class pt14 : public timed_petri_net
{
	typedef enum
	{
		pl_DPS = 0x1,
		pl_SYNC = 0x2,
		pl_SSI = 0x4,
		pl_BUTTONS = 0x8,
		pl_UDP_IN = 0x10,
		pl_DELAY = 0x20,
		pl_BinTimer = 0x40,
		pl_TempTimer = 0x80,
		pl_SEND_SENS = 0x100,
		pl_ADC = 0x200,
		pl_TIMER = 0x400,
		pl_ADC_SUM = 0x800,
		pl_DEBUG_TIMER = 0x1000,
		pl_UDP_OUT = 0x2000,
		pl_COUNTER = 0x4000,
		pl_CAN_OUT = 0x8000
	} tplace;
	typedef char UNIT;

	typedef bool BOOL;

	typedef int INT;

	typedef long long INTINF;

	typedef int TIME;

	typedef short SHORT;



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
	bool DPS;
	u32 SYNC;
	req_tokens SSI;
	u8 BUTTONS;
	CAN_UDP_MESSAGE UDP_IN;
	bool UDP_IN_flag = false;
	timed_heap DELAY;
	timed_heap BinTimer;
	timed_heap TempTimer;
	char SEND_SENS;
	req_tokens ADC;
	timed_heap TIMER;
	INTxINT ADC_SUM;
	bool ADC_SUM_flag = false;
	timed_heap DEBUG_TIMER;
	random_array UDP_OUT;
	u16 COUNTER;
	CAN_RESULT CAN_OUT;
	bool CAN_OUT_flag = false;
	tranfunc tran_funcs[] = { UnnamedTransition6,
	UnnamedTransition7,
	UnnamedTransition8,
	UnnamedTransition9,
	DPS,
	UnnamedTransition0,
	UnnamedTransition10,
	UnnamedTransition11,
	UnnamedTransition1,
	UnnamedTransition2,
	UnnamedTransition3,
	UnnamedTransition12,
	UnnamedTransition4,
	BUTTONS,
	UnnamedTransition5,
	UnnamedTransition13,
	UnnamedTransition14,
	UnnamedTransition15,
	UnnamedTransition16,
	UnnamedTransition17,
	UnnamedTransition18
	};
	typedef enum
	{
		tr_UnnamedTransition6 = 0x1,
		tr_UnnamedTransition7 = 0x2,
		tr_UnnamedTransition8 = 0x4,
		tr_UnnamedTransition9 = 0x8,
		tr_DPS = 0x10,
		tr_UnnamedTransition0 = 0x20,
		tr_UnnamedTransition10 = 0x40,
		tr_UnnamedTransition11 = 0x80,
		tr_UnnamedTransition1 = 0x100,
		tr_UnnamedTransition2 = 0x200,
		tr_UnnamedTransition3 = 0x400,
		tr_UnnamedTransition12 = 0x800,
		tr_UnnamedTransition4 = 0x1000,
		tr_BUTTONS = 0x2000,
		tr_UnnamedTransition5 = 0x4000,
		tr_UnnamedTransition13 = 0x8000,
		tr_UnnamedTransition14 = 0x10000,
		tr_UnnamedTransition15 = 0x20000,
		tr_UnnamedTransition16 = 0x40000,
		tr_UnnamedTransition17 = 0x80000,
		tr_UnnamedTransition18 = 0x100000
	} ttran;
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


protected:

	tran_func get_transition(int n) const
	{
		return tran_funcs[n];
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

			if (GPS.have_tokens())
			{
				int s_idx;
				STRING s = GPS.peek_indexed(s_idx);
				GPS.get_indexed(s_idx);

				UDP_SEND.add(tuple3(256, get_time(), s.field2));
				tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition6);
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

			if (UDP_IN_flag)
			{
				int m_idx;
				CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
				if (is_control(m))
				{
					UDP_IN_flag = false;

					UDP_SEND.add(get_control_msg(m));
					tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition7);
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

			if (UDP_IN_flag)
			{
				int m_idx;
				CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
				UDP_IN_flag = false;

				CAN.add(udp2can(m));
				tran_ena(tr_UnnamedTransition16 | tr_UnnamedTransition8);
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

			if (CAN_IN_flag)
			{
				int cm_idx;
				CAN_MESSAGE cm = CAN_IN.peek_indexed(cm_idx);
				CAN_IN_flag = false;
				can_process(cm)
					UDP_SEND.add(cm);
				tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition9);
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

			int ssi_idx;
			bytesn ssi = SSI.peek_indexed(ssi_idx);

			int n_idx;
			int n = SYNC.peek_indexed(n_idx);

			int dir_idx;
			bool dir = DPS.peek_indexed(dir_idx);



			DELAY.get_all()

				SYNC.add(n + 1);
			UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n, dir, 1, ssi)));
			SYNC_BUF.add(unit.instance());
			tran_ena(tr_UnnamedTransition10 | tr_UnnamedTransition14 | tr_UnnamedTransition11);
			OnDPS()



				;
			unlock(pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
		}
	}

	void UnnamedTransition0()
	{
		if (lock(pl_DEBUG_TIMER | pl_SEND_DEBUG))
		{

			if (DEBUG_TIMER.have_tokens())
			{
				; ;

				if (SEND_DEBUG.have_tokens())
				{
					int d_idx;
					DEBUG_INFO d = SEND_DEBUG.peek_indexed(d_idx);
					SEND_DEBUG.get_indexed(d_idx);
					DEBUG_TIMER.get();

					UDP_SEND.add(tuple3(0, get_time(), d.field2));
					DEBUG_TIMER.add(add_time(unit.instance(), 333000));
					tran_ena(tr_UnnamedTransition0 | tr_UnnamedTransition14 | tr_UnnamedTransition0);
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

			if (SYNC_BUF_flag)
			{

				SYNC_BUF_flag = false;

				DELAY.add(add_time(unit.instance(), 0));
				tran_ena(tr_UnnamedTransition4 | tr_UnnamedTransition10);
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

			if (SEND_SENS_flag)
			{


				int ssi_idx;
				bytesn ssi = SSI.peek_indexed(ssi_idx);

				int n_idx;
				int n = SYNC.peek_indexed(n_idx);

				int dir_idx;
				bool dir = DPS.peek_indexed(dir_idx);



				SEND_SENS_flag = false;

				UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n, dir, 0, ssi)));
				tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition11);
				OnUnnamedTransition11()



			}
			;
			unlock(pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS);
		}
	}

	void UnnamedTransition1()
	{
		if (lock(pl_BatLevel | pl_BinTimer | pl_BUTTONS))
		{

			if (BatLevel_flag)
			{


				if (BinTimer.have_tokens())
				{
					; ;

					int inp_idx;
					int inp = BUTTONS.peek_indexed(inp_idx);

					BinTimer.get();
					BatLevel_flag = false;

					BinTimer.add(add_time(unit.instance(), 1000000));
					UDP_AND_CAN_SEND.add(tuple3(336, get_time(), (_N__4525)));
					UDP_AND_CAN_SEND.add(tuple3(721, get_time(), (_N__4526)));
					tran_ena(tr_UnnamedTransition15 | tr_UnnamedTransition15 | tr_UnnamedTransition1 | tr_UnnamedTransition1);
					OnUnnamedTransition1()

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

			if (SyncFreq.have_tokens())
			{
				int freq_idx;
				int SyncFreq_tok = SyncFreq.peek_indexed(freq);; int freq = SyncFreq_tok;;
				SyncFreq.get_indexed(freq_idx);

				SYNC.add(0);
				SyncFreq.add(add_time(freq(Delay(/ (1000000, freq))), 0));
				tran_ena(tr_UnnamedTransition2 | tr_UnnamedTransition11 | tr_UnnamedTransition2);
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

			if (TempTimer.have_relative_time(unit.instance(), 500000))
			{
				; ;

				int n_idx;
				int n = TEMP.peek_indexed(n_idx);

				TempTimer.get_relative_time(unit.instance(), 500000);

				TempTimer.add(add_time(unit.instance(), 0));
				UDP_AND_CAN_SEND.add(tuple3(721, get_time(), list.Cons(51, IntToList(n))));
				tran_ena(tr_UnnamedTransition15 | tr_UnnamedTransition3 | tr_UnnamedTransition3);
				OnUnnamedTransition3()

			}
			;
			unlock(pl_TempTimer | pl_TEMP);
		}
	}

	void UnnamedTransition12()
	{
		if (lock(pl_UDP_IN))
		{

			if (UDP_IN_flag)
			{
				int m_idx;
				CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
				if (is_sens(m))
				{
					UDP_IN_flag = false;

					SEND_SENS.add(unit.instance());
					tran_ena(tr_UnnamedTransition11 | tr_UnnamedTransition12);
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

			if (DELAY.have_relative_time(unit.instance(), 200000))
			{
				; ;
				DELAY.get_relative_time(unit.instance(), 200000);

				DELAY.add(add_time(unit.instance(), 0));
				SEND_SENS.add(unit.instance());
				tran_ena(tr_UnnamedTransition11 | tr_UnnamedTransition4 | tr_UnnamedTransition4);
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

			int bt_idx;
			u8 bt = BUTTONS.peek_indexed(bt_idx);


			UDP_AND_CAN_SEND.add(bt2can_message(bt));
			tran_ena(tr_UnnamedTransition15);
			OnBUTTONS()
				;
			unlock(pl_BUTTONS);
		}
	}

	void UnnamedTransition5()
	{
		if (lock(pl_ADC_SUM | pl_TIMER | pl_ADC))
		{

			if (ADC_SUM_flag)
			{


				if (TIMER.have_tokens())
				{
					; ;

					int q_idx;
					int q = ADC.peek_indexed(q_idx);
					if (< (n, 10))
					{

						TIMER.get();
						ADC_SUM_flag = false;

						TIMER.add(add_time(unit.instance(), 50000));
						ADC_SUM.add(tuple2(sum + q, n + 1));
						tran_ena(tr_UnnamedTransition13 | tr_UnnamedTransition5 | tr_UnnamedTransition5 | tr_UnnamedTransition5);
					}
					OnUnnamedTransition5()

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

			if (ADC_SUM_flag)
			{

				if (>= (n, 10))
				{
					ADC_SUM_flag = false;

					BatLevel.add(adc2bat(sum(div(n))));
					ADC_SUM.add(tuple2(0, 0));
					tran_ena(tr_UnnamedTransition13 | tr_UnnamedTransition5 | tr_UnnamedTransition1 | tr_UnnamedTransition13);
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

			int n_idx;
			int n = COUNTER.peek_indexed(n_idx);

			if (UDP_SEND.have_tokens())
			{
				int cm_idx;
				CAN_MESSAGE cm = UDP_SEND.peek_indexed(cm_idx);
				UDP_SEND.get_indexed(cm_idx);


				UDP_OUT.add(can2udp(cm, n));
				COUNTER.add(n + 1);
				tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition14);
				OnUnnamedTransition14()
			}

			;
			unlock(pl_COUNTER | pl_UDP_SEND);
		}
	}

	void UnnamedTransition15()
	{
		if (lock(pl_UDP_AND_CAN_SEND))
		{

			if (UDP_AND_CAN_SEND.have_tokens())
			{
				int cm_idx;
				CAN_MESSAGE cm = UDP_AND_CAN_SEND.peek_indexed(cm_idx);
				UDP_AND_CAN_SEND.get_indexed(cm_idx);

				CAN.add(cm);
				UDP_SEND.add(cm);
				tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition16 | tr_UnnamedTransition15);
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

			if (CAN.have_tokens())
			{
				int cm_idx;
				CAN_MESSAGE cm = CAN.peek_indexed(cm_idx);
				CAN.get_indexed(cm_idx);

				CAN_OUT.add(tuple2(cm, can_send(cm)));
				tran_ena(tr_UnnamedTransition18 | tr_UnnamedTransition17 | tr_UnnamedTransition16);
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

			if (CAN_OUT_flag)
			{

				if (not(res))
				{
					CAN_OUT_flag = false;

					CAN.add(cm);
					tran_ena(tr_UnnamedTransition16 | tr_UnnamedTransition17);
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

			if (CAN_OUT_flag)
			{

				if (res)
				{
					CAN_OUT_flag = false;

					tran_ena(tr_UnnamedTransition18);
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
