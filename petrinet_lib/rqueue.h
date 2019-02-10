#pragma once
#include "lib_incl.h"
#include "atomic.h"
#include "memory.h"
#include "queue_base.h"
//#include "time.h"


class rqueue
{
	void *queue;
	u16 count;
	u16 elem_size; // ������ ��������

	u16 read_idx; // ������ ������
	u16 write_idx; // ������ ������
	u16 overflow;
	u16 max_count;

	//	u16 real_elem_size() const // �������� ������ � �������
	//	{
	//		return elem_size + 3 & ~3;
	//	}



	//// ������������ �������, ��������� �������� ������� ����������, ���� � ����� ��������� ���������� � �������� ���������� ���� ���������� ������
	//void unlock()
	//{
	//	u16 locked, idx;
	//	//locked;// = FAA16(&fifo_locked, -1);
	//	LOCK_FAA16ra(fifo_locked, -1, locked);
	//	idx = temp_write_idx; // ������ ��������� ������
	//	UNLOCK_FAA16ra(fifo_locked, locked);
	//	if (locked == 0) // ���� ������� �������������� ���������
	//	{
	//		// ���� �������������� � ������� ����� ���������
	//		if (write_idx == read_idx) overflow++; // ������������ �������
	//		write_idx = idx; // ��������� ��������� ��������� ������� � ������� ������ ������, ��������� ��� ������� ��������� �� ��� ���������� ���������
	//	}
	//}
  u16 get_index()
  {
    /*u16 idx;
    int locked;
    do
    {
    idx = LL16(&temp_write_idx);
    locked = fifo_locked;
    } while (!SC16(&temp_write_idx, add_idx(idx, 1)));

    if (!locked) write_idx = idx;*/ // ���� �� ������������ ���������� ������		
    return atomic_inc(write_idx);
  }

	// �������� ��������� �� ������� � ������� �� �������
	u8 *get_pos(u32 idx) const
	{
		//u16 i = idx % count; // �������� ������ � ������ �� �������
		u16 pos = elem_size * idx; // ��������� ������� � ������
		u8 *ptr = (u8 *)queue + pos; // ��������� ��������� �� �������
		return ptr;
	}
public:
	rqueue() {}
	rqueue(int size, int elem_size)
	{
		init(size, elem_size);
	}

	void enqueue(void *buf, int len)
	{
		u8 *ptr = get_index(); // �������� ��������� �� ������� � �������
		copy(ptr, buf, elem_size); // ���������� �� ������� ������
		unlock(); // ������������ �������
	}

	void *enqueue(int len)
	{
		u16 idx = get_index();	// �������� ������ � ����� � ������ ��������� �������    
		return get_pos(idx); // �������� ��������� �� ������� � �������
	}

	//u16 get_index(u64 *ret_time, int)
	//{
	//	u64 time;
	//	u16 idx;
	//	int locked;
	//	do
	//	{
	//		idx = LL16(&temp_write_idx);
	//		time = global_time::time();
	//		locked = fifo_locked;
	//	} while (!SC16(&temp_write_idx, add_idx(idx, 1)));

	//	if (!locked) write_idx = idx; // ���� �� ������������ ���������� ������
	//	u32 *ptr = (u32 *)ret_time;
	//	*ptr++ = time;
	//	*ptr = time >> 32;
	//	return idx;
	//}

	

	// size - 0 : ������ ������� 1, -1 - ��� ��������, size - ������ ������� ���������
	virtual void *deque()
	{
		u16 count = get_count();

		if (count > max_count) // ������� ������������ ���������� ���������� �������
			max_count = count;
		u8 *ptr = get_pos(read_idx); // �������� �������
		if (count == 0) return 0;
		size = elem_size;
		read_idx++;// = add_idx(read_idx, 1); // ����������� ������ ������, ������� ������ �������� �� ������ ������
		return ptr;
	}

	void *peek() const
	{
		return get_pos(read_idx);
	}

	// �������� �������
	void deque(void *buf)
	{
		u16 count = get_count();
		if (count > max_count)
			max_count = count;
		u8 *ptr = get_pos(read_idx);
		copy(buf, ptr, elem_size);
		read_idx++;// = add_idx(read_idx, 1); // ����������� ������ ������, ������� ������ �������� �� ������ ������
	}

  int next_free_index() const
  {
    return write_index % count;
  }

  void *remove_abs(int index) const
  {
    void *data = deque();
    int idx = read_idx;
    if (index == idx % count)
    {
      return data;
    }
    else
    {
      u8 *ptr = get_pos(index);
      copy(ptr, data, elem_size);
      return ptr;
    }
  }

  void *remove(int index)
  {
    return remove_abs((index + read_idx) % count);
  }

  void *element_at(int index)
  {
    int idx = (read_idx + index) % count;
    return get_pos(idx);
  }

  void clear()
  {
    read_idx = write_idx = 0;
  }

  bool empty() const
  {
    return get_count() == 0;
  }
	// �������� ����� ��������� � �������
	int get_count() const
	{
		s16 count = write_idx - read_idx;
		if (count < 0) count += this->count;
		return count; // �������� ������� ������
	}

	int get_size() const
	{
		return get_count() * elem_size;
	}

	u16 get_max_count() const
	{
		return max_count;
	}

	u16 get_overflow() const
	{
		return overflow;
	}

	// max_elem_size - ������� ������ ��������
	void init(int size, int max_elem_size)
	{
		int count = size / max_elem_size;
		this->elem_size = max_elem_size;
		int queue_size = max_elem_size * count;
		queue = new u8[queue_size];
		this->count = count; // ������
		read_idx = 0; // ������ ������
		write_idx = 0; // ������ ������
		max_count = 0;
		overflow = 0;
	}

};

