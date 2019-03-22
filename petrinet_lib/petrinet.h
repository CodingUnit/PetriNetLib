#pragma once
#include "event_queue32.h"
#include "time.h"

class petri_net32// : IPetriNet, IDisposable
{
	u32 locked;
	event_queue32_conc queue;
	event_queue32_conc defer_queue;
	u32 completed_tran;
	u16 max_steps;
	//tran_queue: RQueue[Action] = RQueue(32);

	public this(step : int = 15)
	{
		completed_tran = 0;
		time_step = step;
		max_steps = 1;
	}

	//public static @`[T](count : int, tok : T) : IEnumerable[T]
	//{
	//  Enumerable.Repeat(tok, count)
	//}

	//	public static @%++[T](tok1 : IEnumerable[T], tok2 : IEnumerable[T]) : IEnumerable[T]
	//{
	//  tok1.Concat(tok2)
	//}

protected:
	//u32 places;

	typedef void(*tran_func)(void *);

	bool lock(u32 pl, u32 tr)
	{
		u32 lock;
		do
		{
			lock = LL(&locked);
			if (lock & pl)// если элементы заблокированы хотя бы один
			{
				defer_queue.enqueue(tr);
				return false;
			}
		} while (SC(&locked, lock, lock | pl));
		return true;
	}

	void unlock(u32 pl)
	{
		atomic_and(&locked, ~pl);
		check_queue();
	}

	/*void places_ena(bool have_rem, u32 rem_mask, u32 add_mask)
	{
		atomic_and_or(&places, rem_mask, add_mask | have_rem * rem_mask);
	}*/

  

	void tran_ena(u32 trmask, u32 completed)
	{
		queue.enqueue(trmask);//trmask, (places & pl_mask == pl_mask) * trmask);
		atomic_or(&completed_tran, completed);
	}

	void tran_ena(u32 completed)
	{
		//queue.enqueue(trmask);//trmask, (places & pl_mask == pl_mask) * trmask);
		atomic_or(&completed_tran, completed);
	}

	void tran_ena_set(u32 trmask, u32 tr_ena_mask)
	{
		queue.set_elem(trmask, tr_ena_mask);
	}

	virtual tran_func get_transition(int n) const
	{
		return 0;
	}

private:

	void check_queue()
	{
		u32 val;
		/*u32 comp = atomic_and(&completed_tran, ~completed_tran);
		queue.enqueue(comp);*/
		while (defer_queue.deque_if_exist(val))
		{
			tran_func tran = get_transition(val);
			tran(this)
		}
	}
public:

	void step()
	{
		u32 val;
		u16 step = 0;
		u32 comp = atomic_and(&completed_tran, ~completed_tran);
		queue.enqueue(comp);
		for (u16 step = 0; step < max_steps; step++)
		{
			if (queue.deque_if_exist(val))
			{
				tran_func tran = get_transition(val);
				tran(this)
			}
			else break;
		}
	}

	void init(u16 steps)
	{
		max_steps = steps;
	}


};