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
		TSYNC(int field1, bool field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		TSYNC(const tuple2<int, bool> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}

		int field1;
		bool field2;

		void operator=(const tuple2<int, bool> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}
	};

	typedef INT SINGLE__INT;

	typedef INTINF LONGTIME;

	struct INTxINT
	{
		INTxINT() {}
		INTxINT(int field1, int field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		INTxINT(const tuple2<int, int> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}

		int field1;
		int field2;

		void operator=(const tuple2<int, int> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}
	};

	typedef INT TIMED_INT;

	typedef INT USHORT;

	typedef bytesn BYTES;

	typedef bytes8 BYTES8;

	struct BYTES_BOOL
	{
		BYTES_BOOL() {}
		BYTES_BOOL(const bytes &field1, bool field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		BYTES_BOOL(const tuple2<bytesn, bool> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}

		bytesn field1;
		bool field2;

		void operator=(const tuple2<bytesn, bool> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}
	};

	struct CAN_MESSAGE
	{
		CAN_MESSAGE() {}
		CAN_MESSAGE(int field1, long long field2, const bytes &field3)
		{
			this->field1 = field1;
			this->field2 = field2;
			this->field3 = field3;
		}

		CAN_MESSAGE(const tuple3<int, long long, bytes8> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
			field3 = tup.field3;
		}

		int field1;
		long long field2;
		bytes8 field3;

		void operator=(const tuple3<int, long long, bytes8> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
			field3 = tup.field3;
		}
	};

	typedef UNIT TIMED_VOID;

	struct CAN_UDP_MESSAGE
	{
		CAN_UDP_MESSAGE() {}
		CAN_UDP_MESSAGE(u16 COUNT, u16 ID, long long timestamp, const bytes &data)
		{
			this->COUNT = COUNT;
			this->ID = ID;
			this->timestamp = timestamp;
			this->data = data;
		}
		u16 COUNT;
		u16 ID;
		long long timestamp;
		bytesn data;
	};

	typedef INT VAR__INT;

	typedef BYTES DEBUG_INFO;

	typedef bytesn TSSI;

	struct CONTROL_MSG
	{
		CONTROL_MSG() {}
		CONTROL_MSG(u8 field1, u16 field2, u32 field3)
		{
			this->field1 = field1;
			this->field2 = field2;
			this->field3 = field3;
		}

		CONTROL_MSG(const tuple3<u8, u16, u32> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
			field3 = tup.field3;
		}

		u8 field1;
		u16 field2;
		u32 field3;

		void operator=(const tuple3<u8, u16, u32> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
			field3 = tup.field3;
		}
	};

	struct CONTROL_MSG_BOOL
	{
		CONTROL_MSG_BOOL() {}
		CONTROL_MSG_BOOL(const CONTROL_MSG &field1, bool field2)
		{
			this->field1 = field1;
			this->field2 = field2;
		}

		CONTROL_MSG_BOOL(const tuple2<CONTROL_MSG, bool> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
		}

		CONTROL_MSG field1;
		bool field2;

		void operator=(const tuple2<CONTROL_MSG, bool> &tup)
		{
			field1 = tup.field1;
			field2 = tup.field2;
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
		pl_ControlCheck = 0x400000,
		pl_STEP = 0x800000,
		pl_Init = 0x1000000,
		pl_GPSLEDCntr = 0x2000000,
		pl_GPSLED = 0x4000000,
		pl_SYNCLEDCntr = 0x8000000,
		pl_SYNCLED = 0x10000000,
		pl_ResetTime = 0x20000000
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
	int STEP;
	char Init;
	u8 GPSLEDCntr;
	char GPSLED;
	u8 SYNCLEDCntr;
	char SYNCLED;
	char ResetTime;
	bool ResetTime_flag;
	u32 ResetTime_time;


	typedef bool (pt14::*tran_func_type)();

	typedef enum
	{
		tr_UnnamedTransition1 = 0x1,
		tr_UnnamedTransition9 = 0x2,
		tr_GroupTransition921 = 0x4,
		tr_UnnamedTransition0 = 0x8,
		tr_UnnamedTransition2 = 0x10,
		tr_UnnamedTransition3 = 0x20,
		tr_tran_DPS = 0x40,
		tr_UnnamedTransition4 = 0x80,
		tr_UnnamedTransition7 = 0x100,
		tr_UnnamedTransition8 = 0x200,
		tr_UnnamedTransition10 = 0x400,
		tr_UnnamedTransition11 = 0x800,
		tr_UnnamedTransition12 = 0x1000,
		tr_UnnamedTransition13 = 0x2000,
		tr_UnnamedTransition16 = 0x4000,
		tr_UnnamedTransition18 = 0x8000,
		tr_UnnamedTransition19 = 0x10000,
		tr_UnnamedTransition20 = 0x20000,
		tr_UnnamedTransition21 = 0x40000,
		tr_UnnamedTransition22 = 0x80000,
		tr_UnnamedTransition23 = 0x100000,
		tr_UnnamedTransition24 = 0x200000,
		tr_UnnamedTransition25 = 0x400000,
		tr_UnnamedTransition26 = 0x800000
	} ttran;

	tran_func_type tran_funcs[24];

	static const int P_LOW = 10000;
	static const int P_NORMAL = 1000;
	static const int P_HIGH = 100;


	function CAN_OUT;
	function UDP_OUT;
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
				UDP_SEND(CAN_MESSAGE(0x100, time64(), s));
				GPSLED = 1;
				tran_ena(tr_UnnamedTransition0);
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_GPS);
			if (res)
			{
				UnnamedTransition21();
				UnnamedTransition22();
			}
		}
		return res;
	}

	bool UnnamedTransition1()
	{
		bool res = false;
		if (lock(pl_ControlCheck | pl_UDP_IN, tr_GroupTransition921))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				if (is_control(m))
				{
					UDP_IN_flag = false;
					;
					ControlCheck = get_control_msg.exec_ret<CONTROL_MSG_BOOL, const CAN_UDP_MESSAGE &>(m);
					ControlCheck_flag = true;
					res = true;
				}
			};
			unlock(pl_ControlCheck | pl_UDP_IN);
			if (res)
			{
				UnnamedTransition18();
			}
		}
		return res;
	}

	bool UnnamedTransition2()
	{
		bool res = false;
		if (lock(pl_CAN | pl_UDP_IN, tr_GroupTransition921))
		{
			if (UDP_IN_flag)
			{
				const CAN_UDP_MESSAGE &m = UDP_IN;
				UDP_IN_flag = false;
				;
				CAN_MESSAGE _N__4366 = udp2can(m);
				CAN.add((void *)&_N__4366);
				res = true;
			};
			unlock(pl_CAN | pl_UDP_IN);
			if (res)
			{
				UnnamedTransition16();
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
				if ((cm.field1 == 0 || cm.field1 == 10) && cm.field3.at(0) == 0xB)
				{
					CAN_IN_flag = false;
					;
					u16 _N__4378[] = { (USHORT)1, 0 };
					UDP_SEND(CAN_MESSAGE(0x30, time64(), bytes4((u8 *)_N__4378)));
					ResetTime = 1;
					ResetTime_time = time() + 10000;
					tran_ena(tr_UnnamedTransition3);
					res = true;
				}
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN_IN);
		}
		return res;
	}

	bool tran_DPS()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_STEP | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS, tr_tran_DPS))
		{
			int st = STEP;
			const bytes8 &ssi = SSI.exec_ret<bytes8>();
			int n = SYNC;
			bool dir = DPS;
			;
			SYNC = n + st;
			UDP_SEND(CAN_MESSAGE(0x297, time64(), get_ssi_bytes.exec_ret<bytesn, int, bool, int, const bytes &>(n, dir, 1, ssi)));
			SYNC_BUF(1);
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_STEP | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
		}
		return res;
	}

	bool UnnamedTransition4()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_DEBUG_TIMER | pl_SEND_DEBUG, tr_UnnamedTransition4))
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

	bool UnnamedTransition7()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BatLevel | pl_BinTimer | pl_BUTTONS, tr_UnnamedTransition7))
		{
			if (BatLevel_flag)
			{
				u8 bt = BatLevel.field1;
				int n = BatLevel.field2;
				int inp = BUTTONS;
				BatLevel_flag = false;
				;

				BinTimer_time = time() + 1000000;
				s16 _N__4386[] = { (SHORT)bt, n };
				UDP_AND_CAN_SEND(CAN_MESSAGE(0x150, time64(), bytes4((u8 *)_N__4386)));
				u8 _N__4387[] = { (BYTE)1, inp };
				UDP_AND_CAN_SEND(CAN_MESSAGE(0x2D1, time64(), bytes2((u8 *)_N__4387)));
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BatLevel | pl_BinTimer | pl_BUTTONS);
		}
		return res;
	}

	bool UnnamedTransition8()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_TempTimer | pl_TEMP, tr_UnnamedTransition8))
		{
			int n = TEMP.exec_ret<int>();
			;

			TempTimer_time = time();
			UDP_AND_CAN_SEND(CAN_MESSAGE(0x2D1, time64(), IntToList(0x33 + n * 256, 3)));
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_TempTimer | pl_TEMP);
		}
		return res;
	}

	bool UnnamedTransition9()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_UDP_IN, tr_GroupTransition921))
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

	bool UnnamedTransition10()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_DELAY, tr_UnnamedTransition10))
		{
			;

			DELAY_time = time();
			SEND_SENS(1);
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_DELAY);
		}
		return res;
	}

	bool UnnamedTransition11()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BUTTONS, tr_UnnamedTransition11))
		{
			u8 bt = BUTTONS;
			;
			UDP_AND_CAN_SEND(bt2can_message(bt));
			tran_ena(tr_UnnamedTransition11);
			res = true;;
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN | pl_CAN_OUT | pl_BUTTONS);
		}
		return res;
	}

	bool UnnamedTransition12()
	{
		bool res = false;
		if (lock(pl_ADC_SUM | pl_TIMER | pl_ADC, tr_UnnamedTransition12))
		{
			if (ADC_SUM_flag)
			{
				int sum = ADC_SUM.field1;
				int n = ADC_SUM.field2;
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
				UnnamedTransition13();
			}
		}
		return res;
	}

	bool UnnamedTransition13()
	{
		bool res = false;
		if (lock(pl_BatLevel | pl_ADC_SUM, tr_UnnamedTransition13))
		{
			if (ADC_SUM_flag)
			{
				int sum = ADC_SUM.field1;
				int n = ADC_SUM.field2;
				if (n >= 10)
				{
					ADC_SUM_flag = false;
					;
					BatLevel = adc2bat.exec_ret<tuple2<int, int>, int >(sum / n);
					BatLevel_flag = true;
					ADC_SUM = INTxINT(0, 0);
					ADC_SUM_flag = true;
					tran_ena(tr_UnnamedTransition13);
					res = true;
				}
			};
			unlock(pl_BatLevel | pl_ADC_SUM);
			if (res)
			{
				UnnamedTransition13();
			}
		}
		return res;
	}

	bool UnnamedTransition16()
	{
		bool res = false;
		if (lock(pl_CAN_OUT | pl_CAN, tr_UnnamedTransition16))
		{
			const CAN_MESSAGE *res_cm;
			if (CAN.have_tokens())
			{
				const CAN_MESSAGE &cm = *(CAN_MESSAGE *)CAN.peek();
				res_cm = &cm;

				CAN.get();
				;
				bool in = CAN_OUT.exec_ret<bool, const CAN_MESSAGE &>(cm);
				tran_ena(tr_UnnamedTransition16);
				res = in;
			};
			unlock(pl_CAN_OUT | pl_CAN);
			if (res)
			{
				UnnamedTransition17(*res_cm);
			}
		}
		return res;
	}

	void UnnamedTransition17(const CAN_MESSAGE &cm)
	{
		;
		CAN.add((void *)&cm);
	}

	bool UnnamedTransition18()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_ControlCheck, tr_UnnamedTransition18))
		{
			if (ControlCheck_flag)
			{
				const CONTROL_MSG &cnm = ControlCheck.field1;
				bool ok = ControlCheck.field2;
				if (ok)
				{
					ControlCheck_flag = false;
					;
					UDP_SEND(control2can(cnm));
					tran_ena(tr_UnnamedTransition18);
					res = true;
				}
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_ControlCheck);
		}
		return res;
	}

	bool UnnamedTransition19()
	{
		bool res = false;
		if (lock(pl_SyncFreq | pl_DPS, tr_UnnamedTransition19))
		{
			if (SyncFreq)
			{
				int freq = SyncFreq;
				SyncFreq = 0;
				;

				SyncFreq_time = time() + (1000000 / freq);
				res = true;
			};
			unlock(pl_SyncFreq | pl_DPS);
			if (res)
			{
				tran_DPS();
			}
		}
		return res;
	}

	bool UnnamedTransition20()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_Init, tr_UnnamedTransition20))
		{
			if (Init)
			{
				Init = 0;
				;
				u16 _N__4393[] = { (USHORT)2, 0x100 };
				UDP_SEND(CAN_MESSAGE(0x30, time64(), bytes4((u8 *)_N__4393)));
				u16 _N__4394[] = { (USHORT)0, 0 };
				UDP_SEND(CAN_MESSAGE(0x30, time64(), bytes4((u8 *)_N__4394)));
				tran_ena(tr_UnnamedTransition20);
				res = true;
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_Init);
		}
		return res;
	}

	bool UnnamedTransition21()
	{
		bool res = false;
		if (lock(pl_GPSLED | pl_GPSLEDCntr, tr_UnnamedTransition21))
		{
			if (GPSLED)
			{
				int n = GPSLEDCntr;
				if (n == 10)
				{
					GPSLED = 0;
					GPS_LED_Toggle.exec();
					GPSLEDCntr = 0;
					tran_ena(tr_UnnamedTransition21);
					res = true;
				}
			};
			unlock(pl_GPSLED | pl_GPSLEDCntr);
			if (res)
			{
				UnnamedTransition21();
				UnnamedTransition22();
			}
		}
		return res;
	}

	bool UnnamedTransition22()
	{
		bool res = false;
		if (lock(pl_GPSLED | pl_GPSLEDCntr, tr_UnnamedTransition22))
		{
			if (GPSLED)
			{
				int n = GPSLEDCntr;
				if (n < 10)
				{
					GPSLED = 0;
					;
					GPSLEDCntr = n + 1;
					tran_ena(tr_UnnamedTransition22);
					res = true;
				}
			};
			unlock(pl_GPSLED | pl_GPSLEDCntr);
			if (res)
			{
				UnnamedTransition21();
				UnnamedTransition22();
			}
		}
		return res;
	}

	bool UnnamedTransition23()
	{
		bool res = false;
		if (lock(pl_SYNCLED | pl_SYNCLEDCntr, tr_UnnamedTransition23))
		{
			if (SYNCLED)
			{
				int n = SYNCLEDCntr;
				if (n == 30)
				{
					SYNCLED = 0;
					LED_Toggle.exec();
					SYNCLEDCntr = 0;
					tran_ena(tr_UnnamedTransition23);
					res = true;
				}
			};
			unlock(pl_SYNCLED | pl_SYNCLEDCntr);
			if (res)
			{
				UnnamedTransition23();
				UnnamedTransition24();
			}
		}
		return res;
	}

	bool UnnamedTransition24()
	{
		bool res = false;
		if (lock(pl_SYNCLED | pl_SYNCLEDCntr, tr_UnnamedTransition24))
		{
			if (SYNCLED)
			{
				int n = SYNCLEDCntr;
				if (n < 30)
				{
					SYNCLED = 0;
					;
					SYNCLEDCntr = n + 1;
					tran_ena(tr_UnnamedTransition24);
					res = true;
				}
			};
			unlock(pl_SYNCLED | pl_SYNCLEDCntr);
			if (res)
			{
				UnnamedTransition23();
				UnnamedTransition24();
			}
		}
		return res;
	}

	bool UnnamedTransition25()
	{
		bool res = false;
		if (lock(pl_COUNTER | pl_UDP_OUT | pl_CAN_IN, tr_UnnamedTransition25))
		{
			if (CAN_IN_flag)
			{
				const CAN_MESSAGE &cm = CAN_IN;
				if (cm.field1 == 0x208)
				{
					CAN_IN_flag = false;
					;
					SEND_SENS(1);
					tran_ena(tr_UnnamedTransition25);
					res = true;
				}
			};
			unlock(pl_COUNTER | pl_UDP_OUT | pl_CAN_IN);
		}
		return res;
	}

	bool UnnamedTransition26()
	{
		bool res = false;
		if (lock(pl_ResetTime, tr_UnnamedTransition26))
		{
			if (ResetTime)
			{
				ResetTime = 0;
				do_reset.exec();
				res = true;
			};
			unlock(pl_ResetTime);
		}
		return res;
	}

	CAN_MESSAGE  control2can(const CONTROL_MSG &m)
	{
		return CAN_MESSAGE(0x50, time64(), bytesn((void *)&m, sizeof(m)));
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
		u8 _N__4405[] = { (BYTE)1, bt };

		return CAN_MESSAGE(0x2D1, time(), bytes2((u8 *)_N__4405));
	}

	bool is_sens(const CAN_UDP_MESSAGE &m)
	{
		return m.ID == 0x297;
	}

	bool is_control(const CAN_UDP_MESSAGE &m)
	{
		return m.ID == 0x50;
	}

	u32 get_next_time(u32 &res_tr)
	{
		u32 tr = 0;

		u32 min = 0xFFFFFFFF, time;
		time = DELAY_time + 200000;
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
			tr = tr_UnnamedTransition19;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition19;
			}
		time = TempTimer_time + 500000;
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
			}
		time = ResetTime_time;
		if (min > time)
		{
			min = time;
			tr = tr_UnnamedTransition26;
		}
		else
			if (min == time)
			{
				tr |= tr_UnnamedTransition26;
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

	void init_adc2bat(tuple2<int, int>(*func)(int))
	{
		adc2bat = function(func);
	}

	template <class T>
	void init_adc2bat(T *obj, tuple2<int, int>(T::*func)(T *obj, int))
	{
		adc2bat = function(obj, func);
	}

	void init_get_ssi_bytes(bytesn(*func)(int, bool, int, const bytes &))
	{
		get_ssi_bytes = function(func);
	}

	template <class T>
	void init_get_ssi_bytes(T *obj, bytesn(T::*func)(T *obj, int, bool, int, const bytes &))
	{
		get_ssi_bytes = function(obj, func);
	}

	void init_get_control_msg(CONTROL_MSG_BOOL(*func)(const CAN_UDP_MESSAGE &))
	{
		get_control_msg = function(func);
	}

	template <class T>
	void init_get_control_msg(T *obj, CONTROL_MSG_BOOL(T::*func)(T *obj, const CAN_UDP_MESSAGE &))
	{
		get_control_msg = function(obj, func);
	}

	void init_GPS_LED_Toggle(void(*func)())
	{
		GPS_LED_Toggle = function(func);
	}

	template <class T>
	void init_GPS_LED_Toggle(T *obj, void(T::*func)(T *obj))
	{
		GPS_LED_Toggle = function(obj, func);
	}

	void init_LED_Toggle(void(*func)())
	{
		LED_Toggle = function(func);
	}

	template <class T>
	void init_LED_Toggle(T *obj, void(T::*func)(T *obj))
	{
		LED_Toggle = function(obj, func);
	}

	void init_do_reset(void(*func)())
	{
		do_reset = function(func);
	}

	template <class T>
	void init_do_reset(T *obj, void(T::*func)(T *obj))
	{
		do_reset = function(obj, func);
	}

	pt14(int time_step = 15) : timed_petri_net32(time_step)
	{
		DPS = false;
		SYNC = 0;
		BUTTONS = 0;
		UDP_IN_flag = false;
		CAN_IN_flag = false;
		GPS_flag = false;
		SEND_DEBUG_flag = false;
		DELAY = 1;
		DELAY_time = 0;
		BinTimer = 1;
		BinTimer_time = 1000000;
		SyncFreq = 0;
		TempTimer = 1;
		TempTimer_time = 500000;
		BatLevel_flag = false;
		TIMER = 1;
		TIMER_time = 0;
		ADC_SUM = INTxINT(0, 0);
		ADC_SUM_flag = true;
		DEBUG_TIMER = 1;
		DEBUG_TIMER_time = 0;
		COUNTER = 0;
		ControlCheck_flag = false;
		STEP = 1;
		Init = 1;
		GPSLEDCntr = 0;
		GPSLED = 0;
		SYNCLEDCntr = 0;
		SYNCLED = 0;
		ResetTime = 0;
		tran_funcs[0] = &pt14::GroupTransition921;
		tran_funcs[1] = &pt14::UnnamedTransition0;
		tran_funcs[2] = &pt14::UnnamedTransition1;
		tran_funcs[3] = &pt14::UnnamedTransition2;
		tran_funcs[4] = &pt14::UnnamedTransition3;
		tran_funcs[5] = &pt14::tran_DPS;
		tran_funcs[6] = &pt14::UnnamedTransition4;
		tran_funcs[7] = &pt14::UnnamedTransition7;
		tran_funcs[8] = &pt14::UnnamedTransition8;
		tran_funcs[9] = &pt14::UnnamedTransition9;
		tran_funcs[10] = &pt14::UnnamedTransition10;
		tran_funcs[11] = &pt14::UnnamedTransition11;
		tran_funcs[12] = &pt14::UnnamedTransition12;
		tran_funcs[13] = &pt14::UnnamedTransition13;
		tran_funcs[14] = &pt14::UnnamedTransition16;
		tran_funcs[15] = &pt14::UnnamedTransition18;
		tran_funcs[16] = &pt14::UnnamedTransition19;
		tran_funcs[17] = &pt14::UnnamedTransition20;
		tran_funcs[18] = &pt14::UnnamedTransition21;
		tran_funcs[19] = &pt14::UnnamedTransition22;
		tran_funcs[20] = &pt14::UnnamedTransition23;
		tran_funcs[21] = &pt14::UnnamedTransition24;
		tran_funcs[22] = &pt14::UnnamedTransition25;
		tran_funcs[23] = &pt14::UnnamedTransition26;
		tran_ena(tr_UnnamedTransition20 | tr_UnnamedTransition13);
	}

	bool GroupTransition921()
	{
		if (!UnnamedTransition9())
			if (!UnnamedTransition1())
				if (!UnnamedTransition2())
					return false;
		tran_ena(0, tr_GroupTransition921);
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
		SYNCLED = 1;
	}

	void SEND_SENS(char param)
	{
		const bytes8 &ssi = SSI.exec_ret<bytes8>();
		int n = SYNC;
		bool dir = DPS;
		;
		UDP_SEND(CAN_MESSAGE(0x297, time64(), get_ssi_bytes.exec_ret<bytesn, int, bool, int, const bytes &>(n, dir, 0, ssi)));
	}

	void UDP_AND_CAN_SEND(const CAN_MESSAGE &cm)
	{
		;
		UDP_SEND(cm);
		CAN.add((void *)&cm);
	}

	void init_SSI(bytes8(*func)())
	{
		SSI = function(func);
	}

	template <class T>
	void init_SSI(T *obj, bytes8(T::*func)(T *obj))
	{
		SSI = function(obj, func);
	}

	void init_TEMP(int(*func)())
	{
		TEMP = function(func);
	}

	template <class T>
	void init_TEMP(T *obj, int(T::*func)(T *obj))
	{
		TEMP = function(obj, func);
	}

	void init_ADC(int(*func)())
	{
		ADC = function(func);
	}

	template <class T>
	void init_ADC(T *obj, int(T::*func)(T *obj))
	{
		ADC = function(obj, func);
	}

	function adc2bat;
	function get_ssi_bytes;
	function get_control_msg;
	function GPS_LED_Toggle;
	function LED_Toggle;
	function do_reset;


	void add_DPS(bool param)
	{
		DPS = param;
		tran_DPS();
	}

	bool  get_DPS() const
	{
		return DPS;
	}

	void add_BUTTONS(u8 param)
	{
		BUTTONS = param;
		UnnamedTransition7();
		UnnamedTransition11();
	}

	u8  get_BUTTONS() const
	{
		return BUTTONS;
	}

	void add_UDP_IN(const CAN_UDP_MESSAGE &param)
	{
		UDP_IN = param;
		UDP_IN_flag = true;
		GroupTransition921();
	}

	const CAN_UDP_MESSAGE & get_UDP_IN() const
	{
		return UDP_IN;
	}

	void add_CAN_IN(const CAN_MESSAGE &param)
	{
		CAN_IN = param;
		CAN_IN_flag = true;
		UnnamedTransition3();
		UnnamedTransition25();
	}

	const CAN_MESSAGE & get_CAN_IN() const
	{
		return CAN_IN;
	}

	void add_GPS(const bytesn &param)
	{
		GPS = param;
		GPS_flag = true;
		UnnamedTransition0();
	}

	const bytesn & get_GPS() const
	{
		return GPS;
	}

	void add_SEND_DEBUG(const bytesn &param)
	{
		SEND_DEBUG = param;
		SEND_DEBUG_flag = true;
		UnnamedTransition4();
	}

	const bytesn & get_SEND_DEBUG() const
	{
		return SEND_DEBUG;
	}

	void add_SyncFreq(int param)
	{
		SyncFreq = param;
		SyncFreq_time = time();
		UnnamedTransition19();
	}

	int  get_SyncFreq() const
	{
		return SyncFreq;
	}

	void add_STEP(int param)
	{
		STEP = param;

	}

	int  get_STEP() const
	{
		return STEP;
	}

	void init_CAN_OUT(bool(*func)(const CAN_MESSAGE &))
	{
		CAN_OUT = function(func);
	}

	template <class T>
	void init_CAN_OUT(T *obj, bool(T::*func)(T *obj, const CAN_MESSAGE &))
	{
		CAN_OUT = function(obj, func);
	}

	void init_UDP_OUT(void(*func)(const CAN_UDP_MESSAGE &))
	{
		UDP_OUT = function(func);
	}

	template <class T>
	void init_UDP_OUT(T *obj, void(T::*func)(T *obj, const CAN_UDP_MESSAGE &))
	{
		UDP_OUT = function(obj, func);
	}

};
