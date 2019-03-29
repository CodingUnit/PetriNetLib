#include "timed_petrinet.h"

using namespace petrinet_lib;

class pt14 : public timed_petri_net32
{
public:
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
		TSYNC() {}
		TSYNC(int field0, bool field1)
		{
			this->field0 = field0;
			this->field1 = field1;
		}

		TSYNC(const tuple2<int, bool> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}

		int field0;
		bool field1;

		void operator=(const tuple2<int, bool> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}
	};

	typedef INT SINGLE__INT;

	typedef INTINF LONGTIME;

	struct INTxINT
	{
		INTxINT() {}
		INTxINT(int field0, int field1)
		{
			this->field0 = field0;
			this->field1 = field1;
		}

		INTxINT(const tuple2<int, int> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}

		int field0;
		int field1;

		void operator=(const tuple2<int, int> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}
	};

	typedef INT TIMED_INT;

	typedef INT USHORT;

	typedef bytesn BYTES;

	typedef bytes8 BYTES8;

	struct BYTES_BOOL
	{
		BYTES_BOOL() {}
		BYTES_BOOL(const bytes &field0, bool field1)
		{
			this->field0 = field0;
			this->field1 = field1;
		}

		BYTES_BOOL(const tuple2<bytesn, bool> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}

		bytesn field0;
		bool field1;

		void operator=(const tuple2<bytesn, bool> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}
	};

	struct CAN_MESSAGE
	{
		CAN_MESSAGE() {}
		CAN_MESSAGE(int field0, long long field1, const bytes &field2)
		{
			this->field0 = field0;
			this->field1 = field1;
			this->field2 = field2;
		}

		CAN_MESSAGE(const tuple3<int, long long, bytes8> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
			field2 = tup.field2;
		}

		int field0;
		long long field1;
		bytes8 field2;

		void operator=(const tuple3<int, long long, bytes8> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
			field2 = tup.field2;
		}
	};

	typedef UNIT TIMED_VOID;

	struct CAN_UDP_MESSAGE
	{
		CAN_UDP_MESSAGE() {}
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

	typedef bytesn TSSI;

	struct CONTROL_MSG
	{
		CONTROL_MSG() {}
		CONTROL_MSG(u8 field0, u16 field1, u32 field2)
		{
			this->field0 = field0;
			this->field1 = field1;
			this->field2 = field2;
		}

		CONTROL_MSG(const tuple3<u8, u16, u32> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
			field2 = tup.field2;
		}

		u8 field0;
		u16 field1;
		u32 field2;

		void operator=(const tuple3<u8, u16, u32> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
			field2 = tup.field2;
		}
	};

	struct CONTROL_MSG_BOOL
	{
		CONTROL_MSG_BOOL() {}
		CONTROL_MSG_BOOL(const CONTROL_MSG &field0, bool field1)
		{
			this->field0 = field0;
			this->field1 = field1;
		}

		CONTROL_MSG_BOOL(const tuple2<CONTROL_MSG, bool> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}

		CONTROL_MSG field0;
		bool field1;

		void operator=(const tuple2<CONTROL_MSG, bool> &tup)
		{
			field0 = tup.field0;
			field1 = tup.field1;
		}
	};

private:

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
		pl_BatLevel = 0x2000,
		pl_ADC = 0x4000,
		pl_TIMER = 0x8000,
		pl_ADC_SUM = 0x10000,
		pl_DEBUG_TIMER = 0x20000,
		pl_COUNTER = 0x40000,
		pl_CAN_OUT = 0x80000,
		pl_CAN = 0x100000,
		pl_UDP_OUT = 0x200000,
		pl_ControlCheck = 0x400000
	} tplace;
	bool DPS;
	u32 SYNC;
	function SSI;
	function TEMP;
	u8 BUTTONS;
	CAN_UDP_MESSAGE UDP_IN;
	bool UDP_IN_flag;
	CAN_MESSAGE CAN_IN;
	bool CAN_IN_flag;
	bytesn GPS;
	bool GPS_flag;
	bytesn SEND_DEBUG;
	bool SEND_DEBUG_flag;
	char DELAY;
	u32 DELAY_time;
	char BinTimer;
	u32 BinTimer_time;
	int SyncFreq;
	u32 SyncFreq_time;
	char TempTimer;
	u32 TempTimer_time;
	INTxINT BatLevel;
	bool BatLevel_flag;
	function ADC;
	char TIMER;
	u32 TIMER_time;
	INTxINT ADC_SUM;
	bool ADC_SUM_flag;
	char DEBUG_TIMER;
	u32 DEBUG_TIMER_time;
	u16 COUNTER;
	token_queue CAN;
	CONTROL_MSG_BOOL ControlCheck;
	bool ControlCheck_flag;


	typedef bool (pt14::*tran_func_type)();

	typedef enum
	{
		tr_UnnamedTransition1 = 0x1,
		tr_UnnamedTransition11 = 0x2,
		tr_GroupTransition1121 = 0x4,
		tr_UnnamedTransition0 = 0x8,
		tr_UnnamedTransition2 = 0x10,
		tr_UnnamedTransition3 = 0x20,
		tr_UnnamedTransition4 = 0x40,
		tr_UnnamedTransition5 = 0x80,
		tr_UnnamedTransition8 = 0x100,
		tr_UnnamedTransition9 = 0x200,
		tr_UnnamedTransition10 = 0x400,
		tr_UnnamedTransition12 = 0x800,
		tr_UnnamedTransition13 = 0x1000,
		tr_UnnamedTransition14 = 0x2000,
		tr_UnnamedTransition15 = 0x4000,
		tr_UnnamedTransition18 = 0x8000,
		tr_UnnamedTransition20 = 0x10000
	} ttran;

	tran_func_type tran_funcs[17];

	static const int P_LOW = 10000;
	static const int P_NORMAL = 1000;
	static const int P_HIGH = 100;


	bool UnnamedTransition0()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_GPS, tr_UnnamedTransition0))
		{
			if (GPS_flag)
			{
				const bytesn &s = GPS;
				GPS_flag = false;
				;
				UDP_SEND(CAN_MESSAGE(256, time64(), s));
				tran_ena(tr_UnnamedTransition0);
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_GPS);
		}
		return res;
	}

	bool UnnamedTransition1()
	{
		bool res = false;
		if (lock(pl_ControlCheck | pl_UDP_IN, tr_GroupTransition1121))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				if (is_control(m))
				{
					UDP_IN_flag = false;
					;
					ControlCheck = get_control_msg(m);
					ControlCheck_flag = true;
					res = true;
				}
			};
			unlock(pl_ControlCheck | pl_UDP_IN);
			if (res)
			{
				UnnamedTransition20();
			}
		}
		return res;
	}

	bool UnnamedTransition2()
	{
		bool res = false;
		if (lock(pl_CAN | pl_UDP_IN, tr_GroupTransition1121))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				UDP_IN_flag = false;
				;
				CAN.add(udp2can(m));
				res = true;
			};
			unlock(pl_CAN | pl_UDP_IN);
			if (res)
			{
				UnnamedTransition18();
			}
		}
		return res;
	}

	bool UnnamedTransition3()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN_IN, tr_UnnamedTransition3))
		{
			if (CAN_IN_flag)
			{
				const CAN_MESSAGE &cm = CAN_IN;
				CAN_IN_flag = false;
				can_process(cm);
				UDP_SEND(cm);
				tran_ena(tr_UnnamedTransition3);
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN_IN);
		}
		return res;
	}

	bool UnnamedTransition4()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS, tr_UnnamedTransition4))
		{
			const bytes8 &ssi = SSI.exec_ret<bytes8>();
			int n = SYNC;
			bool dir = DPS;
			;
			SYNC = n + 1;
			UDP_SEND(CAN_MESSAGE(663, time64(), get_ssi_bytes(n, dir, 1, ssi)));
			SYNC_BUF(1);
			tran_ena(tr_UnnamedTransition4);
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
			if (res)
			{
				UnnamedTransition4();
			}
		}
		return res;
	}

	bool UnnamedTransition5()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_DEBUG_TIMER | pl_SEND_DEBUG, tr_UnnamedTransition5))
		{
			if (SEND_DEBUG_flag)
			{
				const bytesn &d = SEND_DEBUG;
				SEND_DEBUG_flag = false;
				;
				UDP_SEND(CAN_MESSAGE(0, time64(), d));

				DEBUG_TIMER_time = time() + 333000;
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_DEBUG_TIMER | pl_SEND_DEBUG);
		}
		return res;
	}

	bool UnnamedTransition8()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BatLevel | pl_BinTimer | pl_BUTTONS, tr_UnnamedTransition8))
		{
			if (BatLevel_flag)
			{
				u8 bt = BatLevel.field0;
				int n = BatLevel.field1;
				int inp = BUTTONS;
				BatLevel_flag = false;
				;

				BinTimer_time = time() + 1000000;
				UDP_AND_CAN_SEND(CAN_MESSAGE(336, time64(), (_N__4357)));
				UDP_AND_CAN_SEND(CAN_MESSAGE(721, time64(), (_N__4358)));
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BatLevel | pl_BinTimer | pl_BUTTONS);
		}
		return res;
	}

	bool UnnamedTransition9()
	{
		bool res = false;
		if (lock(pl_SYNC | pl_SyncFreq, tr_UnnamedTransition9))
		{
			if (SyncFreq)
			{
				;
				SYNC = 0;

				SyncFreq_time = time() + 1000000 / freq;
				res = true;
			};
			unlock(pl_SYNC | pl_SyncFreq);
			if (res)
			{
				UnnamedTransition4();
			}
		}
		return res;
	}

	bool UnnamedTransition10()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_TempTimer | pl_TEMP, tr_UnnamedTransition10))
		{
			int n = TEMP.exec_ret<int>();
			;

			TempTimer_time = time();
			UDP_AND_CAN_SEND(CAN_MESSAGE(721, time64(), IntToList(51 + n * 256)));
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_TempTimer | pl_TEMP);
		}
		return res;
	}

	bool UnnamedTransition11()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_UDP_IN, tr_GroupTransition1121))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				if (is_sens(m))
				{
					UDP_IN_flag = false;
					;
					SEND_SENS(1);
					res = true;
				}
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_UDP_IN);
		}
		return res;
	}

	bool UnnamedTransition12()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_DELAY, tr_UnnamedTransition12))
		{
			;

			DELAY_time = time();
			SEND_SENS(1);
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_DELAY);
			if (res)
			{
				UnnamedTransition4();
			}
		}
		return res;
	}

	bool UnnamedTransition13()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BUTTONS, tr_UnnamedTransition13))
		{
			u8 bt = BUTTONS;
			;
			UDP_AND_CAN_SEND(bt2can_message(bt));
			tran_ena(tr_UnnamedTransition13);
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BUTTONS);
		}
		return res;
	}

	bool UnnamedTransition14()
	{
		bool res = false;
		if (lock(pl_ADC_SUM | pl_TIMER | pl_ADC, tr_UnnamedTransition14))
		{
			if (ADC_SUM_flag)
			{
				int sum = ADC_SUM.field0;
				int n = ADC_SUM.field1;
				int q = ADC.exec_ret<int>();
				if (n < 10)
				{
					ADC_SUM_flag = false;
					;

					TIMER_time = time() + 50000;
					ADC_SUM = INTxINT(sum + q, n + 1);
					ADC_SUM_flag = true;
					res = true;
				}
			};
			unlock(pl_ADC_SUM | pl_TIMER | pl_ADC);
			if (res)
			{
				UnnamedTransition15();
			}
		}
		return res;
	}

	bool UnnamedTransition15()
	{
		bool res = false;
		if (lock(pl_BatLevel | pl_ADC_SUM, tr_UnnamedTransition15))
		{
			if (ADC_SUM_flag)
			{
				int sum = ADC_SUM.field0;
				int n = ADC_SUM.field1;
				if (n >= 10)
				{
					ADC_SUM_flag = false;
					;
					BatLevel = adc2bat(sum / n);
					BatLevel_flag = true;
					ADC_SUM = INTxINT(0, 0);
					ADC_SUM_flag = true;
					tran_ena(tr_UnnamedTransition15);
					res = true;
				}
			};
			unlock(pl_BatLevel | pl_ADC_SUM);
			if (res)
			{
				UnnamedTransition15();
			}
		}
		return res;
	}

	bool UnnamedTransition18()
	{
		bool res = false;
		if (lock(pl_CAN_OUT | pl_CAN, tr_UnnamedTransition18))
		{
			const CAN_MESSAGE *res_cm;
			if (CAN.have_tokens())
			{
				const CAN_MESSAGE &cm = CAN.peek();
				res_cm = *cm;

				CAN.get(cm);
				;
				bool in = CAN_OUT.exec_ref_ret_bool(cm);
				tran_ena(tr_UnnamedTransition18);
				res = in;
			};
			unlock(pl_CAN_OUT | pl_CAN);
			if (res)
			{
				UnnamedTransition19(*res_cm);
			}
		}
		return res;
	}

	bool UnnamedTransition19(const CAN_MESSAGE &cm)
	{
		bool res = false;
		if (lock(pl_CAN | pl_CAN_OUT, tr_UnnamedTransition19))
		{
			;
			CAN.add(cm);
			tran_ena(tr_UnnamedTransition19);
			res = true;;
			unlock(pl_CAN | pl_CAN_OUT);
			if (res)
			{
				UnnamedTransition18();
			}
		}
		return res;
	}

	bool UnnamedTransition20()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_ControlCheck, tr_UnnamedTransition20))
		{
			if (ControlCheck_flag)
			{
				const CONTROL_MSG &cnm = ControlCheck.field0;
				bool ok = ControlCheck.field1;
				if (ok)
				{
					ControlCheck_flag = false;
					;
					UDP_SEND(control2can(cnm));
					tran_ena(tr_UnnamedTransition20);
					res = true;
				}
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_ControlCheck);
		}
		return res;
	}

	CAN_MESSAGE  control2can(const CONTROL_MSG &m)
	{
		return CAN_MESSAGE(80, time64(), bytesn(&m, sizeof(m)));
	}

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
		u8 _N__4359[] = { (BYTE)1, bt };
		return CAN_MESSAGE(721, time(), byte2(_N__4359));
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
			tr = tr_UnnamedTransition4
				tr = tr_UnnamedTransition12;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition4
					tr |= tr_UnnamedTransition12;
			}
		time = BinTimer_time;
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
		time = SyncFreq_time;
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
		time = TempTimer_time + 500000;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition10;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition10;
			}
		time = TIMER_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition14;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition14;
			}
		time = DEBUG_TIMER_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition5;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition5;
			};
		;
		res_tr = tr;
		return min;
	}

protected:

	tran_func get_transition(int n) const
	{
		return *(tran_func *)&tran_funcs[n];
	}

public:

	pt14(int time_step = 15)
	{
		timed_petri_net32(time_step);
		DPS = false;
		SYNC = 0;
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
		ControlCheck_flag = false;
		tran_funcs[0] = &pt14::UnnamedTransition1;
		tran_funcs[1] = &pt14::UnnamedTransition11;
		tran_funcs[2] = &pt14::GroupTransition1121;
		tran_funcs[3] = &pt14::UnnamedTransition0;
		tran_funcs[4] = &pt14::UnnamedTransition2;
		tran_funcs[5] = &pt14::UnnamedTransition3;
		tran_funcs[6] = &pt14::UnnamedTransition4;
		tran_funcs[7] = &pt14::UnnamedTransition5;
		tran_funcs[8] = &pt14::UnnamedTransition8;
		tran_funcs[9] = &pt14::UnnamedTransition9;
		tran_funcs[10] = &pt14::UnnamedTransition10;
		tran_funcs[11] = &pt14::UnnamedTransition12;
		tran_funcs[12] = &pt14::UnnamedTransition13;
		tran_funcs[13] = &pt14::UnnamedTransition14;
		tran_funcs[14] = &pt14::UnnamedTransition15;
		tran_funcs[15] = &pt14::UnnamedTransition18;
		tran_funcs[16] = &pt14::UnnamedTransition20;
	}

	bool GroupTransition1121()
	{
		if (!UnnamedTransition11())
			if (!UnnamedTransition1())
				if (!UnnamedTransition2())
					return false;
		tran_ena(0, tr_GroupTransition1121);
		return true;
	}

	void UDP_SEND(const CAN_MESSAGE &cm)
	{
		int n = COUNTER;
		;
		COUNTER = n + 1;
		UDP_OUT.exec_ref(can2udp(cm, n));
	}

	void SYNC_BUF(char param)
	{
		;
		DELAY = 1;
		DELAY_time = time();
	}

	void SEND_SENS(char param)
	{
		const bytes8 &ssi = SSI.exec_ret<bytes8>();
		int n = SYNC;
		bool dir = DPS;
		;
		UDP_SEND(CAN_MESSAGE(663, time64(), get_ssi_bytes(n, dir, 0, ssi)));
	}

	void UDP_AND_CAN_SEND(const CAN_MESSAGE &cm)
	{
		;
		UDP_SEND(cm);
		CAN.add(cm);
	}

	void init_SSI(const function &func)
	{
		SSI = func;
	}

	void init_TEMP(const function &func)
	{
		TEMP = func;
	}

	void init_ADC(const function &func)
	{
		ADC = func;
	}

	function adc2bat;
	function get_ssi_bytes;
	function get_control_msg;
	function can_process;


	void add_DPS(bool param)
	{
		DPS = param;
		UnnamedTransition4();
		UnnamedTransition7();
	}

	void add_SSI(const bytes8 &param)
	{
		SSI.add(param);
		UnnamedTransition4();
		UnnamedTransition7();
	}

	void add_TEMP(int param)
	{
		TEMP.add(param);
		UnnamedTransition10();
	}

	void add_BUTTONS(u8 param)
	{
		BUTTONS = param;
		UnnamedTransition8();
		UnnamedTransition13();
	}

	void add_UDP_IN(const CAN_UDP_MESSAGE &param)
	{
		UDP_IN = param;
		UDP_IN_flag = true;
		GroupTransition1121();
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
		UnnamedTransition14();
	}

	function CAN_OUT;
	function UDP_OUT;
};
