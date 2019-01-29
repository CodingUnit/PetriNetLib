#pragma once
#include "lib_incl.h"
#include "atomic.h"
#include "memory.h"
#include "queue_base.h"
//#include "time.h"


class rqueue : public queue_base
{
	void *queue;
	u16 count;
	u16 elem_size; // размер элемента

	u16 read_idx; // индекс чтения
	u16 write_idx; // индекс записи
	u16 fifo_locked; // счетчик показывает сколько раз заблокирована очередь
	u16 overflow;
	u16 max_count;

	//	u16 real_elem_size() const // реальный размер в очереди
	//	{
	//		return elem_size + 3 & ~3;
	//	}


	// блокируем очередь, увеличивает атомарно счетчик блокировок
	void lock()
	{
		atomic_inc16(&fifo_locked);
	}

	//// разблокируем очередь, уменьшает атомарно счетчик блокировок, если в цикле возникает прерывание и изменяет переменную цикл начинается заново
	//void unlock()
	//{
	//	u16 locked, idx;
	//	//locked;// = FAA16(&fifo_locked, -1);
	//	LOCK_FAA16ra(fifo_locked, -1, locked);
	//	idx = temp_write_idx; // читаем временный индекс
	//	UNLOCK_FAA16ra(fifo_locked, locked);
	//	if (locked == 0) // если очередь разблокирована полностью
	//	{
	//		// если разблокировали и счетчик равен читаемому
	//		if (write_idx == read_idx) overflow++; // переполнение очереди
	//		write_idx = idx; // сохраняем последний временный счетчик в текущий индекс записи, показывая что очередь заполнена на это количество элементов
	//	}
	//}

	u16 add_idx(u16 idx, u16 val) const
	{
		idx += val;
		if (idx >= count)
		{
			idx -= count;
		}
		return idx;
	}

	// получаем указатель на элемент в очереди по индексу
	u8 *get_pos(u32 idx) const
	{
		//u16 i = idx % count; // получаем индекс в буфере из индекса
		u16 pos = elem_size * idx; // вычисляем позицию в байтах
		u8 *ptr = (u8 *)queue + pos; // вычисляем указатель на элемент
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
		u8 *ptr = get_index(); // получаем указатель на элемент в очереди
		copy(ptr, buf, elem_size); // записываем по индексу данные
		unlock(); // разблокируем очередь
	}

	void *enqueue(void *buf, int len)
	{
		u16 idx = get_index();	// получаем индекс и время в момент получения индекса    
		return get_pos(idx); // получаем указатель на элемент в очереди
	}

	void *add(int len, u64 *time)
	{
		u16 idx = get_index(time, 0);	// получаем индекс и время в момент получения индекса    
		return get_pos(idx); // получаем указатель на элемент в очереди
	}

	// добавление в очередь элемента по известному индексу, полученному ранее и разблокирование очереди на чтение
	void add(void *buf, int len, int idx)
	{
		u8 *ptr = get_pos(idx); // получаем указатель на элемент в очереди
		copy(ptr, buf, elem_size); // записываем по индексу данные
		unlock(); // разблокируем очередь
	}

	// добавление в очередь элемента по известному индексу, полученному ранее и разблокирование очереди на чтение
	void add(void *buf, int len, u64 *time)
	{
		u16 idx = get_index(time, 0);	// получаем индекс и время в момент получения индекса
		u8 *ptr = get_pos(idx); // получаем указатель на элемент в очереди
		copy(ptr, buf, elem_size); // записываем по индексу данные
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

	//	if (!locked) write_idx = idx; // если не заблокирован записываем индекс
	//	u32 *ptr = (u32 *)ret_time;
	//	*ptr++ = time;
	//	*ptr = time >> 32;
	//	return idx;
	//}

	//u16 get_index()
	//{
	//	/*u16 idx;
	//	int locked;
	//	do
	//	{
	//		idx = LL16(&temp_write_idx);
	//		locked = fifo_locked;
	//	} while (!SC16(&temp_write_idx, add_idx(idx, 1)));

	//	if (!locked) write_idx = idx;*/ // если не заблокирован записываем индекс		
	//	return atomic_inc(write_idx);
	//}

	u16 get_lock_index(u64 *ret_time, int)
	{
		lock(); // блокируем очередь на чтение
		return get_index(ret_time, 0);
	}

	// size - 0 : читаем элемент 1, -1 - все элементы, size - размер кратный элементам
	virtual void *get(int &size)
	{
		u16 count = get_count();

		if (count > max_count) // считаем максимальное количество наполнения очереди
			max_count = count;
		u8 *ptr = get_pos(read_idx); // получаем позицию
		if (size == 0) // если 0 читаем элемент
		{
			if (count == 0) return 0;
			size = elem_size;
			read_idx = add_idx(read_idx, 1); // увеличиваем индекс чтения, очередь должна читаться из одного потока
		}
		else
			if (size == -1) // если -1
			{
				size = count * elem_size; // считаем все элементы
				read_idx = add_idx(read_idx, count);
			}
			else
			{
				int need = size / elem_size; // получаем количество элементов
				if (count < need) // если количество в очереди меньше нужного
				{
					size = 0; // размер 0
					return 0; // ничего не выдаем
				}
				// считаем сколько осталось в очереди до конца буфера
				int left = this->count - read_idx;
				if (left < need)// если меньше того что читаем
				{
					need = left; // читаем только до конца
				}
				read_idx = add_idx(read_idx, need);
				size = need * elem_size;
			}

		return ptr;
	}

	void *peek() const
	{
		return get_pos(read_idx);
	}
	// получаем элемент
	void get(void *buf)
	{
		u16 count = get_count();
		if (count > max_count)
			max_count = count;
		u8 *ptr = get_pos(read_idx);
		copy(buf, ptr, elem_size);
		read_idx = add_idx(read_idx, 1); // увеличиваем индекс чтения, очередь должна читаться из одного потока
	}

	// получаем число элементов в очереди
	int get_count() const
	{
		s16 count = write_idx - read_idx;
		if (count < 0) count += this->count;
		return count; // вычитаем индекса чтения
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

	// max_elem_size - больший размер элемента
	void init(int size, int max_elem_size)
	{
		int count = size / max_elem_size;
		this->elem_size = max_elem_size;
		int queue_size = max_elem_size * count;
		queue = new u8[queue_size];
		this->count = count; // размер
		read_idx = 0; // индекс чтения
		write_idx = temp_write_idx = 0; // индекс записи
		fifo_locked = 0; // счетчик показывает сколько раз заблокирована очередь
		max_count = 0;
		overflow = 0;
	}

};

