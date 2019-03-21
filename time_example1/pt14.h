class pt14 : public timed_petri_net32
{
	typedef enum
	{
		pl_DPS = 0x1,
		pl_SYNC = 0x2,
		pl_SSI = 0x4,
		pl_TEMP = 0x8,
		pl_BUTTONS = 0x10,
		pl_UDP_IN = 0x20,
		pl_CAN_IN = 0x40,
		pl_GPS = 0x80,
		pl_SEND_DEBUG = 0x100,
		pl_DELAY = 0x200,
		pl_BinTimer = 0x400,
		pl_SyncFreq = 0x800,
		pl_TempTimer = 0x1000,
		pl_SEND_SENS = 0x2000,
		pl_BatLevel = 0x4000,
		pl_ADC = 0x8000,
		pl_TIMER = 0x10000,
		pl_ADC_SUM = 0x20000,
		pl_DEBUG_TIMER = 0x40000,
		pl_UDP_OUT = 0x80000,
		pl_COUNTER = 0x100000,
		pl_CAN_OUT = 0x200000,
		pl_CAN = 0x400000
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

	struct INTxINT
	{
		INTxINT(int field1, int field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		int field1;
		int field2;
	};

	typedef INT QUEUE__INT;

	typedef INT TIMED_INT;

	typedef INT USHORT;





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

	typedef UNIT TIMED_VOID;

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

	typedef BYTES DEBUG_INFO;



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

	random_array DPS;
	u32 SYNC;
	req_tokens SSI;
	req_tokens TEMP;
	u8 BUTTONS;
	CAN_UDP_MESSAGE UDP_IN;
	bool UDP_IN_flag = false;
	CAN_MESSAGE CAN_IN;
	bool CAN_IN_flag = false;
	bytesn GPS;
	bool GPS_flag = false;
	bytesn SEND_DEBUG;
	bool SEND_DEBUG_flag = false;
	char DELAY;
	u32 DELAY_time;
	char BinTimer;
	u32 BinTimer_time;
	int SyncFreq = 0;
	u32 SyncFreq_time;
	char TempTimer;
	u32 TempTimer_time;
	char SEND_SENS;
	INTxINT BatLevel;
	bool BatLevel_flag = false;
	req_tokens ADC;
	char TIMER;
	u32 TIMER_time;
	INTxINT ADC_SUM;
	bool ADC_SUM_flag = false;
	char DEBUG_TIMER;
	u32 DEBUG_TIMER_time;
	random_array UDP_OUT;
	u16 COUNTER;
	CAN_MESSAGE CAN_OUT;
	bool CAN_OUT_flag = false;
	token_queue CAN;



	typedef enum
	{
		tr_UnnamedTransition1 = 0x1,
		tr_UnnamedTransition10 = 0x2,
		tr_GroupTransition1021 = 0x4,
		tr_UnnamedTransition0 = 0x8,
		tr_UnnamedTransition2 = 0x10,
		tr_UnnamedTransition3 = 0x20,
		tr_DPS = 0x40,
		tr_UnnamedTransition4 = 0x80,
		tr_UnnamedTransition6 = 0x100,
		tr_UnnamedTransition7 = 0x200,
		tr_UnnamedTransition8 = 0x400,
		tr_UnnamedTransition9 = 0x800,
		tr_UnnamedTransition11 = 0x1000,
		tr_BUTTONS = 0x2000,
		tr_UnnamedTransition12 = 0x4000,
		tr_UnnamedTransition13 = 0x8000,
		tr_UnnamedTransition16 = 0x10000,
		tr_UnnamedTransition17 = 0x20000
	} ttran;

	tran_func tran_funcs[] = { UnnamedTransition1,
UnnamedTransition10,
GroupTransition1021,
UnnamedTransition0,
UnnamedTransition2,
UnnamedTransition3,
DPS,
UnnamedTransition4,
UnnamedTransition6,
UnnamedTransition7,
UnnamedTransition8,
UnnamedTransition9,
UnnamedTransition11,
BUTTONS,
UnnamedTransition12,
UnnamedTransition13,
UnnamedTransition16,
UnnamedTransition17
	};

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
		u8 _N__4334[] = { (BYTE)1, bt };
		return CAN_MESSAGE(721, time(), byte2(_N__4334));
	}

	bool is_sens(const CAN_UDP_MESSAGE &m)
	{
		return m.ID == 663;
	}

	bool is_control(const CAN_UDP_MESSAGE &m)
	{
		return m.ID == 80;
	}

	u32 get_next_time(u32 &res_tr)
	{
		u32 tr = 0;

		u32 min = 0xFFFFFFFF, time;
		time = DELAY_time + 200000;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition11;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition11;
			}
		time = BinTimer_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition7;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition7;
			}
		time = SyncFreq_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition8;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition8;
			}
		time = TempTimer_time + 500000;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition9;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition9;
			}
		time = TIMER_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition12;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition12;
			}
		time = DEBUG_TIMER_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition4;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition4;
			};
		;
		res_tr = tr;
		return min;
	}

protected:

	tran_func get_transition(int n) const
	{
		return tran_funcs[n];
	}

public:

	pt14(int time_step = 15)
	{
		timed_petri_net32(time_step);
		DPS.add(false);
		SYNC = 0;
		SSI.add(byte0(_N__4320));
		TEMP.add(0);
		BUTTONS = 0;
		UDP_IN_flag = false;
		CAN_IN_flag = false;
		GPS_flag = false;
		SEND_DEBUG_flag = false;
		SYNC_BUF = 0;
		DELAY = 1;
		DELAY_time = 0;
		BinTimer = 1;
		BinTimer_time = 1000000;
		SyncFreq = 0;
		TempTimer = 1;
		TempTimer_time = 500000;
		SEND_SENS = 0;
		BatLevel_flag = false;
		TIMER = 1;
		TIMER_time = 0;
		ADC_SUM = tuple2(0, 0);
		ADC_SUM_flag = true;
		DEBUG_TIMER = 1;
		DEBUG_TIMER_time = 0;
		COUNTER = 0;
		CAN_OUT_flag = false;

	}

	void GroupTransition1021()
	{
		if (!UnnamedTransition10())
			if (!UnnamedTransition1())
				if (!UnnamedTransition2())
					return;
		tran_ena(0, tr_GroupTransition1021);
	}

	bool UnnamedTransition0()
	{
		bool res = false;
		if (lock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_GPS, tr_UnnamedTransition0))
		{
			if (GPS_flag)
			{
				const bytesn &s = GPS;
				GPS_flag = false;
				;
				UDP_SEND(tuple3(256, time64(), s));
				tran_ena(0, tr_UnnamedTransition0);
				res = true;
			};
			unlock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_GPS);
		}
		return res;
	}

	bool UnnamedTransition1()
	{
		bool res = false;
		if (lock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_UDP_IN, tr_GroupTransition1021))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				if (is_control(m))
				{
					UDP_IN_flag = false;
					;
					UDP_SEND(get_control_msg(m));
					res = true;
				}
			};
			unlock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_UDP_IN);
		}
		return res;
	}

	bool UnnamedTransition2()
	{
		bool res = false;
		if (lock(pl_CAN | pl_UDP_IN, tr_GroupTransition1021))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				UDP_IN_flag = false;
				;
				CAN.add(udp2can(m));
				UnnamedTransition16();
				res = true;
			};
			unlock(pl_CAN | pl_UDP_IN);
		}
		return res;
	}

	bool UnnamedTransition3()
	{
		bool res = false;
		if (lock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN_IN, tr_UnnamedTransition3))
		{
			if (CAN_IN_flag)
			{
				const CAN_MESSAGE &cm = CAN_IN;
				CAN_IN_flag = false;
				can_process(cm);
				UDP_SEND(cm);
				tran_ena(0, tr_UnnamedTransition3);
				res = true;
			};
			unlock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN_IN);
		}
		return res;
	}

	bool DPS()
	{
		bool res = false;
		if (lock(pl_SYNC_BUF | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS, tr_DPS))
		{
			const bytes8 &ssi = SSI.peek();
			int n = SYNC;
			if (DPS.have_tokens())
			{
				int dir_idx;
				bool dir = DPS.peek_indexed(dir_idx);
				DPS.get_indexed(dir_idx);
				;
				SYNC = n + 1;
				UDP_SEND(tuple3(663, time64(), get_ssi_bytes(n, dir, 1, ssi)));
				SYNC_BUF(1);
				UnnamedTransition6();
				res = true;
			};
			unlock(pl_SYNC_BUF | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
		}
		return res;
	}

	bool UnnamedTransition4()
	{
		bool res = false;
		if (lock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_DEBUG_TIMER | pl_SEND_DEBUG, tr_UnnamedTransition4))
		{
			if (SEND_DEBUG_flag)
			{
				const bytesn &d = SEND_DEBUG;
				SEND_DEBUG_flag = false;
				;
				UDP_SEND(tuple3(0, time64(), d));

				DEBUG_TIMER_time = time() + 333000;
				res = true;
			};
			unlock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_DEBUG_TIMER | pl_SEND_DEBUG);
		}
		return res;
	}

	bool UnnamedTransition6()
	{
		bool res = false;
		if (lock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS, tr_UnnamedTransition6))
		{
			if (SEND_SENS)
			{
				const bytes8 &ssi = SSI.peek();
				int n = SYNC;
				if (DPS.have_tokens())
				{
					int dir_idx;
					bool dir = DPS.peek_indexed(dir_idx);
					DPS.get_indexed(dir_idx);
					SEND_SENS = 0;
					;
					UDP_SEND(tuple3(663, time64(), get_ssi_bytes(n, dir, 0, ssi)));
					tran_ena(0, tr_UnnamedTransition6);
					res = true;
				}
			};
			unlock(pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS);
		}
		return res;
	}

	bool UnnamedTransition7()
	{
		bool res = false;
		if (lock(pl_UDP_AND_CAN_SEND | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN | pl_CAN_OUT | pl_BatLevel | pl_BinTimer | pl_BUTTONS, tr_UnnamedTransition7))
		{
			if (BatLevel_flag)
			{
				u8 bt = BatLevel.field0;
				int n = BatLevel.field1;
				int inp = BUTTONS;
				BatLevel_flag = false;
				;

				BinTimer_time = time() + 1000000;
				UDP_AND_CAN_SEND(tuple3(336, time64(), (_N__4332)));
				UDP_AND_CAN_SEND(tuple3(721, time64(), (_N__4333)));
				res = true;
			};
			unlock(pl_UDP_AND_CAN_SEND | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN | pl_CAN_OUT | pl_BatLevel | pl_BinTimer | pl_BUTTONS);
		}
		return res;
	}

	bool UnnamedTransition8()
	{
		bool res = false;
		if (lock(pl_SyncFreq | pl_SYNC | pl_SyncFreq, tr_UnnamedTransition8))
		{
			if (SyncFreq)
			{
				;
				SYNC = 0;

				SyncFreq_time = time() + 1000000 / freq;
				UnnamedTransition6();
				res = true;
			};
			unlock(pl_SyncFreq | pl_SYNC | pl_SyncFreq);
		}
		return res;
	}

	bool UnnamedTransition9()
	{
		bool res = false;
		if (lock(pl_UDP_AND_CAN_SEND | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN | pl_CAN_OUT | pl_TempTimer | pl_TEMP, tr_UnnamedTransition9))
		{
			int n = TEMP.peek();
			;

			TempTimer_time = time();
			UDP_AND_CAN_SEND(tuple3(721, time64(), IntToList(51 + n * 256)));
			res = true;;
			unlock(pl_UDP_AND_CAN_SEND | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN | pl_CAN_OUT | pl_TempTimer | pl_TEMP);
		}
		return res;
	}

	bool UnnamedTransition10()
	{
		bool res = false;
		if (lock(pl_SEND_SENS | pl_UDP_IN, tr_GroupTransition1021))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				if (is_sens(m))
				{
					UDP_IN_flag = false;
					;
					SEND_SENS = 1;
					UnnamedTransition6();
					res = true;
				}
			};
			unlock(pl_SEND_SENS | pl_UDP_IN);
		}
		return res;
	}

	bool UnnamedTransition11()
	{
		bool res = false;
		if (lock(pl_SEND_SENS | pl_DELAY | pl_DELAY, tr_UnnamedTransition11))
		{
			;

			DELAY_time = time();
			SEND_SENS = 1;
			UnnamedTransition6();
			res = true;;
			unlock(pl_SEND_SENS | pl_DELAY | pl_DELAY);
		}
		return res;
	}

	bool BUTTONS()
	{
		bool res = false;
		if (lock(pl_UDP_AND_CAN_SEND | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN | pl_CAN_OUT | pl_BUTTONS, tr_BUTTONS))
		{
			u8 bt = BUTTONS;
			;
			UDP_AND_CAN_SEND(bt2can_message(bt));
			res = true;;
			unlock(pl_UDP_AND_CAN_SEND | pl_UDP_SEND | pl_UDP_OUT | pl_COUNTER | pl_CAN | pl_CAN_OUT | pl_BUTTONS);
		}
		return res;
	}

	bool UnnamedTransition12()
	{
		bool res = false;
		if (lock(pl_ADC_SUM | pl_TIMER | pl_ADC_SUM | pl_TIMER | pl_ADC, tr_UnnamedTransition12))
		{
			if (ADC_SUM_flag)
			{
				int sum = ADC_SUM.field0;
				int n = ADC_SUM.field1;
				int q = ADC.peek();
				if (n < 10)
				{
					ADC_SUM_flag = false;
					;

					TIMER_time = time() + 50000;
					ADC_SUM = tuple2(sum + q, n + 1);
					ADC_SUM_flag = true;
					UnnamedTransition13();
					res = true;
				}
			};
			unlock(pl_ADC_SUM | pl_TIMER | pl_ADC_SUM | pl_TIMER | pl_ADC);
		}
		return res;
	}

	bool UnnamedTransition13()
	{
		bool res = false;
		if (lock(pl_ADC_SUM | pl_BatLevel | pl_ADC_SUM, tr_UnnamedTransition13))
		{
			if (ADC_SUM_flag)
			{
				int sum = ADC_SUM.field0;
				int n = ADC_SUM.field1;
				if (n >= 10)
				{
					ADC_SUM_flag = false;
					;
					BatLevel = adc2bat(sum(div(n)));
					BatLevel_flag = true;
					ADC_SUM = tuple2(0, 0);
					ADC_SUM_flag = true;
					tran_ena(0, tr_UnnamedTransition13);
					UnnamedTransition13();
					res = true;
				}
			};
			unlock(pl_ADC_SUM | pl_BatLevel | pl_ADC_SUM);
		}
		return res;
	}

	bool UnnamedTransition16()
	{
		bool res = false;
		if (lock(pl_CAN_OUT | pl_CAN, tr_UnnamedTransition16))
		{
			if (CAN.have_tokens())
			{
				const CAN_MESSAGE &cm = CAN.peek();
				CAN.get(cm);
				;
				CAN_OUT = cm;
				CAN_OUT_flag = true;
				tran_ena(0, tr_UnnamedTransition16);
				UnnamedTransition17();
				res = true;
			};
			unlock(pl_CAN_OUT | pl_CAN);
		}
		return res;
	}

	bool UnnamedTransition17()
	{
		bool res = false;
		if (lock(pl_CAN | pl_CAN_OUT, tr_UnnamedTransition17))
		{
			if (CAN_OUT_flag)
			{
				const CAN_MESSAGE &cm = CAN_OUT;
				CAN_OUT_flag = false;
				;
				CAN.add(cm);
				tran_ena(0, tr_UnnamedTransition17);
				UnnamedTransition16();
				res = true;
			};
			unlock(pl_CAN | pl_CAN_OUT);
		}
		return res;
	}

	void UDP_SEND(const CAN_MESSAGE &cm)
	{
		int n = COUNTER;
		;
		UDP_OUT.add(can2udp(cm, n));
		COUNTER = n + 1;
	}

	void SYNC_BUF(char param)
	{
		;
		DELAY = 1;
		DELAY_time = time();
	}

	void UDP_AND_CAN_SEND(const CAN_MESSAGE &cm)
	{
		;
		UDP_SEND(cm);
		CAN.add(cm);
		UnnamedTransition16();
	}

	function adc2bat;
	function get_ssi_bytes;
	function get_control_msg;
	function can_process;


	void add_DPS(bool param)
	{
		DPS.add(param);
		UnnamedTransition6();
	}

	void add_SSI(const bytes8 &param)
	{
		SSI.add(param);
		UnnamedTransition6();
	}

	void add_TEMP(int param)
	{
		TEMP.add(param);
		UnnamedTransition9();
	}

	void add_BUTTONS(u8 param)
	{
		BUTTONS = param;
		UnnamedTransition7();
	}

	void add_UDP_IN(const CAN_UDP_MESSAGE &param)
	{
		UDP_IN = param;
		UDP_IN_flag = true;
		GroupTransition1021();
	}

	void add_CAN_IN(const CAN_MESSAGE &param)
	{
		CAN_IN = param;
		CAN_IN_flag = true;
		UnnamedTransition3();
	}

	void add_ADC(int param)
	{
		ADC.add(param);
		UnnamedTransition12();
	}

	function add_UDP_OUT;
};
