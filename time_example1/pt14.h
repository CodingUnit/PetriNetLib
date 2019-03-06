class pt14 : public timed_petri_net
            {
              typedef enum
         {
           pl_DPS = 1,
pl_SYNC = 2,
pl_SSI = 4,
pl_BUTTONS = 8,
pl_UDP_IN = 16,
pl_DELAY = 32,
pl_BinTimer = 64,
pl_TempTimer = 128,
pl_SEND_SENS = 256,
pl_ADC = 512,
pl_TIMER = 1024,
pl_ADC_SUM = 2048,
pl_DEBUG_TIMER = 4096,
pl_UDP_OUT = 8192,
pl_COUNTER = 16384,
pl_CAN_OUT = 32768
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
tranfunc tran_funcs[] = {UnnamedTransition6,
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
                    {u8 _N__4527[] = {(BYTE)1, bt};
                      return CAN_MESSAGE (721,IntInf.fromInt(0),byte2(_N__4527));
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
places_ena(GPS.have_tokens() && , pl_GPS, pl_UDP_SEND);
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
                  
              if (UDP_IN.have_tokens())
              {
                 int m_idx;
                                          CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
                if (is_control(m)) 
                    {
                      UDP_IN.get_indexed(m_idx);

UDP_SEND.add(get_control_msg(m));
places_ena(UDP_IN.have_tokens() && , pl_UDP_IN, pl_UDP_SEND);
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
                  
              if (UDP_IN.have_tokens())
              {
                 int m_idx;
                                          CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
                UDP_IN.get_indexed(m_idx);

CAN.add(udp2can(m));
places_ena(UDP_IN.have_tokens() && , pl_UDP_IN, pl_CAN);
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
                  
              if (CAN_IN.have_tokens())
              {
                 int cm_idx;
                                          CAN_MESSAGE cm = CAN_IN.peek_indexed(cm_idx);
                CAN_IN.get_indexed(cm_idx);
can_process(cm)
UDP_SEND.add(cm);
places_ena(CAN_IN.have_tokens() && , pl_CAN_IN, pl_UDP_SEND);
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
                
              if (SSI.have_tokens())
              {
                 int ssi_idx;
                                          bytesn ssi = SSI.peek_indexed(ssi_idx);
                  
              if (SYNC.have_tokens())
              {
                 int n_idx;
                                          int n = SYNC.peek_indexed(n_idx);
                  
              if (DPS.have_tokens())
              {
                 int dir_idx;
                                          bool dir = DPS.peek_indexed(dir_idx);
                DPS.get_indexed(dir_idx);
SYNC.get_indexed(n_idx);
SSI.get_indexed(ssi_idx);
DELAY.get_all()

SYNC.add(n + 1);
UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n,dir,1,ssi)));
SYNC_BUF.add(unit.instance());
places_ena(SSI.have_tokens() && SYNC.have_tokens() && DPS.have_tokens() && , pl_DELAY | pl_SSI | pl_SYNC | pl_DPS, pl_SYNC_BUF | pl_UDP_SEND | pl_SYNC);
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
places_ena(DEBUG_TIMER.have_tokens() && SEND_DEBUG.have_tokens() && , pl_DEBUG_TIMER | pl_SEND_DEBUG, pl_DEBUG_TIMER | pl_UDP_SEND);
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
                  
              if (SYNC_BUF.have_tokens())
              {
                
                SYNC_BUF.get();

DELAY.add(add_time(unit.instance(), 0));
places_ena(SYNC_BUF.have_tokens() && , pl_SYNC_BUF, pl_DELAY);
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
                  
              if (SEND_SENS.have_tokens())
              {
                
                  
              if (SSI.have_tokens())
              {
                 int ssi_idx;
                                          bytesn ssi = SSI.peek_indexed(ssi_idx);
                  
              if (SYNC.have_tokens())
              {
                 int n_idx;
                                          int n = SYNC.peek_indexed(n_idx);
                  
              if (DPS.have_tokens())
              {
                 int dir_idx;
                                          bool dir = DPS.peek_indexed(dir_idx);
                DPS.get_indexed(dir_idx);
SYNC.get_indexed(n_idx);
SSI.get_indexed(ssi_idx);
SEND_SENS.get();

UDP_SEND.add(tuple3(663, get_time(), get_ssi_bytes(n,dir,0,ssi)));
places_ena(SEND_SENS.have_tokens() && SSI.have_tokens() && SYNC.have_tokens() && DPS.have_tokens() && , pl_SEND_SENS | pl_SSI | pl_SYNC | pl_DPS, pl_UDP_SEND);
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
                  
              if (BatLevel.have(IEnumerable[(bt, n)]))
              {
                
                  
              if (BinTimer.have_tokens())
              {
                ; ;
                  
              if (BUTTONS.have_tokens())
              {
                 int inp_idx;
                                          int inp = BUTTONS.peek_indexed(inp_idx);
                BUTTONS.get_indexed(inp_idx);
BinTimer.get();
BatLevel.get((bt, n));

BinTimer.add(add_time(unit.instance(), 1000000));
UDP_AND_CAN_SEND.add(tuple3(336, get_time(), (_N__4525)));
UDP_AND_CAN_SEND.add(tuple3(721, get_time(), (_N__4526)));
places_ena(BatLevel.have(IEnumerable[(bt, n)]) && BinTimer.have_tokens() && BUTTONS.have_tokens() && , pl_BatLevel | pl_BinTimer | pl_BUTTONS, pl_UDP_AND_CAN_SEND | pl_UDP_AND_CAN_SEND | pl_BinTimer);
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
                  
              if (SyncFreq.have_tokens())
              {
                int freq_idx;
                                          int SyncFreq_tok = SyncFreq.peek_indexed(freq);; int freq = SyncFreq_tok;;
                SyncFreq.get_indexed(freq_idx);

SYNC.add(0);
SyncFreq.add(add_time(freq(Delay(/(1000000,freq))), 0));
places_ena(SyncFreq.have_tokens() && , pl_SyncFreq, pl_SyncFreq | pl_SYNC);
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
                  
              if (TEMP.have_tokens())
              {
                 int n_idx;
                                          int n = TEMP.peek_indexed(n_idx);
                TEMP.get_indexed(n_idx);
TempTimer.get_relative_time(unit.instance(), 500000);

TempTimer.add(add_time(unit.instance(), 0));
UDP_AND_CAN_SEND.add(tuple3(721, get_time(), list.Cons(51,IntToList(n))));
places_ena(TempTimer.have_relative_time(unit.instance(), 500000) && TEMP.have_tokens() && , pl_TempTimer | pl_TEMP, pl_UDP_AND_CAN_SEND | pl_TempTimer);
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
                  
              if (UDP_IN.have_tokens())
              {
                 int m_idx;
                                          CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
                if (is_sens(m)) 
                    {
                      UDP_IN.get_indexed(m_idx);

SEND_SENS.add(unit.instance());
places_ena(UDP_IN.have_tokens() && , pl_UDP_IN, pl_SEND_SENS);
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
places_ena(DELAY.have_relative_time(unit.instance(), 200000) && , pl_DELAY, pl_SEND_SENS | pl_DELAY);
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
                  
              if (BUTTONS.have_tokens())
              {
                 int bt_idx;
                                          u8 bt = BUTTONS.peek_indexed(bt_idx);
                BUTTONS.get_indexed(bt_idx);

UDP_AND_CAN_SEND.add(bt2can_message(bt));
places_ena(BUTTONS.have_tokens() && , pl_BUTTONS, pl_UDP_AND_CAN_SEND);
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
                  
              if (ADC_SUM.have(IEnumerable[(sum, n)]))
              {
                
                  
              if (TIMER.have_tokens())
              {
                ; ;
                  
              if (ADC.have_tokens())
              {
                 int q_idx;
                                          int q = ADC.peek_indexed(q_idx);
                if (<(n,10)) 
                    {
                      ADC.get_indexed(q_idx);
TIMER.get();
ADC_SUM.get((sum, n));

TIMER.add(add_time(unit.instance(), 50000));
ADC_SUM.add(tuple2(sum + q, n + 1));
places_ena(ADC_SUM.have(IEnumerable[(sum, n)]) && TIMER.have_tokens() && ADC.have_tokens() && , pl_ADC_SUM | pl_TIMER | pl_ADC, pl_ADC_SUM | pl_TIMER);
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
                  
              if (ADC_SUM.have(IEnumerable[(sum, n)]))
              {
                
                if (>=(n,10)) 
                    {
                      ADC_SUM.get((sum, n));

BatLevel.add(adc2bat(sum(div(n))));
ADC_SUM.add(tuple2(0, 0));
places_ena(ADC_SUM.have(IEnumerable[(sum, n)]) && , pl_ADC_SUM, pl_ADC_SUM | pl_BatLevel);
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
                  
              if (COUNTER.have_tokens())
              {
                 int n_idx;
                                          int n = COUNTER.peek_indexed(n_idx);
                  
              if (UDP_SEND.have_tokens())
              {
                 int cm_idx;
                                          CAN_MESSAGE cm = UDP_SEND.peek_indexed(cm_idx);
                UDP_SEND.get_indexed(cm_idx);
COUNTER.get_indexed(n_idx);

UDP_OUT.add(can2udp(cm,n));
COUNTER.add(n + 1);
places_ena(COUNTER.have_tokens() && UDP_SEND.have_tokens() && , pl_COUNTER | pl_UDP_SEND, pl_COUNTER | pl_UDP_OUT);
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
                  
              if (UDP_AND_CAN_SEND.have_tokens())
              {
                 int cm_idx;
                                          CAN_MESSAGE cm = UDP_AND_CAN_SEND.peek_indexed(cm_idx);
                UDP_AND_CAN_SEND.get_indexed(cm_idx);

CAN.add(cm);
UDP_SEND.add(cm);
places_ena(UDP_AND_CAN_SEND.have_tokens() && , pl_UDP_AND_CAN_SEND, pl_UDP_SEND | pl_CAN);
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
places_ena(CAN.have_tokens() && , pl_CAN, pl_CAN_OUT);
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
                  
              if (CAN_OUT.have(IEnumerable[(cm, res)]))
              {
                
                if (not(res)) 
                    {
                      CAN_OUT.get((cm, res));

CAN.add(cm);
places_ena(CAN_OUT.have(IEnumerable[(cm, res)]) && , pl_CAN_OUT, pl_CAN);
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
                  
              if (CAN_OUT.have(IEnumerable[(cm, res)]))
              {
                
                if (res) 
                    {
                      CAN_OUT.get((cm, res));

places_ena(CAN_OUT.have(IEnumerable[(cm, res)]) && , pl_CAN_OUT, );
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
        