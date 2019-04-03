#pragma once
#include "rqueue.h"
#include "math_utils.h"
#include "token_iter_utils.h"
//using namespace math_utils;

namespace petrinet_lib
{
	class random_array
	{
		rqueue queue;
		random ran;
	public:

		void init(int size, int max_elem_size)
		{
			queue.init(size, max_elem_size);
		}

		void init()
		{

		}

		void add(void *tok)
		{
			queue.enqueue(tok);
		}

		//void addmany()
		void addmany(token_iter &iter)
		{
			while (iter.move_next())
			{
				void *elem = iter.current();
				add(elem);
			}
		}

		bool have(void *tok) const
		{
			return queue.contains(tok);
		}

		bool have(token_iter &iter) const
		{
			while (iter.move_next())
			{
				if (!queue.contains(iter.current())) return false;
			}
			return true;
		}

		bool have_tokens() const
		{
			return !queue.empty();
		}

		void get_all()
		{
			queue.clear();
		}

		void *peek()
		{
			int idx = ran.next(0, queue.get_count());
			return queue.element_at(idx);
		}

		void get(void *elem)
		{
			int idx = queue.index_of(elem);
			queue.remove_abs(idx);
		}

		void *get()
		{
			int idx = ran.next(0, queue.get_count());
			return queue.remove(idx);
		}

		void *peek_indexed(int &idx)
		{
			int i = ran.next(0, queue.get_count());
			idx = queue.real_index(i);
			return queue.element_at_abs(idx);
		}

		void get_indexed(int idx)
		{
			queue.remove_abs(idx);
		}
	};

}
