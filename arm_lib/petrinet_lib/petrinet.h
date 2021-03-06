#pragma once
#include "event_queue32.h"
#include "time.h"
#include "tuple.h"
#include "buffer_utils.h"
#include "token_queue.h"
#include "bits.h"

using namespace events;
namespace petrinet_lib
{


	class petri_net32// : IPetriNet, IDisposable
	{
		u32 locked;
		event_queue32_conc queue;
		event_queue32_conc defer_queue;
		u32 completed_tran;
		u16 max_steps;
		//tran_queue: RQueue[Action] = RQueue(32);


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

		typedef bool(*tran_func)(void *);

		bytes4 IntToList(u32 val, int count = 4)
		{
			bytes4 ret = bytes4((u8 *)&val);
			ret.set_count(count);
			return ret;
		}

		bool lock(u32 pl, u32 tr)
		{
			u32 lock;
			do
			{
				lock = LL(&locked);
				if (lock & pl)// ���� �������� ������������� ���� �� ����
				{
					defer_queue.enqueue(tr);
					return false;
				}
			} while (!SC(&locked, lock | pl));
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
      trmask &= ~1;
			queue.enqueue(trmask);//trmask, (places & pl_mask == pl_mask) * trmask);
			atomic_or(&completed_tran, completed);
		}

		void tran_ena(u32 completed)
		{
			//queue.enqueue(trmask);//trmask, (places & pl_mask == pl_mask) * trmask);
			atomic_or(&completed_tran, completed);
		}

		//	void tran_ena_set(u32 trmask, u32 tr_ena_mask)
		//	{
		//		queue.set_elem(trmask, tr_ena_mask);
		//	}

		virtual tran_func get_transition(int n) const
		{
			return 0;
		}

		void run_transitions(u32 tr)
		{
			while (tr)
			{
				u32 cur = tr & -tr; // ����� ������ ���
				transition(cur);
				tr -= cur;
			}
		}

		virtual void transition(u32 tr)
		{
		}

	private:

		

		void check_queue()
		{
			u32 val;
			/*u32 comp = atomic_and(&completed_tran, ~completed_tran);
			queue.enqueue(comp);*/
			while (defer_queue.deque_if_exist(val))
			{
				transition(val);
			}
		}
	public:


		petri_net32(int step = 15)
		{
			completed_tran = locked = 0;
			max_steps = step;
		}

		void step()
		{
			u32 val;
			u32 comp = atomic_and(&completed_tran, ~completed_tran);
			queue.enqueue(comp);
			for (u16 step = 0; step < max_steps; step++)
			{
				if (queue.deque_if_exist(val))
				{
					transition(val);
				}
				else break;
			}
		}

		void init(u16 steps)
		{
			max_steps = steps;
		}


	};
}
