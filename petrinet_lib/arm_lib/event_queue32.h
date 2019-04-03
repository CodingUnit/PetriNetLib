#pragma once
#include "include.h"
#include "atomic.h"

namespace events
{

	class event_queue32
	{
		u32 evt;
	public:
		event_queue32() { init(); }

		void init()
		{
			evt = 0;
		}

		bool is_empty() const
		{
			return evt == 0;
		}

		void enqueue(u32 e)
		{
			evt |= e;
		}

		//static u32 get_event(u32 e)
		//{
		//	return e & -e;
		//}

		//static u32 get_left(u32 e, u32 last)
		//{
		//	return e - last;
		//}

		u32 deque()
		{
      //using namespace atomic;
      u32 e = evt;
      u32 lowest = e & -e;
      evt = e - lowest;
			return lowest;
		}
	};

	class event_queue32_conc
	{
		u32 evt;
	public:
		event_queue32_conc() { init(); }

		void init()
		{
			evt = 0;
		}

		bool is_empty() const
		{
			return evt == 0;
		}

		bool have_elem(u32 e) const
		{
			return evt & e;
		}

		void set_elem(u32 clr, u32 set)
		{
			atomic_and_or(&evt, clr, set);
		}

		// добавляем элемент
		void enqueue(u32 e)
		{
			atomic_or(&evt, e); // атомарно
			//evt |= e;
		}

		//static u32 get_event(u32 e)
		//{
		//	return e & -e;
		//}

		//static u32 get_left(u32 e, u32 last)
		//{
		//	return e - last;
		//}
		// получаем элемент но не удаляем из очереди
		u32 peek() const
		{
			u32 e = evt;
			return e & -e;
		}

		// удаление предыдущего взятого элемента с помощью peek
		void remove(u32 e)
		{
			evt -= e;
		}

		void remove_conc(u32 e)
		{
			//evt -= e;
			u32 cevt;
			do 
			{
				cevt = evt;
			} while (!CAS(&evt, cevt, cevt - e));
		}

		bool deque_if_exist(u32 &val)
		{
			if (is_empty())
			{
				return false;
			}
			else
			{
				val = deque_conc();
				return true;
			}

		}

		u32 deque_conc()
		{
			u32 e;
			u32 lowest;
			do 
			{
				e = evt;
				lowest = e & -e;
			//} while (!CAS( &evt, e, e - lowest ));
      } while (!CAS(&evt, e, e - lowest));
			return lowest;
		}

		// вызывается из одного потока
		u32 deque()
		{
			u32 e = peek();
			evt -= e;
			return e;
      //using namespace atomic;
			//u32 e;
			//u32 lowest;
			//do 
			//{
			//	e = evt;
			//	lowest = e & -e;
			//} while (!CAS( &evt, e, e - lowest ));
			//return lowest;
		}
	};
}
