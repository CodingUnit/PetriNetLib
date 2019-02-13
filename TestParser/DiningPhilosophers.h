class DiningPhilosophers : public petri_net
{
	token_iter Chopsticks(PH i)
	{

		return token_iter_utils.concat(token_iter_utils.repeat(cs(i), 1), token_iter_utils.repeat(cs(i == n ? 1 : i + 1), 1));
	}
	const int n = 5;
	multi_set UnusedChopsticks;
	random_array Think;
	random_array Eat;
	typedef cs int;
	typedef CS int;
	typedef ph int;
	typedef PH int;

public:

	void PutDownChopsticks()
	{
		if (lock(PutDownChopsticks))
		{

			if (Eat.have_tokens())
			{
				int p_idx;
				PH p = Eat.peek_indexed(p_idx);
				Eat.get_indexed(p_idx);

				Think.add(p);
				UnusedChopsticks.add(Chopsticks(p));

			}
			;
			unlock();
		}
	}

	void TakeChopsticks()
	{
		if (lock(TakeChopsticks))
		{

			if (Think.have_tokens())
			{
				int p_idx;
				PH p = Think.peek_indexed(p_idx);

				if (UnusedChopsticks.have(Chopsticks(p)))
				{

					UnusedChopsticks.get(Chopsticks(p));
					Think.get_indexed(p_idx);

					Eat.add(p);

				}

			}
			;
			unlock();
		}
	}

	DiningPhilosophers(int time_step = 15)
	{
		Think.add(PH.all());
		UnusedChopsticks.add(CS.all());

	}
};
