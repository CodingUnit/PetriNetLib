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

typedef u32 UINT;

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

                                                          bytesn get_bytes() const
                                                          {
                                                            return bytesn((void *)&field1, sizeof(field2) + sizeof(field1));;
                                                            //return bytes_ptr(&field1, sizeof(TSYNC));
                                                          }

                                                          /*void operator=(const tuple2<int, bool> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
                                                          }*/
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

                                                          bytesn get_bytes() const
                                                          {
                                                            return bytesn((void *)&field1, sizeof(field2) + sizeof(field1));;
                                                            //return bytes_ptr(&field1, sizeof(INTxINT));
                                                          }

                                                          /*void operator=(const tuple2<int, int> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
                                                          }*/
                                                        };

typedef INT TIMED_INT;

typedef u16 USHORT;

typedef bytesn BYTES;

typedef bytes8 BYTES8;

typedef bytes3 BYTES3;

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

                                                          bytesn get_bytes() const
                                                          {
                                                            bytesn res;
          res += field1;
          res += bytesn((void *)&field2, sizeof(field2));
          return res;
                                                            //return bytes_ptr(&field1, sizeof(BYTES_BOOL));
                                                          }

                                                          /*void operator=(const tuple2<bytesn, bool> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
                                                          }*/
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

                                                          CAN_MESSAGE(const tuple3<int, long long, bytesn> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
field3 = tup.field3;
                                                          }

                                                          int field1;
long long field2;
bytesn field3;

                                                          bytesn get_bytes() const
                                                          {
                                                            bytesn res;
          res += bytesn((void *)&field1, sizeof(field2) + sizeof(field1));
          res += field3;
          return res;
                                                            //return bytes_ptr(&field1, sizeof(CAN_MESSAGE));
                                                          }

                                                          /*void operator=(const tuple3<int, long long, bytesn> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
field3 = tup.field3;
                                                          }*/
                                                        };

struct CAN_MESSAGE_BOOL
                                                        {
                                                          CAN_MESSAGE_BOOL() {}
                                                          CAN_MESSAGE_BOOL(bool field1, const CAN_MESSAGE &field2) 
                                                          {
                                                            this->field1 = field1;
this->field2 = field2;
                                                          }

                                                          CAN_MESSAGE_BOOL(const tuple2<bool, CAN_MESSAGE> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
                                                          }

                                                          bool field1;
CAN_MESSAGE field2;

                                                          bytesn get_bytes() const
                                                          {
                                                            bytesn res;
          res += bytesn((void *)&field1, sizeof(field1));
          res += field2.get_bytes();
          return res;
                                                            //return bytes_ptr(&field1, sizeof(CAN_MESSAGE_BOOL));
                                                          }

                                                          /*void operator=(const tuple2<bool, CAN_MESSAGE> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
                                                          }*/
                                                        };

typedef UNIT TIMED_VOID;

struct CAN_UDP_MESSAGE
                                                        {
                                                          CAN_UDP_MESSAGE() {}
                                                          CAN_UDP_MESSAGE(const bytes &head, u16 COUNT, u16 ID, long long timestamp, u8 len, const bytes &data) 
                                                          {
                                                            this->head = head;
this->COUNT = COUNT;
this->ID = ID;
this->timestamp = timestamp;
this->len = len;
this->data = data;
                                                          }

                                                          bytesn get_bytes() const
                                                          {
                                                            bytesn res;
          res += head;
          res += bytesn((void *)&COUNT, sizeof(len) + sizeof(timestamp) + sizeof(ID) + sizeof(COUNT));
          res += data;
          return res;
                                                          }
                                                          bytes3 head;
u16 COUNT;
u16 ID;
long long timestamp;
u8 len;
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

                                                          bytesn get_bytes() const
                                                          {
                                                            return bytesn((void *)&field1, sizeof(field3) + sizeof(field2) + sizeof(field1));;
                                                            //return bytes_ptr(&field1, sizeof(CONTROL_MSG));
                                                          }

                                                          /*void operator=(const tuple3<u8, u16, u32> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
field3 = tup.field3;
                                                          }*/
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

                                                          bytesn get_bytes() const
                                                          {
                                                            bytesn res;
          res += field1.get_bytes();
          res += bytesn((void *)&field2, sizeof(field2));
          return res;
                                                            //return bytes_ptr(&field1, sizeof(CONTROL_MSG_BOOL));
                                                          }

                                                          /*void operator=(const tuple2<CONTROL_MSG, bool> &tup)
                                                          {
                                                            field1 = tup.field1;
field2 = tup.field2;
                                                          }*/
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
pl_CAN = 0x80000,
pl_UDP_OUT = 0x100000,
pl_ControlCheck = 0x200000,
pl_STEP = 0x400000,
pl_Init = 0x800000,
pl_GPSLEDCntr = 0x1000000,
pl_GPSLED = 0x2000000,
pl_SYNCLEDCntr = 0x4000000,
pl_SYNCLED = 0x8000000,
pl_ResetTime = 0x10000000,
pl_CAN_SEND = 0x20000000
         } tplace;
bool DPS;
u32 SYNC;
bytesn (*SSI)();
short (*TEMP)();
u8 BUTTONS;
CAN_UDP_MESSAGE UDP_IN;
bool UDP_IN_flag;
CAN_MESSAGE CAN_IN;
bool CAN_IN_flag;
bytesn GPS;
bool GPS_flag;
bytesn (*SEND_DEBUG)();
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
int (*ADC)();
char TIMER;
u32 TIMER_time;
INTxINT ADC_SUM;
char DEBUG_TIMER;
u32 DEBUG_TIMER_time;
u16 COUNTER;
token_queue CAN;
CONTROL_MSG ControlCheck;
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
random_array CAN_SEND;


typedef u32 (pt14::*tran_func_type)();

      typedef enum 
      {
        res_ok = 1,
        tr_GroupTransition721 = 0x2,
tr_GroupTransition27262522 = 0x4,
tr_GroupTransition1716 = 0x8,
tr_GroupTransition1918 = 0x10,
tr_UnnamedTransition0 = 0x20,
tr_tran_DPS = 0x40,
tr_UnnamedTransition3 = 0x80,
tr_UnnamedTransition5 = 0x100,
tr_UnnamedTransition6 = 0x200,
tr_UnnamedTransition8 = 0x400,
tr_UnnamedTransition9 = 0x800,
tr_UnnamedTransition10 = 0x1000,
tr_UnnamedTransition14 = 0x2000,
tr_UnnamedTransition15 = 0x4000,
tr_UnnamedTransition21 = 0x8000,
tr_UnnamedTransition29 = 0x10000,
tr_UnnamedTransition30 = 0x20000,
tr_UnnamedTransition31 = 0x40000,
tr_UnnamedTransition32 = 0x80000
      } ttran;
const tran_func_type *tran_funcs;
      
u32 can_repeat(u32 tr) const
      {
        bool can_rep = tran_can_repeat & tr;
        return tr * can_rep;
      }
      
const tplace *tran_lock;
      
static const u32 tran_can_repeat = 935998;
      
static const int P_LOW = 10000;
static const int P_NORMAL = 1000;
static const int P_HIGH = 100;


void (*UDP_OUT)(const CAN_UDP_MESSAGE &);

        u32 GroupTransition721()
            {
              if (UDP_IN_flag)
                    {
                      const CAN_UDP_MESSAGE &m = UDP_IN; 
UDP_IN_flag = false;
if (m.ID == 0x50) 
                    {
                      ControlCheck = (*(CONTROL_MSG  *)m.data.get_buf());
                                          ControlCheck_flag = true;
return 0;
                    }
if (m.ID == 0x297) 
                    {
                      SEND_SENS(1);
return 0;
                    }
CAN_MESSAGE _N__4353 = udp2can(m);
                                              CAN_SEND.add((void *)&_N__4353);
return tr_UnnamedTransition31;
                    }
                    return 0;
            }

        u32 GroupTransition27262522()
            {
              if (ControlCheck_flag)
                    {
                      const CONTROL_MSG &cnm = ControlCheck; 
ControlCheck_flag = false;
if (cnm.field1 == 0) 
                    {
                      CONTROL_MSG _N__4354 = CONTROL_MSG(0,0,0);
      UDP_SEND(CAN_MESSAGE(0x50,time64(),_N__4354.get_bytes()));
RESET(1);
return 0;
                    }
if (cnm.field1 == 1) 
                    {
                      int  n = set_param(cnm.field2,cnm.field3);
CONTROL_MSG _N__4355 = CONTROL_MSG(1,cnm.field2,n);
      UDP_SEND(CAN_MESSAGE(0x50,time64(),_N__4355.get_bytes()));
return 0;
                    }
if (cnm.field1 == 2) 
                    {
                      int  n = read_param(cnm.field2);
CONTROL_MSG _N__4356 = CONTROL_MSG(1,cnm.field2,n);
      UDP_SEND(CAN_MESSAGE(0x50,time64(),_N__4356.get_bytes()));
return 0;
                    }
if (cnm.field1 == 3) 
                    {
                      flash_reset();
CONTROL_MSG _N__4357 = CONTROL_MSG(3,0,0);
      UDP_SEND(CAN_MESSAGE(0x50,time64(),_N__4357.get_bytes()));
return 0;
                    }
                    }
                    return 0;
            }

        u32 GroupTransition1716()
            {
              if (GPSLED)
                  {
                    int n = GPSLEDCntr; 
GPSLED = 0;
if (n == 10) 
                    {
                      GPS_LED_Toggle();
GPSLEDCntr = 0;
return 0;
                    }
if (n < 10) 
                    {
                      GPSLEDCntr = n + 1;
return 0;
                    }
                  }
                  return 0;
            }

        u32 GroupTransition1918()
            {
              if (SYNCLED)
                  {
                    int n = SYNCLEDCntr; 
SYNCLED = 0;
if (n == 30) 
                    {
                      LED_Toggle();
SYNCLEDCntr = 0;
return 0;
                    }
if (n < 30) 
                    {
                      SYNCLEDCntr = n + 1;
return 0;
                    }
                  }
                  return 0;
            }

        u32 UnnamedTransition0()
            {
               if (GPS_flag)
                {
                  const bytesn &s = GPS; 
GPS_flag = false;
UDP_SEND(CAN_MESSAGE(0x100,time64(),s));
GPSLED = 1;
return 1;
                }
       return 0;
       ;
                                 
            }

        u32 tran_DPS()
            {
              int st = STEP; 
const bytesn &ssi = SSI(); 
int n = SYNC; 
bool dir = DPS; 
SYNC = n + st;
UDP_SEND(CAN_MESSAGE(0x297,time64(),get_ssi_bytes(n,dir,1,ssi)));
DELAY = 1;
DELAY_time = time();
SYNCLED = 1;
return 1;;
                                 
            }

        u32 UnnamedTransition3()
            {
              const bytesn &d = SEND_DEBUG(); 
UDP_SEND(CAN_MESSAGE(0,time64(),d));

DEBUG_TIMER_time = time() + 333000;
return 1;;
                                 
            }

        u32 UnnamedTransition5()
            {
               if (BatLevel_flag)
              {
                u8 bt = BatLevel.field1;
int n = BatLevel.field2;
int inp = BUTTONS; 
BatLevel_flag = false;

BinTimer_time = time() + 1000000;
s16 _N__4385[] = {(SHORT)bt, n};
      UDP_AND_CAN_SEND(CAN_MESSAGE(0x150,time64(),bytes4((u8 *)_N__4385)));
u8 _N__4386[] = {(BYTE)1, inp};
      UDP_AND_CAN_SEND(CAN_MESSAGE(0x2D1,time64(),bytes2((u8 *)_N__4386)));
return 1;
              }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition6()
            {
              int n = TEMP(); 

TempTimer_time = time();
UDP_AND_CAN_SEND(CAN_MESSAGE(0x2D1,time64(),IntToList(33 + n * 256,3)));
return 1;;
                                 
            }

        u32 UnnamedTransition8()
            {
              
DELAY_time = time();
SEND_SENS(1);
return 1;;
                                 
            }

        u32 UnnamedTransition9()
            {
              u8 bt = BUTTONS; 
UDP_AND_CAN_SEND(bt2can_message(bt));
return 1;;
                                 
            }

        u32 UnnamedTransition10()
            {
              int sum = ADC_SUM.field1;
int n = ADC_SUM.field2;
int q = ADC(); 
if (n < 10) 
                    {
                      
TIMER_time = time() + 50000;
ADC_SUM = INTxINT(sum + q,n + 1);
return 1;
                    }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition14()
            {
               if (SyncFreq)
              {
                int freq = SyncFreq; 
SyncFreq = 0;

SyncFreq_time = time() + (1000000 / freq);
return tr_tran_DPS;
              }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition15()
            {
               if (Init)
                {
                  Init = 0;
u16 _N__4387[] = {(USHORT)2, 0x100};
      UDP_SEND(CAN_MESSAGE(0x30,time64(),bytes4((u8 *)_N__4387)));
u16 _N__4388[] = {(USHORT)0, 0};
      UDP_SEND(CAN_MESSAGE(0x30,time64(),bytes4((u8 *)_N__4388)));
return 1;
                }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition21()
            {
               if (ResetTime)
                {
                  ResetTime = 0;
do_reset();
return 1;
                }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition29()
            {
              int sum = ADC_SUM.field1;
int n = ADC_SUM.field2;
int q = ADC(); 
if (n >= 10) 
                    {
                      BatLevel = adc2bat((sum + q) / n);
                                          BatLevel_flag = true;

TIMER_time = time() + 50000;
ADC_SUM = INTxINT(0,0);
return 1;
                    }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition30()
            {
               if (CAN_IN_flag)
                {
                  const CAN_MESSAGE &cm = CAN_IN; 
CAN_IN_flag = false;
UDP_SEND(cm);
CAN_PROCESS(cm);
return 1;
                }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition31()
            {
               if (CAN_SEND.have_tokens())
                {
                   int cm_idx;
                                          const CAN_MESSAGE &cm = CAN_SEND.peek_indexed(cm_idx);
CAN_SEND.get_indexed(cm_idx);
CAN_OUT(CAN_MESSAGE_BOOL(can_send(cm),cm));
return 1;
                }
       return 0;
       ;
                                 
            }

        u32 UnnamedTransition32()
            {
               if (CAN.have_tokens())
                {
                  const CAN_MESSAGE &cm = *(CAN_MESSAGE *)CAN.peek(); 
CAN.get();
CAN_SEND.add((void *)&cm);
return tr_UnnamedTransition31;
                }
       return 0;
       ;
                                 
            }
CAN_MESSAGE  control2can(const CONTROL_MSG &m)
          {
            return CAN_MESSAGE (0x50,time64(),m.get_bytes());
          }
          
CAN_UDP_MESSAGE  can2udp(const CAN_MESSAGE &m,int c)
          {u8 _N__4404[] = {(BYTE)0x55, 0x55, 3};
        
            return CAN_UDP_MESSAGE (bytes3((u8 *)_N__4404),c,m.field1,m.field2,m.field3.get_count(),m.field3);
          }
          
CAN_MESSAGE  udp2can(const CAN_UDP_MESSAGE &m)
          {
            return CAN_MESSAGE (m.ID,m.timestamp,m.data);
          }
          
CAN_MESSAGE  bt2can_message(int bt)
          {u8 _N__4405[] = {(BYTE)1, bt};
        
            return CAN_MESSAGE (0x2D1,time(),bytes2((u8 *)_N__4405));
          }
          
tuple2<int,int> (*adc2bat)(int );
bytesn (*get_ssi_bytes)(int ,bool ,int ,const bytes &);
void (*GPS_LED_Toggle)();
void (*LED_Toggle)();
void (*do_reset)();
UINT  (*read_param)(u16 );
bool (*can_send)(const CAN_MESSAGE &);
void (*flash_reset)();
UINT  (*set_param)(u16 ,u32 );
u32 get_next_time(u32 &res_tr)
                      {
                        u32 tr = 0;
                        
                                  u32 min = 0xFFFFFFFF;
                                  min = calc_min_time(DELAY_time + 200000, min, tr_UnnamedTransition8, tr);
min = calc_min_time(BinTimer_time, min, tr_UnnamedTransition5, tr);
if (SyncFreq != 0)
          {
            min = calc_min_time(SyncFreq_time, min, tr_UnnamedTransition14, tr);
          }
          
min = calc_min_time(TempTimer_time + 500000, min, tr_UnnamedTransition6, tr);
min = calc_min_time(TIMER_time, min, tr_UnnamedTransition10 | tr_UnnamedTransition29, tr);
min = calc_min_time(DEBUG_TIMER_time, min, tr_UnnamedTransition3, tr);
if (ResetTime_flag)
          {
            min = calc_min_time(ResetTime_time + 10000, min, tr_UnnamedTransition21, tr);
          }
          ;
                              ;
                        res_tr = tr;
                        return min;
                      }

              protected:
                      
      tran_func get_transition(int n) const
	    {
		    return *(tran_func *)&tran_funcs[n];
	    }
      
void transition(u32 tr_mask)
		{
			u32 tr = LSB(tr_mask) - 1;
			tran_func_type tran = tran_funcs[tr];
			u32 lock_places = tran_lock[tr];
			if (lock(lock_places, tr_mask))
			{
			  u32 next = (this->*tran)();
			  if (next)
				  tran_ena(next, can_repeat(tr_mask));
				unlock(lock_places);
			}
		}
              public:

              void init_adc2bat(tuple2<int,int>(*func)(int ))
          {
            adc2bat = func;
          }
         
          
void init_get_ssi_bytes(bytesn(*func)(int ,bool ,int ,const bytes &))
          {
            get_ssi_bytes = func;
          }
         
          
void init_GPS_LED_Toggle(void(*func)())
          {
            GPS_LED_Toggle = func;
          }
         
          
void init_LED_Toggle(void(*func)())
          {
            LED_Toggle = func;
          }
         
          
void init_do_reset(void(*func)())
          {
            do_reset = func;
          }
         
          
void init_read_param(UINT (*func)(u16 ))
          {
            read_param = func;
          }
         
          
void init_can_send(bool(*func)(const CAN_MESSAGE &))
          {
            can_send = func;
          }
         
          
void init_flash_reset(void(*func)())
          {
            flash_reset = func;
          }
         
          
void init_set_param(UINT (*func)(u16 ,u32 ))
          {
            set_param = func;
          }
         
          
pt14(int time_step = 15) : timed_petri_net32(time_step)
      {
        UDP_SEND.init(32, sizeof(CAN_MESSAGE));
UDP_AND_CAN_SEND.init(32, sizeof(CAN_MESSAGE));
CAN_OUT.init(32, sizeof(CAN_MESSAGE_BOOL));
CAN.init(8, sizeof(CAN_MESSAGE));
UDP_OUT.init(32, sizeof(CAN_UDP_MESSAGE));
RESET.init(32, sizeof(char));
CAN_PROCESS.init(32, sizeof(CAN_MESSAGE));
CAN_SEND.init(32, sizeof(CAN_MESSAGE));
        DPS = false;
SYNC = 0;
BUTTONS = 0;
UDP_IN_flag = false;
CAN_IN_flag = false;
GPS_flag = false;
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
ADC_SUM = INTxINT(0,0);
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
        static const tran_func_type tr_funcs[] = {&pt14::GroupTransition721,
&pt14::GroupTransition27262522,
&pt14::GroupTransition1716,
&pt14::GroupTransition1918,
&pt14::UnnamedTransition0,
&pt14::tran_DPS,
&pt14::UnnamedTransition3,
&pt14::UnnamedTransition5,
&pt14::UnnamedTransition6,
&pt14::UnnamedTransition8,
&pt14::UnnamedTransition9,
&pt14::UnnamedTransition10,
&pt14::UnnamedTransition14,
&pt14::UnnamedTransition15,
&pt14::UnnamedTransition21,
&pt14::UnnamedTransition29,
&pt14::UnnamedTransition30,
&pt14::UnnamedTransition31,
&pt14::UnnamedTransition32};
                   tran_funcs = tr_funcs; 
                  
static const tplace tr_lock[] = {(tplace)(pl_COUNTER | pl_UDP_OUT | pl_UDP_IN),
(tplace)(pl_ResetTime | pl_COUNTER | pl_UDP_OUT | pl_ControlCheck),
(tplace)(pl_GPSLED | pl_GPSLEDCntr),
(tplace)(pl_SYNCLED | pl_SYNCLEDCntr),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_GPS),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_STEP | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_DEBUG_TIMER | pl_SEND_DEBUG),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_CAN_SEND | pl_CAN | pl_BatLevel | pl_BinTimer | pl_BUTTONS),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_CAN_SEND | pl_CAN | pl_TempTimer | pl_TEMP),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_DELAY),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_CAN_SEND | pl_CAN | pl_BUTTONS),
(tplace)(pl_ADC_SUM | pl_TIMER | pl_ADC),
(tplace)(pl_SyncFreq | pl_DPS),
(tplace)(pl_COUNTER | pl_UDP_OUT | pl_Init),
(tplace)(pl_ResetTime),
(tplace)(pl_BatLevel | pl_ADC_SUM | pl_TIMER | pl_ADC),
(tplace)(pl_ResetTime | pl_COUNTER | pl_UDP_OUT | pl_CAN_IN),
(tplace)(pl_CAN | pl_CAN_SEND),
(tplace)(pl_CAN_SEND | pl_CAN)};
                         tran_lock = tr_lock;
                       
tran_ena(tr_UnnamedTransition15);
      }
void UDP_SEND(const CAN_MESSAGE &cm)
      {
        int n = COUNTER; 
COUNTER = n + 1;
UDP_OUT(can2udp(cm,n));;
                                 
      }
      
void SEND_SENS(char param)
      {
        const bytesn &ssi = SSI(); 
int n = SYNC; 
bool dir = DPS; 
UDP_SEND(CAN_MESSAGE(0x297,time64(),get_ssi_bytes(n,dir,0,ssi)));;
                                 
      }
      
void UDP_AND_CAN_SEND(const CAN_MESSAGE &cm)
      {
        UDP_SEND(cm);
CAN_SEND.add((void *)&cm);;
                                 
      }
      
void CAN_OUT(const CAN_MESSAGE_BOOL &param)
      {
        if (!res) 
                    {
                      CAN.add((void *)&cm);
return ;
                    }
if (res) 
                    {
                      return ;
                    }
      }
      
void RESET(char param)
      {
        u16 _N__4403[] = {(USHORT)1, 0};
      UDP_SEND(CAN_MESSAGE(0x30,time64(),bytes4((u8 *)_N__4403)));
ResetTime = 1;
ResetTime_time = time();;
                                 
      }
      
void CAN_PROCESS(const CAN_MESSAGE &cm)
      {
        if (cm.field1 == 0x208) 
                    {
                      SEND_SENS(1);
return ;
                    }
if ((cm.field1 == 0 || cm.field1 == 10) && cm.field3.at(0) == 0xB) 
                    {
                      RESET(1);
return ;
                    }
      }
      
void init_SSI(bytesn(*func)())
          {
            SSI = func;
          }
         
          
void init_TEMP(short(*func)())
          {
            TEMP = func;
          }
         
          
void init_SEND_DEBUG(bytesn(*func)())
          {
            SEND_DEBUG = func;
          }
         
          
void init_ADC(int(*func)())
          {
            ADC = func;
          }
         
          


void add_DPS(bool param)
      {
        DPS = param;
        run_transitions(tr_tran_DPS);
      }

      bool  get_DPS() const
      {
        return DPS;
      }
      
void add_BUTTONS(u8 param)
      {
        BUTTONS = param;
        run_transitions(tr_UnnamedTransition9);
      }

      u8  get_BUTTONS() const
      {
        return BUTTONS;
      }
      
void add_UDP_IN(const CAN_UDP_MESSAGE &param)
      {
        UDP_IN = param;
                              UDP_IN_flag = true;
        run_transitions(tr_GroupTransition721);
      }

      const CAN_UDP_MESSAGE & get_UDP_IN() const
      {
        return UDP_IN;
      }
      
void add_CAN_IN(const CAN_MESSAGE &param)
      {
        CAN_IN = param;
                              CAN_IN_flag = true;
        run_transitions(tr_UnnamedTransition30);
      }

      const CAN_MESSAGE & get_CAN_IN() const
      {
        return CAN_IN;
      }
      
void add_GPS(const bytesn &param)
      {
        GPS = param;
                              GPS_flag = true;
        run_transitions(tr_UnnamedTransition0);
      }

      const bytesn & get_GPS() const
      {
        return GPS;
      }
      
void add_SyncFreq(int param)
      {
        SyncFreq = param;
SyncFreq_time = time();
        
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
      
void init_UDP_OUT(void(*func)(const CAN_UDP_MESSAGE &))
          {
            UDP_OUT = func;
          }
         
          
            };
        