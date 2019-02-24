class pt14 : public timed_petri_net
{
  bool is_control(const CAN_UDP_MESSAGE &m)
  {

    return m.ID == 80;
  }
  void EXT_can_process(const CAN_MESSAGE &m)
  {

    return 'u';
  }
  bytesn EXT_intToList(INT n)
  {

    return byte0(_N__4489);
  }
  ? EXT_get_time()
  {

    return IntInf.fromInt(0);
  }
  CAN_MESSAGE EXT_get_control_msg(const CAN_UDP_MESSAGE &m)
  {
    u8 _N__4481[] = {};
    return CAN_MESSAGE(m.ID, m.timestamp, byte0(_N__4481));
  }
  bool is_sens(const CAN_UDP_MESSAGE &m)
  {

    return m.ID == 663;
  }
  tuple2<int, int> EXT_adc2bat(INT q)
  {

    return tuple2(0, q);
  }
  CAN_MESSAGE bt2can_message(INT bt)
  {
    u8 _N__4472[] = { (BYTE)1, bt };
    return CAN_MESSAGE(721, IntInf.fromInt(0), byte2(_N__4472));
  }
  CAN_MESSAGE udp2can(const CAN_UDP_MESSAGE &m)
  {

    return CAN_MESSAGE(m.ID, m.timestamp, m.data);
  }
  CAN_UDP_MESSAGE can2udp(const CAN_MESSAGE &m, INT c)
  {

    return CAN_UDP_MESSAGE(c, m.field1, m.field2, m.field3);
  }
  bytesn EXT_get_ssi_bytes(INT c, BOOL dir, INT flags, const TSSI &ssi)
  {
    u8 _N__4460[] = {};
    return byte0(_N__4460);
  }
  const int P_HIGH = 100;
  const int P_NORMAL = 1000;
  const int P_LOW = 10000;
  multi_set UDP_AND_CAN_SEND;
  multi_set COUNTER;
  multi_set UDP_OUT;
  timed_heap DEBUG_TIMER;
  multi_set ADC_SUM;
  timed_heap TIMER;
  random_array ADC;
  multi_set BatLevel;
  random_array SEND_SENS;
  timed_heap TempTimer;
  timed_heap SyncFreq;
  timed_heap BinTimer;
  timed_heap DELAY;
  random_array SYNC_BUF;
  random_array SEND_DEBUG;
  random_array GPS;
  random_array CAN_IN;
  random_array BinInputs;
  multi_set UDP_SEND;
  multi_set CAN_OUT;
  random_array UDP_IN;
  random_array BUTTONS;
  random_array TEMP;
  random_array SSI;
  multi_set SYNC;
  random_array DPS;
  void time_step()
  {
    UnnamedTransition0(), UnnamedTransition1(), UnnamedTransition2(), UnnamedTransition3(), UnnamedTransition4(), UnnamedTransition5();
  }
  int get_next_time()
  {

    int min = 0xFFFFFFFF;
  expr: min = math_utils::min(min, DELAY.NextTokenDelay);
  expr: min = math_utils::min(min, BinTimer.NextTokenDelay);
  expr: min = math_utils::min(min, SyncFreq.NextTokenDelay);
  expr: min = math_utils::min(min, TempTimer.NextTokenDelay);
  expr: min = math_utils::min(min, TIMER.NextTokenDelay);
  expr: min = math_utils::min(min, DEBUG_TIMER.NextTokenDelay); ;
    return min;
    ;
  }
  typedef STRING DEBUG_INFO;
  typedef char STRING;

  typedef INT MINUS_SINGLE_INT;
  typedef char INT;

  struct CAN_UDP_MESSAGE
  {
    CAN_UDP_MESSAGE(int COUNT, int ID, LONGTIME timestamp, int data)
    {
      this->COUNT = COUNT;
      this->ID = ID;
      this->timestamp = timestamp;
      this->data = data;
    }
    int COUNT;
    int ID;
    LONGTIME timestamp;
    int data;
  };
  typedef UNIT SINGLE_TIMED_VOID;
  typedef char UNIT;

  typedef BOOL CACHED_BOOL;
  typedef char BOOL;

  struct CAN_MESSAGE
  {
    CAN_MESSAGE(int field1, long long field2, int field3)
    {
      this->field1 = field1;
      this->field2 = field2;
      this->field3 = field3;
    }

    int field1;
    long long field2;
    int field3;
  };
  typedef INT CACHED_INT;
  typedef char INT;

  struct STRING
  {
    STRING(int field1, int field2)
    {
      this->field1 = field1;
      this->field2 = field2;
    }

    int field1;
    int field2;
  };
  typedef INT TIMED_INT;
  typedef char INT;

  typedef INT QUEUE_INT;
  typedef char INT;

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
  typedef INTINF LONGTIME;
  typedef char INTINF;

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
  typedef UNIT UNIT_TIMED;
  typedef char UNIT;

  typedef byte BYTE;
  typedef real REAL;
  typedef time TIME;
  typedef intinf INTINF;
  typedef int INT;
  typedef bool BOOL;
  typedef char UNIT;

public:

  void UnnamedTransition17()
  {
    if (lock(UnnamedTransition17))
    {

      if (UDP_AND_CAN_SEND.have_tokens())
      {
        int cm_idx;
        CAN_MESSAGE cm = UDP_AND_CAN_SEND.peek_indexed(cm_idx);
        UDP_AND_CAN_SEND.get_indexed(cm_idx);

        CAN_OUT.add(cm);
        OnUnnamedTransition17()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition16()
  {
    if (lock(UnnamedTransition16))
    {

      if (UDP_AND_CAN_SEND.have_tokens())
      {
        int cm_idx;
        CAN_MESSAGE cm = UDP_AND_CAN_SEND.peek_indexed(cm_idx);
        UDP_AND_CAN_SEND.get_indexed(cm_idx);

        UDP_SEND.add(cm);
        OnUnnamedTransition16()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition15()
  {
    if (lock(UnnamedTransition15))
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

          UDP_OUT.add(can2udp(cm, n));
          COUNTER.add(n + 1);
          OnUnnamedTransition15()
        }

      }
      ;
      unlock();
    }
  }

  void UnnamedTransition14()
  {
    if (lock(UnnamedTransition14))
    {

      if (ADC_SUM.have(IEnumerable[(sum, n)]))
      {

        if (>= (n, 10))
        {
          ADC_SUM.get((sum, n));

          BatLevel.add(EXT_adc2bat(sum(div(n))));
          ADC_SUM.add(tuple2(0, 0));
        }
        OnUnnamedTransition14()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition5()
  {
    if (lock(UnnamedTransition5))
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
            if (< (n, 10))
            {
              ADC.get_indexed(q_idx);
              TIMER.get();
              ADC_SUM.get((sum, n));

              TIMER.add(add_time(unit.instance(), 50000));
              ADC_SUM.add(tuple2(sum + q, n + 1));
            }
            OnUnnamedTransition5()
          }

        }

      }
      ;
      unlock();
    }
  }

  void UnnamedTransition13()
  {
    if (lock(UnnamedTransition13))
    {

      if (BUTTONS.have_tokens())
      {
        int bt_idx;
        int bt = BUTTONS.peek_indexed(bt_idx);
        BUTTONS.get_indexed(bt_idx);

        UDP_AND_CAN_SEND.add(bt2can_message(bt));
        OnUnnamedTransition13()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition4()
  {
    if (lock(UnnamedTransition4))
    {

      if (DELAY.have_relative_time(unit.instance(), 200000))
      {
        ; ;
        DELAY.get_relative_time(unit.instance(), 200000);

        DELAY.add(add_time(unit.instance(), 0));
        SEND_SENS.add(unit.instance());
        OnUnnamedTransition4()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition12()
  {
    if (lock(UnnamedTransition12))
    {

      if (UDP_IN.have_tokens())
      {
        int m_idx;
        CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
        if (is_sens(m))
        {
          UDP_IN.get_indexed(m_idx);

          SEND_SENS.add(unit.instance());
        }
        OnUnnamedTransition12()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition3()
  {
    if (lock(UnnamedTransition3))
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
          UDP_AND_CAN_SEND.add(tuple3(721, EXT_get_time(), list.Cons(51, EXT_intToList(n))));
          OnUnnamedTransition3()
        }

      }
      ;
      unlock();
    }
  }

  void UnnamedTransition2()
  {
    if (lock(UnnamedTransition2))
    {

      if (SyncFreq.have_tokens())
      {
        int freq_idx;
        int SyncFreq_tok = SyncFreq.peek_indexed(freq);; int freq = SyncFreq_tok;;
        SyncFreq.get_indexed(freq_idx);

        SYNC.add(0);
        SyncFreq.add(add_time(freq(Delay(/ (1000000, freq))), 0));
        OnUnnamedTransition2()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition1()
  {
    if (lock(UnnamedTransition1))
    {

      if (BatLevel.have(IEnumerable[(bt, n)]))
      {


        if (BinTimer.have_tokens())
        {
          ; ;

          if (BinInputs.have_tokens())
          {
            int inp_idx;
            int inp = BinInputs.peek_indexed(inp_idx);
            BinInputs.get_indexed(inp_idx);
            BinTimer.get();
            BatLevel.get((bt, n));

            BinTimer.add(add_time(unit.instance(), 1000000));
            UDP_AND_CAN_SEND.add(tuple3(336, EXT_get_time(), EXT_intToList(bt + n * 65536)));
            OnUnnamedTransition1()
          }

        }

      }
      ;
      unlock();
    }
  }

  void UnnamedTransition11()
  {
    if (lock(UnnamedTransition11))
    {

      if (SEND_SENS.have_tokens())
      {


        if (SSI.have_tokens())
        {
          int ssi_idx;
          int ssi = SSI.peek_indexed(ssi_idx);

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

              UDP_SEND.add(tuple3(663, EXT_get_time(), EXT_get_ssi_bytes(n, dir, 0, ssi)));
              OnUnnamedTransition11()
            }

          }

        }

      }
      ;
      unlock();
    }
  }

  void UnnamedTransition10()
  {
    if (lock(UnnamedTransition10))
    {

      if (SYNC_BUF.have_tokens())
      {

        SYNC_BUF.get();

        DELAY.add(add_time(unit.instance(), 0));
        OnUnnamedTransition10()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition0()
  {
    if (lock(UnnamedTransition0))
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

          UDP_SEND.add(tuple3(0, EXT_get_time(), d.field2));
          DEBUG_TIMER.add(add_time(unit.instance(), 333000));
          OnUnnamedTransition0()
        }

      }
      ;
      unlock();
    }
  }

  void DPS()
  {
    if (lock(DPS))
    {

      ; ;

      if (SSI.have_tokens())
      {
        int ssi_idx;
        int ssi = SSI.peek_indexed(ssi_idx);

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
            UDP_SEND.add(tuple3(663, EXT_get_time(), EXT_get_ssi_bytes(n, dir, 1, ssi)));
            SYNC_BUF.add(unit.instance());
            OnDPS()
          }

        }

      }

      ;
      unlock();
    }
  }

  void UnnamedTransition9()
  {
    if (lock(UnnamedTransition9))
    {

      if (CAN_IN.have_tokens())
      {
        int cm_idx;
        CAN_MESSAGE cm = CAN_IN.peek_indexed(cm_idx);
        CAN_IN.get_indexed(cm_idx);
        EXT_can_process(cm)
          UDP_SEND.add(cm);
        OnUnnamedTransition9()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition8()
  {
    if (lock(UnnamedTransition8))
    {

      if (UDP_IN.have_tokens())
      {
        int m_idx;
        CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
        UDP_IN.get_indexed(m_idx);

        CAN_OUT.add(udp2can(m));
        OnUnnamedTransition8()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition7()
  {
    if (lock(UnnamedTransition7))
    {

      if (UDP_IN.have_tokens())
      {
        int m_idx;
        CAN_UDP_MESSAGE m = UDP_IN.peek_indexed(m_idx);
        if (is_control(m))
        {
          UDP_IN.get_indexed(m_idx);

          UDP_SEND.add(EXT_get_control_msg(m));
        }
        OnUnnamedTransition7()
      }
      ;
      unlock();
    }
  }

  void UnnamedTransition6()
  {
    if (lock(UnnamedTransition6))
    {

      if (GPS.have_tokens())
      {
        int s_idx;
        STRING s = GPS.peek_indexed(s_idx);
        GPS.get_indexed(s_idx);

        UDP_SEND.add(tuple3(256, EXT_get_time(), s.field2));
        OnUnnamedTransition6()
      }
      ;
      unlock();
    }
  }

  pt14(int time_step = 15)
  {
    timed_petri_net(time_step);
    DPS.add();
    SYNC.add(0);
    SSI.add();
    TEMP.add();
    BUTTONS.add();
    UDP_IN.add();
    CAN_OUT.add();
    UDP_SEND.add();
    BinInputs.add();
    CAN_IN.add();
    GPS.add();
    SEND_DEBUG.add();
    SYNC_BUF.add();
    DELAY.add(add_time('u', 0););
    BinTimer.add(add_time(at_time('u', 1000000), 0););
    SyncFreq.add(add_time(, 0););
    TempTimer.add(add_time(, 0););
    SEND_SENS.add();
    BatLevel.add();
    ADC.add();
    TIMER.add(add_time(at_time('u', 0), 0););
    ADC_SUM.add(tuple2(0, 0));
    DEBUG_TIMER.add(add_time(at_time('u', 0), 0););
    UDP_OUT.add();
    COUNTER.add();
    UDP_AND_CAN_SEND.add();

  }
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
  }
};
