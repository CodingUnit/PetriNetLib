#include "petrinet.h"

namespace petrinet_lib
{

	class timed_petri_net32 : public petri_net32
	{
		event_queue32_conc time_queue;
		u32 min_time;
	protected:
		u32 calc_min_time(u32 time, u32 min, u32 ctr, u32 &tr)
		{
			if (time < min)
			{
				min = time;
				tr = ctr;
			}
			else
				if (min == time)
				{
					tr |= ctr;
				}
		}

		bool check_time() const
		{
			return time() >= min_time;
		}

		u32 time() const
		{
			return global_time::time();
		}

		u64 time64() const
		{
			return global_time::time();
		}

		virtual u32 get_next_time(u32 &tr)
		{
			return 0xFFFFFFFF;
		}

		void time_tran_ena(u32 min_time, u32 trmask)
		{
			this->min_time = min_time;
			time_queue.enqueue(trmask);
		}

		bool time_waiting() const
		{
			return !time_queue.is_empty();
		}

		void check_time_queue()
		{
			u32 val;
			/*u32 comp = atomic_and(&completed_tran, ~completed_tran);
			queue.enqueue(comp);*/
			while (time_queue.deque_if_exist(val))
			{
				//tran_func tran = get_transition(val);
        transition(val);
				//tran(this);
			}
		}
	public:
    timed_petri_net32(int step) : petri_net32(step)
    {
      
    }
    
		void time_step()
		{
			if (time_waiting())
			{
				if (check_time())
				{
					check_time_queue();
					u32 tr;
					u32 min = get_next_time(tr);
					time_tran_ena(min, tr);
				}
			}
			else
			{
				u32 tr;
				u32 min = get_next_time(tr);
				time_tran_ena(min, tr);
			}
		}


	};

}
