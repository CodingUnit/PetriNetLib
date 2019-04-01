#pragma once
#include "time.h"

typedef u32(*tval_func)();

class random
{
	u32 next_val;
public:
	random() : next_val(0) {}

	random(u32 seed)
	{
		next_val = seed;
	}

	void init(u32 seed)
	{
		next_val = seed;
	}


	int next(int min, int max) 
	{
		/*
		BOOT32 boot_rand(BOOT32 value){
	static BOOT32 rand_seed=0;
	rand_seed=(rand_seed+value)*1103515245ul+12345ul;
	return rand_seed;
}*/
		u32 value = global_time::time();
		next_val = (next_val + value) * 1103515245ul + 12345ul;
		int count = max - min + 1;
		return (next_val % count) + min;
	}

};