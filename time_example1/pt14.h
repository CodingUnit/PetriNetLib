class pt14 : public timed_petri_net
{
	typedef enum
	{
		pl_CAN_OUT = 1,
		pl_COUNTER = 2,
		pl_UDP_OUT = 4,
		pl_DEBUG_TIMER = 8,
		pl_ADC_SUM = 16,
		pl_TIMER = 32,
		pl_ADC = 64,
		pl_SEND_SENS = 128,
		pl_TempTimer = 256,
		pl_BinTimer = 512,
		pl_DELAY = 1024,
		pl_UDP_IN = 2048,
		pl_BUTTONS = 4096,
		pl_SSI = 8192,
		pl_SYNC = 16384,
		pl_DPS = 32768
	} tplace;
	typedef char UNIT;

	typedef bool BOOL;

	typedef int INT;

	typedef intinf INTINF;

	typedef time TIME;

	typedef short SHORT;

	typedef real REAL;

	typedef u8 BYTE;

	typedef UNIT UNIT_TIMED;

	typedef INT UINT;

	typedef UNIT SINGLE__UNIT;

	struct TSYNC
	{
		TSYNC(int field1, bool field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		int field1;
		bool field2;
	};

	typedef INT SINGLE__INT;

	typedef INTINF LONGTIME;

	struct SINGLE__INTxINT
	{
		SINGLE__INTxINT(int field1, int field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		int field1;
		int field2;
	};

	typedef INT QUEUE__INT;

	typedef INT ZEROSINGLE__TIMED_INT;

	typedef BYTE SINGLE__BYTE;

	typedef INT USHORT;



	struct STRING
	{
		STRING(int field1, const bytes &field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		int field1;
		bytesn field2;
	};

	typedef INT REQ__INT;



	typedef INT VAR_PUSH__BYTE;

	typedef BYTES SINGLE__BYTES;

	typedef INT VAR__UINT;

	struct CAN_MESSAGE
	{
		CAN_MESSAGE(int field1, long long field2, const bytes &field3)
		{
			this->field1 = field1;
			this->field2 = field2;
			this->field3 = field3;
		}

		int field1;
		long long field2;
		bytes8 field3;
	};

	typedef BOOL VAR_PUSH__BOOL;

	typedef UNIT SINGLE__TIMED_VOID;

	struct CAN_UDP_MESSAGE
	{
		CAN_UDP_MESSAGE(int COUNT, int ID, long long timestamp, const bytes &data)
		{
			this->COUNT = COUNT;
			this->ID = ID;
			this->timestamp = timestamp;
			this->data = data;
		}
		int COUNT;
		int ID;
		long long timestamp;
		bytesn data;
	};



	typedef INT MINUS_SINGLE_INT;

	typedef INT VAR__INT;



	typedef STRING DEBUG_INFO;

	struct CAN_RESULT
	{
		CAN_RESULT(const CAN_MESSAGE &field1, bool field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		CAN_MESSAGE field1;
		bool field2;
	};

	int get_next_time()
	{

		int min = 0xFFFFFFFF;
		min = math_utils::min(min, [VAR]DELAY.NextTokenDelay);
		min = math_utils::min(min, [VAR]BinTimer.NextTokenDelay);
		min = math_utils::min(min, SyncFreq.NextTokenDelay);
		min = math_utils::min(min, [VAR]TempTimer.NextTokenDelay);
		min = math_utils::min(min, [VAR]TIMER.NextTokenDelay);
		min = math_utils::min(min, [VAR]DEBUG_TIMER.NextTokenDelay); ;
		return min;
		;
	}
	void time_step()
	{
		UnnamedTransition0(), UnnamedTransition1(), UnnamedTransition2(), UnnamedTransition3(), UnnamedTransition4(), UnnamedTransition5();
	}
	CAN_RESULT CAN_OUT;
	bool CAN_OUT_flag = false;
	u16 COUNTER;
	random_array UDP_OUT;
	timed_heap DEBUG_TIMER;
	INTxINT ADC_SUM;
	bool ADC_SUM_flag = false;
	timed_heap TIMER;
	req_tokens ADC;
	char SEND_SENS;
	timed_heap TempTimer;
	timed_heap BinTimer;
	timed_heap DELAY;
	CAN_UDP_MESSAGE UDP_IN;
	bool UDP_IN_flag = false;
	u8 BUTTONS;
	req_tokens SSI;
	u32 SYNC;
	bool DPS;
	static const int P_LOW = 10000;
	static const int P_NORMAL = 1000;
	static const int P_HIGH = 100;
	CAN_UDP_MESSAGE  can2udp(const CAN_MESSAGE &m, int c)
	{
		return CAN_UDP_MESSAGE(c, m.field1, m.field2, m.field3);
	}

	CAN_MESSAGE  udp2can(const CAN_UDP_MESSAGE &m)
	{
		return CAN_MESSAGE(m.ID, m.timestamp, m.data);
	}

	CAN_MESSAGE  bt2can_message(int bt)
	{
		u8 _N__4527[] = { (BYTE)1, bt };
		return CAN_MESSAGE(721, IntInf.fromInt(0), byte2(_N__4527));
	}

	bool is_sens(const CAN_UDP_MESSAGE &m)
	{
		return m.ID == 663;
	}

	bool is_control(const CAN_UDP_MESSAGE &m)
	{
		return m.ID == 80;
	}


public:

	void step()
	{
		UnnamedTransition6()
			UnnamedTransition7()
			UnnamedTransition8()
			UnnamedTransition9()
			UnnamedTransition10()
			UnnamedTransition11()
			UnnamedTransition12()
			UnnamedTransition13()
			UnnamedTransition14()
			UnnamedTransition15()
			UnnamedTransition16()
			UnnamedTransition17()
			UnnamedTransition18()
	}
	pt14(int time_step = 15)
	{
		timed_petri_net(time_step);
		DPS.add(false);
		SYNC.add(0);
		SSI.add(byte0(_N__4513));
		TEMP.add(0);
		BUTTONS.add(0);
		UDP_IN.add();
		CAN.add();
		UDP_SEND.add();
		CAN_IN.add();
		GPS.add();
		SEND_DEBUG.add();
		SYNC_BUF.add();
		DELAY.add(add_time('u', 0););
		BinTimer.add(add_time(at_time('u', 1000000), 0););
		SyncFreq.add(add_time(, 0););
		TempTimer.add(add_time(at_time('u', 500000), 0););
		SEND_SENS.add();
		BatLevel.add();
		ADC.add();
		TIMER.add(add_time(at_time('u', 0), 0););
		ADC_SUM.add(tuple2(0, 0));
		DEBUG_TIMER.add(add_time(at_time('u', 0), 0););
		UDP_OUT.add();
		COUNTER.add(0);
		UDP_AND_CAN_SEND.add();
		CAN_OUT.add();

	}
	void UnnamedTransition6()
	{
		if (lock(pl_GPS))
		{

			if (SEND_SENS.have_tokens())
			{
				int s_idx;
				STRING s = SEND_SENS.peek_indexed(s_idx);
				SEND_SENS.get_indexed(s_idx);

				UDP_SEND.add(tuple3(256, get_time(), s.field2));
				OnUnnamedTransition6()
			}
			;
			unlock(pl_GPS);
		}
	}

	void UnnamedTransition7()
	{
		if (lock(pl_UDP_IN))
		{

			if (ADC_SUM.have_tokens())
			{
				int m_idx;
				CAN_UDP_MESSAGE m = ADC_SUM.peek_indexed(m_idx);
				if (is_control(m))
				{
					ADC_SUM.get_indexed(m_idx);

					UDP_SEND.add(get_control_msg(m));
				}
				OnUnnamedTransition7()
			}
			;
			unlock(pl_UDP_IN);
		}
	}

	void UnnamedTransition8()
	{
		if (lock(pl_UDP_IN))
		{

			if (ADC_SUM.have_tokens())
			{
				int m_idx;
				CAN_UDP_MESSAGE m = ADC_SUM.peek_indexed(m_idx);
				ADC_SUM.get_indexed(m_idx);

				CAN.add(udp2can(m));
				OnUnnamedTransition8()
			}
			;
			unlock(pl_UDP_IN);
		}
	}

	void UnnamedTransition9()
	{
		if (lock(pl_CAN_IN))
		{

			if (BatLevel.have_tokens())
			{
				int cm_idx;
				CAN_MESSAGE cm = BatLevel.peek_indexed(cm_idx);
				BatLevel.get_indexed(cm_idx);
				can_process(cm)
					UDP_SEND.add(cm);
				OnUnnamedTransition9()
			}
			;
			unlock(pl_CAN_IN);
		}
	}

	void DPS()
	{
		if (lock(pl_DELAY | pl_SSI | pl_SYNC | pl_DPS))
		{

			; ;

			if (COUNTER.have_tokens())
			{
				int ssi_idx;
				bytesn ssi = COUNTER.peek_indexed(ssi_idx);

				if (UDP_AND_CAN_SEND.have_tokens())
				{
					int n_idx;
					int n = UDP_AND_CAN_SEND.peek_indexed(n_idx);

					if (CAN_OUT.have_tokens())
					{
						int dir_idx;
						bool dir = CAN_OUT.peek_indexed(dir_idx);
						CAN_OUT.get_indexed(dir_idx);
						UDP_AND_CAN_SEND.get_indexed(n_idx);
						COUNTER.get_indexed(ssi_idx);
						BinTimer.get_all()

							SYNC.add(n + 1);
						UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n, dir, 1, ssi)));
						SYNC_BUF.add(unit.instance());
						OnDPS()
					}

				}

			}

			;
			unlock(pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
		}
	}

	void UnnamedTransition0()
	{
		if (lock(pl_DEBUG_TIMER | pl_SEND_DEBUG))
		{

			if (BUTTONS.have_tokens())
			{


				if (TempTimer.have_tokens())
				{
					int d_idx;
					char TempTimer_tok = TempTimer.peek_indexed(d);; DEBUG_INFO d = TempTimer_tok;;
					TempTimer.get_indexed(d_idx);
					BUTTONS.get();

					UDP_SEND.add(tuple3(0, get_time(), d.field2));
					DEBUG_TIMER.add(add_time(unit.instance(), 333000));
					OnUnnamedTransition0()
				}

			}
			;
			unlock(pl_DEBUG_TIMER | pl_SEND_DEBUG);
		}
	}

	void UnnamedTransition10()
	{
		if (lock(pl_SYNC_BUF))
		{

			if (SyncFreq.have_tokens())
			{
				; ;
				SyncFreq.get();

				DELAY.add(add_time(unit.instance(), 0));
				OnUnnamedTransition10()
			}
			;
			unlock(pl_SYNC_BUF);
		}
	}

	void UnnamedTransition11()
	{
		if (lock(pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS))
		{

			if (GPS.have_tokens())
			{


				if (COUNTER.have_tokens())
				{
					int ssi_idx;
					bytesn ssi = COUNTER.peek_indexed(ssi_idx);

					if (UDP_AND_CAN_SEND.have_tokens())
					{
						int n_idx;
						int n = UDP_AND_CAN_SEND.peek_indexed(n_idx);

						if (CAN_OUT.have_tokens())
						{
							int dir_idx;
							bool dir = CAN_OUT.peek_indexed(dir_idx);
							CAN_OUT.get_indexed(dir_idx);
							UDP_AND_CAN_SEND.get_indexed(n_idx);
							COUNTER.get_indexed(ssi_idx);
							GPS.get();

							UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n, dir, 0, ssi)));
							OnUnnamedTransition11()
						}

					}

				}

			}
			;
			unlock(pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS);
		}
	}

	void UnnamedTransition1()
	{
		if (lock(pl_BatLevel | pl_BinTimer | pl_BUTTONS))
		{

			if (CAN_IN.have(IEnumerable[(bt, n)]))
			{


				if (DELAY.have_tokens())
				{
					; ;

					if (DEBUG_TIMER.have_tokens())
					{
						int inp_idx;
						char DEBUG_TIMER_tok = DEBUG_TIMER.peek_indexed(inp);; int inp = DEBUG_TIMER_tok;;
						DEBUG_TIMER.get_indexed(inp_idx);
						DELAY.get();
						CAN_IN.get((bt, n));

						BinTimer.add(add_time(unit.instance(), 1000000));
						UDP_AND_CAN_SEND.add(tuple3(336, get_time(), (_N__4525)));
						UDP_AND_CAN_SEND.add(tuple3(721, get_time(), (_N__4526)));
						OnUnnamedTransition1()
					}

				}

			}
			;
			unlock(pl_BatLevel | pl_BinTimer | pl_BUTTONS);
		}
	}

	void UnnamedTransition2()
	{
		if (lock(pl_SyncFreq))
		{

			if (SYNC_BUF.have_tokens())
			{
				int freq_idx;
				int freq = SYNC_BUF.peek_indexed(freq_idx);
				SYNC_BUF.get_indexed(freq_idx);

				SYNC.add(0);
				SyncFreq.add(add_time(freq(Delay(/ (1000000, freq))), 0));
				OnUnnamedTransition2()
			}
			;
			unlock(pl_SyncFreq);
		}
	}

	void UnnamedTransition3()
	{
		if (lock(pl_TempTimer | pl_TEMP))
		{

			if (SEND_DEBUG.have_relative_time(unit.instance(), 500000))
			{


				if (UDP_OUT.have_tokens())
				{
					int n_idx;
					int n = UDP_OUT.peek_indexed(n_idx);
					UDP_OUT.get_indexed(n_idx);
					SEND_DEBUG.get_relative_time(unit.instance(), 500000);

					TempTimer.add(add_time(unit.instance(), 0));
					UDP_AND_CAN_SEND.add(tuple3(721, get_time(), list.Cons(51, IntToList(n))));
					OnUnnamedTransition3()
				}

			}
			;
			unlock(pl_TempTimer | pl_TEMP);
		}
	}

	void UnnamedTransition12()
	{
		if (lock(pl_UDP_IN))
		{

			if (ADC_SUM.have_tokens())
			{
				int m_idx;
				CAN_UDP_MESSAGE m = ADC_SUM.peek_indexed(m_idx);
				if (is_sens(m))
				{
					ADC_SUM.get_indexed(m_idx);

					SEND_SENS.add(unit.instance());
				}
				OnUnnamedTransition12()
			}
			;
			unlock(pl_UDP_IN);
		}
	}

	void UnnamedTransition4()
	{
		if (lock(pl_DELAY))
		{

			if (BinTimer.have_relative_time(unit.instance(), 200000))
			{
				; ;
				BinTimer.get_relative_time(unit.instance(), 200000);

				DELAY.add(add_time(unit.instance(), 0));
				SEND_SENS.add(unit.instance());
				OnUnnamedTransition4()
			}
			;
			unlock(pl_DELAY);
		}
	}

	void BUTTONS()
	{
		if (lock(pl_BUTTONS))
		{

			if (DEBUG_TIMER.have_tokens())
			{
				int bt_idx;
				char DEBUG_TIMER_tok = DEBUG_TIMER.peek_indexed(bt);; u8 bt = DEBUG_TIMER_tok;;
				DEBUG_TIMER.get_indexed(bt_idx);

				UDP_AND_CAN_SEND.add(bt2can_message(bt));
				OnBUTTONS()
			}
			;
			unlock(pl_BUTTONS);
		}
	}

	void UnnamedTransition5()
	{
		if (lock(pl_ADC_SUM | pl_TIMER | pl_ADC))
		{

			if (UDP_IN.have(IEnumerable[(sum, n)]))
			{


				if (CAN.have_tokens())
				{


					if (UDP_SEND.have_tokens())
					{
						int q_idx;
						int q = UDP_SEND.peek_indexed(q_idx);
						if (< (n, 10))
						{
							UDP_SEND.get_indexed(q_idx);
							CAN.get();
							UDP_IN.get((sum, n));

							TIMER.add(add_time(unit.instance(), 50000));
							ADC_SUM.add(tuple2(sum + q, n + 1));
						}
						OnUnnamedTransition5()
					}

				}

			}
			;
			unlock(pl_ADC_SUM | pl_TIMER | pl_ADC);
		}
	}

	void UnnamedTransition13()
	{
		if (lock(pl_ADC_SUM))
		{

			if (UDP_IN.have(IEnumerable[(sum, n)]))
			{

				if (>= (n, 10))
				{
					UDP_IN.get((sum, n));

					BatLevel.add(adc2bat(sum(div(n))));
					ADC_SUM.add(tuple2(0, 0));
				}
				OnUnnamedTransition13()
			}
			;
			unlock(pl_ADC_SUM);
		}
	}

	void UnnamedTransition14()
	{
		if (lock(pl_COUNTER | pl_UDP_SEND))
		{

			if (SSI.have_tokens())
			{
				int n_idx;
				int n = SSI.peek_indexed(n_idx);

				if (ADC.have_tokens())
				{
					int cm_idx;
					CAN_MESSAGE cm = ADC.peek_indexed(cm_idx);
					ADC.get_indexed(cm_idx);
					SSI.get_indexed(n_idx);

					UDP_OUT.add(can2udp(cm, n));
					COUNTER.add(n + 1);
					OnUnnamedTransition14()
				}

			}
			;
			unlock(pl_COUNTER | pl_UDP_SEND);
		}
	}

	void UnnamedTransition15()
	{
		if (lock(pl_UDP_AND_CAN_SEND))
		{

			if (SYNC.have_tokens())
			{
				int cm_idx;
				CAN_MESSAGE cm = SYNC.peek_indexed(cm_idx);
				SYNC.get_indexed(cm_idx);

				CAN.add(cm);
				UDP_SEND.add(cm);
				OnUnnamedTransition15()
			}
			;
			unlock(pl_UDP_AND_CAN_SEND);
		}
	}

	void UnnamedTransition16()
	{
		if (lock(pl_CAN))
		{

			if (TIMER.have_tokens())
			{
				int cm_idx;
				char TIMER_tok = TIMER.peek_indexed(cm);; CAN_MESSAGE cm = TIMER_tok;;
				TIMER.get_indexed(cm_idx);

				CAN_OUT.add(tuple2(cm, can_send(cm)));
				OnUnnamedTransition16()
			}
			;
			unlock(pl_CAN);
		}
	}

	void UnnamedTransition17()
	{
		if (lock(pl_CAN_OUT))
		{

			if (DPS.have(IEnumerable[(cm, res)]))
			{

				if (not(res))
				{
					DPS.get((cm, res));

					CAN.add(cm);
				}
				OnUnnamedTransition17()
			}
			;
			unlock(pl_CAN_OUT);
		}
	}

	void UnnamedTransition18()
	{
		if (lock(pl_CAN_OUT))
		{

			if (DPS.have(IEnumerable[(cm, res)]))
			{

				if (res)
				{
					DPS.get((cm, res));

				}
				OnUnnamedTransition18()
			}
			;
			unlock(pl_CAN_OUT);
		}
	}

	function adc2bat;
	function get_ssi_bytes;
	function get_control_msg;
	function can_process;
};
