#pragma once

typedef u32(*tval_func)();

class random
{
	u32 next;
	tval_func val_func;
public:
	random() : next(0) {}

	random(u32 seed)
	{
		next = seed;
	}

	void init(u32 seed, tval_func val_func)
	{
		next = seed;
		this.val_func = val_func;
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
		u32 value = val_func ? val_func() : 0;
		next = (next + value) * 1103515245ul + 12345ul;
		int count = max - min;
		return (next % count) + min;
	}

};