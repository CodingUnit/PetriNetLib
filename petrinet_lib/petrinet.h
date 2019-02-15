#pragma once
#include "event_queue32.h"

class petri_net32// : IPetriNet, IDisposable
{
	u8 locked;
	event_queue32_conc queue;
	//tran_queue: RQueue[Action] = RQueue(32);

	public this(step : int = 15)
	{
		time_step = step;
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

	bool lock(int evt)
	{
		if (!CAS8(&locked, 0, 1))
		{
			queue.enqueue(evt);
			return false;
		}
		return true;
	}

	void unlock() 
	{
		locked = 0;
		check_queue();
	}

	virtual function get_transition(int n)
	{
		return function();
	}

private:
	check_queue() : void
	{
		u32 val;
		while (queue.deque_if_exist(val))
		{
			function tran = get_transition(n);
			tran.exec();
		}
	}

public:

	virtual void step() 
	{
	}

};