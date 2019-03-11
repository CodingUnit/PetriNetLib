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
                        UnnamedTransition76(), UnnamedTransition77(), UnnamedTransition78(), UnnamedTransition79(), UnnamedTransition80(), UnnamedTransition81();
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
tranfunc tran_funcs[] = {UnnamedTransition82,
UnnamedTransition83,
UnnamedTransition84,
UnnamedTransition85,
DPS,
UnnamedTransition76,
UnnamedTransition86,
UnnamedTransition87,
UnnamedTransition77,
UnnamedTransition78,
UnnamedTransition79,
UnnamedTransition88,
UnnamedTransition80,
BUTTONS,
UnnamedTransition81,
UnnamedTransition89,
UnnamedTransition90,
UnnamedTransition91,
UnnamedTransition92,
UnnamedTransition93,
UnnamedTransition94
      };
typedef enum 
      {
        tr_UnnamedTransition82 = 0x1,
tr_UnnamedTransition83 = 0x2,
tr_UnnamedTransition84 = 0x4,
tr_UnnamedTransition85 = 0x8,
tr_DPS = 0x10,
tr_UnnamedTransition76 = 0x20,
tr_UnnamedTransition86 = 0x40,
tr_UnnamedTransition87 = 0x80,
tr_UnnamedTransition77 = 0x100,
tr_UnnamedTransition78 = 0x200,
tr_UnnamedTransition79 = 0x400,
tr_UnnamedTransition88 = 0x800,
tr_UnnamedTransition80 = 0x1000,
tr_BUTTONS = 0x2000,
tr_UnnamedTransition81 = 0x4000,
tr_UnnamedTransition89 = 0x8000,
tr_UnnamedTransition90 = 0x10000,
tr_UnnamedTransition91 = 0x20000,
tr_UnnamedTransition92 = 0x40000,
tr_UnnamedTransition93 = 0x80000,
tr_UnnamedTransition94 = 0x100000
      } ttran;
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
                    {u8 _N__4386[] = {(BYTE)1, bt};
                      return CAN_MESSAGE (721,IntInf.fromInt(0),byte2(_N__4386));
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
        UnnamedTransition82()
UnnamedTransition83()
UnnamedTransition84()
UnnamedTransition85()
UnnamedTransition86()
UnnamedTransition87()
UnnamedTransition88()
UnnamedTransition89()
UnnamedTransition90()
UnnamedTransition91()
UnnamedTransition92()
UnnamedTransition93()
UnnamedTransition94()
      }
pt14(int time_step = 15) 
      { 
        timed_petri_net(time_step);
        DPS.add(false);
SYNC.add(0);
SSI.add(byte0(_N__4372));
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
void UnnamedTransition82()
            {
              if (lock(pl_UDP_SEND | pl_GPS))
              {
                 if (GPS_flag)
                {
                  bytesn s = GPS; 
GPS_flag = false;
;
UDP_SEND.add(tuple3(256, get_time(), s));
tran_ena(tr_UnnamedTransition90, tr_UnnamedTransition82);
                };
                unlock(pl_UDP_SEND | pl_GPS);
              }
            }
          
void UnnamedTransition83()
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
tran_ena(tr_UnnamedTransition90, tr_UnnamedTransition83);
                    }
                };
                unlock(pl_UDP_SEND | pl_UDP_IN);
              }
            }
          
void UnnamedTransition84()
            {
              if (lock(pl_CAN | pl_UDP_IN))
              {
                 if (UDP_IN_flag)
                {
                  CAN_UDP_MESSAGE m = UDP_IN; 
UDP_IN_flag = false;
;
CAN.add(udp2can(m));
tran_ena(tr_UnnamedTransition92, tr_UnnamedTransition84);
                };
                unlock(pl_CAN | pl_UDP_IN);
              }
            }
          
void UnnamedTransition85()
            {
              if (lock(pl_UDP_SEND | pl_CAN_IN))
              {
                 if (CAN_IN_flag)
                {
                  CAN_MESSAGE cm = CAN_IN; 
CAN_IN_flag = false;
can_process(cm);
UDP_SEND.add(cm);
tran_ena(tr_UnnamedTransition90, tr_UnnamedTransition85);
                };
                unlock(pl_UDP_SEND | pl_CAN_IN);
              }
            }
          
void DPS()
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
tran_ena(tr_UnnamedTransition86 | tr_UnnamedTransition90 | tr_UnnamedTransition87, 0);;
                unlock(pl_SYNC_BUF | pl_UDP_SEND | pl_SYNC | pl_DELAY | pl_SSI | pl_SYNC | pl_DPS);
              }
            }
          
void UnnamedTransition76()
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
tran_ena(tr_UnnamedTransition76 | tr_UnnamedTransition90, tr_UnnamedTransition76);
                }
              };
                unlock(pl_DEBUG_TIMER | pl_UDP_SEND | pl_DEBUG_TIMER | pl_SEND_DEBUG);
              }
            }
          
void UnnamedTransition86()
            {
              if (lock(pl_DELAY | pl_SYNC_BUF))
              {
                 if (SYNC_BUF_flag)
                {
                  SYNC_BUF_flag = false;
;
DELAY.add(add_time(1, 0));
tran_ena(tr_UnnamedTransition80, tr_UnnamedTransition86);
                };
                unlock(pl_DELAY | pl_SYNC_BUF);
              }
            }
          
void UnnamedTransition87()
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
tran_ena(tr_UnnamedTransition90, tr_UnnamedTransition87);
              };
                unlock(pl_UDP_SEND | pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS);
              }
            }
          
void UnnamedTransition77()
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
UDP_AND_CAN_SEND.add(tuple3(336, get_time(), (_N__4384)));
UDP_AND_CAN_SEND.add(tuple3(721, get_time(), (_N__4385)));
tran_ena(tr_UnnamedTransition91 | tr_UnnamedTransition91 | tr_UnnamedTransition77, tr_UnnamedTransition77);
              }
              };
                unlock(pl_UDP_AND_CAN_SEND | pl_UDP_AND_CAN_SEND | pl_BinTimer | pl_BatLevel | pl_BinTimer | pl_BUTTONS);
              }
            }
          
void UnnamedTransition78()
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
tran_ena(tr_UnnamedTransition78 | tr_UnnamedTransition87, tr_UnnamedTransition78);
                };
                unlock(pl_SyncFreq | pl_SYNC | pl_SyncFreq);
              }
            }
          
void UnnamedTransition79()
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
tran_ena(tr_UnnamedTransition91 | tr_UnnamedTransition79, tr_UnnamedTransition79);
              };
                unlock(pl_UDP_AND_CAN_SEND | pl_TempTimer | pl_TempTimer | pl_TEMP);
              }
            }
          
void UnnamedTransition88()
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
tran_ena(tr_UnnamedTransition87, tr_UnnamedTransition88);
                    }
                };
                unlock(pl_SEND_SENS | pl_UDP_IN);
              }
            }
          
void UnnamedTransition80()
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
tran_ena(tr_UnnamedTransition87 | tr_UnnamedTransition80, tr_UnnamedTransition80);
                };
                unlock(pl_SEND_SENS | pl_DELAY | pl_DELAY);
              }
            }
          
void BUTTONS()
            {
              if (lock(pl_UDP_AND_CAN_SEND | pl_BUTTONS))
              {
                u8 bt = BUTTONS; 
;
UDP_AND_CAN_SEND.add(bt2can_message(bt));
tran_ena(tr_UnnamedTransition91, 0);;
                unlock(pl_UDP_AND_CAN_SEND | pl_BUTTONS);
              }
            }
          
void UnnamedTransition81()
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
tran_ena(tr_UnnamedTransition89 | tr_UnnamedTransition81 | tr_UnnamedTransition81, tr_UnnamedTransition81);
                    }
              }
              };
                unlock(pl_ADC_SUM | pl_TIMER | pl_ADC_SUM | pl_TIMER | pl_ADC);
              }
            }
          
void UnnamedTransition89()
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
tran_ena(tr_UnnamedTransition89 | tr_UnnamedTransition81 | tr_UnnamedTransition77, tr_UnnamedTransition89);
                    }
                };
                unlock(pl_ADC_SUM | pl_BatLevel | pl_ADC_SUM);
              }
            }
          
void UnnamedTransition90()
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
tran_ena(tr_UnnamedTransition90, tr_UnnamedTransition90);
                };
                unlock(pl_COUNTER | pl_UDP_OUT | pl_COUNTER | pl_UDP_SEND);
              }
            }
          
void UnnamedTransition91()
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
tran_ena(tr_UnnamedTransition90 | tr_UnnamedTransition92, tr_UnnamedTransition91);
                };
                unlock(pl_UDP_SEND | pl_CAN | pl_UDP_AND_CAN_SEND);
              }
            }
          
void UnnamedTransition92()
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
tran_ena(tr_UnnamedTransition94 | tr_UnnamedTransition93, tr_UnnamedTransition92);
                };
                unlock(pl_CAN_OUT | pl_CAN);
              }
            }
          
void UnnamedTransition93()
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
tran_ena(tr_UnnamedTransition92, tr_UnnamedTransition93);
                    }
                };
                unlock(pl_CAN | pl_CAN_OUT);
              }
            }
          
void UnnamedTransition94()
            {
              if (lock(pl_CAN_OUT))
              {
                 if (CAN_OUT_flag)
                {
                  if (res) 
                    {
                      CAN_OUT_flag = false;
;
tran_ena(0, tr_UnnamedTransition94);
                    }
                };
                unlock(pl_CAN_OUT);
              }
            }
          
function adc2bat;
function get_ssi_bytes;
function get_control_msg;
function can_process;
            };
        