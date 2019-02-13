#pragma once
#include "time.h"

typedef u32(*tval_func)();

class random
{
	u32 next;
public:
	random() : next(0) {}

	random(u32 seed)
	{
		next = seed;
	}

	void init(u32 seed)
	{
		next = seed;
	}

	int next(int min, int max)
	{
		/*
		BOOT32 boot_rand(BOOT32 value){
	static BOOT32 rand_seed=0;
	rand_seed=(rand_seed+value)*1103515245ul+12345ul;
	return rand_seed;
}*/
		return next(0, min, max);
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
		next = (next + value) * 1103515245ul + 12345ul;
		int count = max - min + 1;
		return (next % count) + min;
	}

};