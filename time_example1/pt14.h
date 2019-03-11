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
pl_SEND_SENS = 0x80,
pl_ADC = 0x100,
pl_TIMER = 0x200,
pl_ADC_SUM = 0x400,
pl_DEBUG_TIMER = 0x800,
pl_UDP_OUT = 0x1000,
pl_COUNTER = 0x2000,
pl_CAN_OUT = 0x4000
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

typedef INT ZEROSINGLE__TIMED_INT;

typedef INT USHORT;





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

int get_next_time()
                      {
                        
                                  int min = 0xFFFFFFFF;
                                  min = math_utils::min(min, DELAY.NextTokenDelay); 
min = math_utils::min(min, BinTimer.NextTokenDelay); 
min = math_utils::min(min, SyncFreq.NextTokenDelay); 
min = math_utils::min(min, TempTimer.NextTokenDelay); 
min = math_utils::min(min, TIMER.NextTokenDelay); 
min = math_utils::min(min, DEBUG_TIMER.NextTokenDelay); ;
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
tran_func tran_funcs[] = {UnnamedTransition7,
UnnamedTransition12,
BUTTONS,
UnnamedTransition5,
UnnamedTransition18,
UnnamedTransition4,
UnnamedTransition13,
UnnamedTransition16,
UnnamedTransition17,
UnnamedTransition14,
UnnamedTransition15,
DPS,
UnnamedTransition0,
UnnamedTransition9,
UnnamedTransition6,
UnnamedTransition8,
UnnamedTransition2,
UnnamedTransition3,
UnnamedTransition1,
UnnamedTransition10,
UnnamedTransition11
      };
typedef enum 
      {
        tr_UnnamedTransition7 = 0x1,
tr_UnnamedTransition12 = 0x2,
tr_BUTTONS = 0x4,
tr_UnnamedTransition5 = 0x8,
tr_UnnamedTransition18 = 0x10,
tr_UnnamedTransition4 = 0x20,
tr_UnnamedTransition13 = 0x40,
tr_UnnamedTransition16 = 0x80,
tr_UnnamedTransition17 = 0x100,
tr_UnnamedTransition14 = 0x200,
tr_UnnamedTransition15 = 0x400,
tr_DPS = 0x800,
tr_UnnamedTransition0 = 0x1000,
tr_UnnamedTransition9 = 0x2000,
tr_UnnamedTransition6 = 0x4000,
tr_UnnamedTransition8 = 0x8000,
tr_UnnamedTransition2 = 0x10000,
tr_UnnamedTransition3 = 0x20000,
tr_UnnamedTransition1 = 0x40000,
tr_UnnamedTransition10 = 0x80000,
tr_UnnamedTransition11 = 0x100000
      } ttran;
void GroupTransition1287()
                              {
                                if (!UnnamedTransition7()) 
if (!UnnamedTransition12()) 
if (!UnnamedTransition8()) 
return;
                                tran_ena(0, tr_GroupTransition1287);
                              }
static const int P_LOW = 10000;
static const int P_NORMAL = 1000;
static const int P_HIGH = 100;
CAN_UDP_MESSAGE  can2udp(const CAN_MESSAGE &m,int c)
                    {
                      return CAN_UDP_MESSAGE (c,m.field1,m.field2,m.field3);
                    }
                    
CAN_MESSAGE  udp2can(const CAN_UDP_MESSAGE &m)
                    {
                      return CAN_MESSAGE (m.ID,m.timestamp,m.data);
                    }
                    
CAN_MESSAGE  bt2can_message(int bt)
                    {u8 _N__4336[] = {(BYTE)1, bt};
                      return CAN_MESSAGE (721,IntInf.fromInt(0),byte2(_N__4336));
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
SSI.add(byte0(_N__4322));
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
BinTimer.add(add_time(at_time('u',1000000), 0););
SyncFreq.add(add_time(, 0););
TempTimer.add(add_time(at_time('u',500000), 0););
SEND_SENS.add();
BatLevel.add();
ADC.add();
TIMER.add(add_time(at_time('u',0), 0););
ADC_SUM.add(tuple2(0, 0));
DEBUG_TIMER.add(add_time(at_time('u',0), 0););
UDP_OUT.add();
COUNTER.add(0);
UDP_AND_CAN_SEND.add();
CAN_OUT.add();
        
      }
bool UnnamedTransition7()
            {
              if (lock(pl_UDP_SEND | pl_UDP_IN))
              {
                 if (UDP_IN_flag)
                {
                  CAN_UDP_MESSAGE m = UDP_IN; 
if (is_control(m)) 
                    {
                      UDP_IN_flag = false;
;
UDP_SEND.add(get_control_msg(m));
tran_ena(tr_UnnamedTransition2, 0);
return true;
                    }
                };
                unlock(pl_UDP_SEND | pl_UDP_IN);
              }
              return false;
            }
          
bool UnnamedTransition12()
            {
              if (lock(pl_SEND_SENS | pl_UDP_IN))
              {
                 if (UDP_IN_flag)
                {
                  CAN_UDP_MESSAGE m = UDP_IN; 
if (is_sens(m)) 
                    {
                      UDP_IN_flag = false;
;
SEND_SENS = 1;
tran_ena(tr_UnnamedTransition16, 0);
return true;
                    }
                };
                unlock(pl_SEND_SENS | pl_UDP_IN);
              }
              return false;
            }
          
bool BUTTONS()
            {
              if (lock(pl_UDP_AND_CAN_SEND | pl_BUTTONS))
              {
                u8 bt = BUTTONS; 
;
UDP_AND_CAN_SEND.add(bt2can_message(bt));
tran_ena(tr_UnnamedTransition3, 0);
return true;;
                unlock(pl_UDP_AND_CAN_SEND | pl_BUTTONS);
              }
              return false;
            }
          
bool UnnamedTransition5()
            {
              if (lock(pl_ADC_SUM | pl_TIMER | pl_ADC_SUM | pl_TIMER | pl_ADC))
              {
                 if (ADC_SUM_flag)
              {
                 if (TIMER.have_tokens())
              {
                ; ;
int q = ADC.peek(); 
if (<(n,10)) 
                    {
                      TIMER.get();
ADC_SUM_flag = false;
;
TIMER.add(add_time(1, 50000));
ADC_SUM = tuple2(sum + q, n + 1);
                              ADC_SUM_flag = true;
tran_ena(tr_UnnamedTransition8 | tr_UnnamedTransition6 | tr_UnnamedTransition6, tr_UnnamedTransition5);
return true;
                    }
              }
              };
                unlock(pl_ADC_SUM | pl_TIMER | pl_ADC_SUM | pl_TIMER | pl_ADC);
              }
              return false;
            }
          
bool UnnamedTransition18()
            {
              if (lock(pl_CAN_OUT))
              {
                 if (CAN_OUT_flag)
                {
                  if (res) 
                    {
                      CAN_OUT_flag = false;
;
tran_ena(0, tr_UnnamedTransition18);
return true;
                    }
                };
                unlock(pl_CAN_OUT);
              }
              return false;
            }
          
bool UnnamedTransition4()
            {
              if (lock(pl_SEND_SENS | pl_DELAY | pl_DELAY))
              {
                 if (DELAY.have_relative_time(unit.instance(), 200000))
                {
                  ; ;
DELAY.get_relative_time(unit.instance(), 200000);
;
DELAY.add(add_time(1, 0));
SEND_SENS = 1;
tran_ena(tr_UnnamedTransition16 | tr_UnnamedTransition0 | tr_UnnamedTransition18, tr_UnnamedTransition4);
return true;
                };
                unlock(pl_SEND_SENS | pl_DELAY | pl_DELAY);
              }
              return false;
            }
          
bool UnnamedTransition13()
            {
              if (lock(pl_ADC_SUM | pl_BatLevel | pl_ADC_SUM))
              {
                 if (ADC_SUM_flag)
                {
                  if (>=(n,10)) 
                    {
                      ADC_SUM_flag = false;
;
BatLevel = adc2bat(sum(div(n)));
                              BatLevel_flag = true;
ADC_SUM = tuple2(0, 0);
                              ADC_SUM_flag = true;
tran_ena(tr_UnnamedTransition8 | tr_UnnamedTransition6 | tr_UnnamedTransition17, tr_UnnamedTransition13);
return true;
                    }
                };
                unlock(pl_ADC_SUM | pl_BatLevel | pl_ADC_SUM);
              }
              return false;
            }
          
bool UnnamedTransition16()
            {
              if (lock(pl_CAN_OUT | pl_CAN))
              {
                 if (CAN.have_tokens())
                {
                  CAN_MESSAGE cm = CAN.peek(); 
CAN.get(cm);
;
CAN_OUT = tuple2(cm, can_send(cm));
                              CAN_OUT_flag = true;
tran_ena(tr_UnnamedTransition11 | tr_UnnamedTransition10, tr_UnnamedTransition16);
return true;
                };
                unlock(pl_CAN_OUT | pl_CAN);
              }
              return false;
            }
          
bool UnnamedTransition17()
            {
              if (lock(pl_CAN | pl_CAN_OUT))
              {
                 if (CAN_OUT_flag)
                {
                  if (not(res)) 
                    {
                      CAN_OUT_flag = false;
;
CAN.add(cm);
tran_ena(tr_UnnamedTransition1, tr_UnnamedTransition17);
return true;
                    }
                };
                unlock(pl_CAN | pl_CAN_OUT);
              }
              return false;
            }
          
bool UnnamedTransition14()
            {
              if (lock(pl_COUNTER | pl_UDP_OUT | pl_COUNTER | pl_UDP_SEND))
              {
                int n = COUNTER; 
 if (UDP_SEND.have_tokens())
                {
                   int cm_idx;
                                          CAN_MESSAGE cm = UDP_SEND.peek_indexed(cm_idx);
UDP_SEND.get_indexed(cm_idx);
;
UDP_OUT.add(can2udp(cm,n));
COUNTER = n + 1;
tran_ena(tr_UnnamedTransition2, tr_UnnamedTransition14);
return true;
                };
                unlock(pl_COUNTER | pl_UDP_OUT | pl_COUNTER | pl_UDP_SEND);
              }
              return false;
            }
          
bool UnnamedTransition15()
            {
              if (lock(pl_UDP_SEND | pl_CAN | pl_UDP_AND_CAN_SEND))
              {
                 if (UDP_AND_CAN_SEND.have_tokens())
                {
                   int cm_idx;
                                          CAN_MESSAGE cm = UDP_AND_CAN_SEND.peek_indexed(cm_idx);
UDP_AND_CAN_SEND.get_indexed(cm_idx);
;
CAN.add(cm);
UDP_SEND.add(cm);
tran_ena(tr_UnnamedTransition2 | tr_UnnamedTransition1, tr_UnnamedTransition15);
return true;
                };
                unlock(pl_UDP_SEND | pl_CAN | pl_UDP_AND_CAN_SEND);
              }
              return false;
            }
          
bool DPS()
            {
              if (lock(pl_SYNC_BUF | pl_UDP_SEND | pl_SYNC | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS))
              {
                ; ;
bytes8 ssi = SSI.peek(); 
int n = SYNC; 
bool dir = DPS; 
DELAY.get_all();
;
SYNC = n + 1;
UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n,dir,1,ssi)));
SYNC_BUF = token_iter_utils.repeat('u', 1);
tran_ena(tr_UnnamedTransition13 | tr_UnnamedTransition2 | tr_UnnamedTransition16 | tr_UnnamedTransition18, 0);
return true;;
                unlock(pl_SYNC_BUF | pl_UDP_SEND | pl_SYNC | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
              }
              return false;
            }
          
bool UnnamedTransition0()
            {
              if (lock(pl_DEBUG_TIMER | pl_UDP_SEND | pl_DEBUG_TIMER | pl_SEND_DEBUG))
              {
                 if (DEBUG_TIMER.have_tokens())
              {
                ; ;
 if (SEND_DEBUG_flag)
                {
                  bytesn d = SEND_DEBUG; 
SEND_DEBUG_flag = false;
DEBUG_TIMER.get();
;
UDP_SEND.add(tuple3(0, get_time(), d));
DEBUG_TIMER.add(add_time(1, 333000));
tran_ena(tr_UnnamedTransition4 | tr_UnnamedTransition2, tr_UnnamedTransition0);
return true;
                }
              };
                unlock(pl_DEBUG_TIMER | pl_UDP_SEND | pl_DEBUG_TIMER | pl_SEND_DEBUG);
              }
              return false;
            }
          
bool UnnamedTransition9()
            {
              if (lock(pl_UDP_SEND | pl_CAN_IN))
              {
                 if (CAN_IN_flag)
                {
                  CAN_MESSAGE cm = CAN_IN; 
CAN_IN_flag = false;
can_process(cm);
UDP_SEND.add(cm);
tran_ena(tr_UnnamedTransition2, tr_UnnamedTransition9);
return true;
                };
                unlock(pl_UDP_SEND | pl_CAN_IN);
              }
              return false;
            }
          
bool UnnamedTransition6()
            {
              if (lock(pl_UDP_SEND | pl_GPS))
              {
                 if (GPS_flag)
                {
                  bytesn s = GPS; 
GPS_flag = false;
;
UDP_SEND.add(tuple3(256, get_time(), s));
tran_ena(tr_UnnamedTransition2, tr_UnnamedTransition6);
return true;
                };
                unlock(pl_UDP_SEND | pl_GPS);
              }
              return false;
            }
          
bool UnnamedTransition8()
            {
              if (lock(pl_CAN | pl_UDP_IN))
              {
                 if (UDP_IN_flag)
                {
                  CAN_UDP_MESSAGE m = UDP_IN; 
UDP_IN_flag = false;
;
CAN.add(udp2can(m));
tran_ena(tr_UnnamedTransition1, 0);
return true;
                };
                unlock(pl_CAN | pl_UDP_IN);
              }
              return false;
            }
          
bool UnnamedTransition2()
            {
              if (lock(pl_SyncFreq | pl_SYNC | pl_SyncFreq))
              {
                 if (SyncFreq.have_tokens())
                {
                  int SyncFreq_tok = SyncFreq.peek();; int freq = SyncFreq_tok;;
SyncFreq.get(freq);
;
SYNC = 0;
SyncFreq.add(add_time(freq(Delay(/(1000000,freq))), 0));
tran_ena(tr_UnnamedTransition14 | tr_UnnamedTransition16 | tr_UnnamedTransition18, tr_UnnamedTransition2);
return true;
                };
                unlock(pl_SyncFreq | pl_SYNC | pl_SyncFreq);
              }
              return false;
            }
          
bool UnnamedTransition3()
            {
              if (lock(pl_UDP_AND_CAN_SEND | pl_TempTimer | pl_TempTimer | pl_TEMP))
              {
                 if (TempTimer.have_relative_time(unit.instance(), 500000))
              {
                ; ;
int n = TEMP.peek(); 
TempTimer.get_relative_time(unit.instance(), 500000);
;
TempTimer.add(add_time(1, 0));
UDP_AND_CAN_SEND.add(tuple3(721, get_time(), list.Cons(51,IntToList(n))));
tran_ena(tr_UnnamedTransition3 | tr_UnnamedTransition15, tr_UnnamedTransition3);
return true;
              };
                unlock(pl_UDP_AND_CAN_SEND | pl_TempTimer | pl_TempTimer | pl_TEMP);
              }
              return false;
            }
          
bool UnnamedTransition1()
            {
              if (lock(pl_UDP_AND_CAN_SEND | pl_UDP_AND_CAN_SEND | pl_BinTimer | pl_BatLevel | pl_BinTimer | pl_BUTTONS))
              {
                 if (BatLevel_flag)
              {
                 if (BinTimer.have_tokens())
              {
                ; ;
int inp = BUTTONS; 
BinTimer.get();
BatLevel_flag = false;
;
BinTimer.add(add_time(1, 1000000));
UDP_AND_CAN_SEND.add(tuple3(336, get_time(), (_N__4334)));
UDP_AND_CAN_SEND.add(tuple3(721, get_time(), (_N__4335)));
tran_ena(tr_UnnamedTransition3 | tr_UnnamedTransition3 | tr_UnnamedTransition17, tr_UnnamedTransition1);
return true;
              }
              };
                unlock(pl_UDP_AND_CAN_SEND | pl_UDP_AND_CAN_SEND | pl_BinTimer | pl_BatLevel | pl_BinTimer | pl_BUTTONS);
              }
              return false;
            }
          
bool UnnamedTransition10()
            {
              if (lock(pl_DELAY | pl_SYNC_BUF))
              {
                 if (SYNC_BUF_flag)
                {
                  SYNC_BUF_flag = false;
;
DELAY.add(add_time(1, 0));
tran_ena(tr_UnnamedTransition0 | tr_UnnamedTransition18, tr_UnnamedTransition10);
return true;
                };
                unlock(pl_DELAY | pl_SYNC_BUF);
              }
              return false;
            }
          
bool UnnamedTransition11()
            {
              if (lock(pl_UDP_SEND | pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS))
              {
                 if (SEND_SENS_flag)
              {
                bytes8 ssi = SSI.peek(); 
int n = SYNC; 
bool dir = DPS; 
SEND_SENS_flag = false;
;
UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n,dir,0,ssi)));
tran_ena(tr_UnnamedTransition2, tr_UnnamedTransition11);
return true;
              };
                unlock(pl_UDP_SEND | pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS);
              }
              return false;
            }
          
function adc2bat;
function get_ssi_bytes;
function get_control_msg;
function can_process;
            };
        