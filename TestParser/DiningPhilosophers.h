class DiningPhilosophers : public petri_net
            {
              typedef enum
         {
           pl_Think = 0x1,
pl_UnusedChopsticks = 0x2
         } tplace;
typedef PH int;;
                                                     typedef ph int;

typedef CS int;;
                                                     typedef cs int;

random_array Think;
multi_set UnusedChopsticks;
tranfunc tran_funcs[] = {TakeChopsticks,
PutDownChopsticks
      };
typedef enum 
      {
        tr_TakeChopsticks = 0x1,
tr_PutDownChopsticks = 0x2
      } ttran;
static const int n = 5;
System.Collections.Generic.IEnumerable[int-] Chopsticks(PH i)
                                                       {
                                                         return token_iter_utils.concat(token_iter_utils.repeat(cs(i), 1), token_iter_utils.repeat(cs(i == n ? 1 : i + 1), 1));
                                                       }
                                                       

              protected:
                      
      tran_func get_transition(int n) const
	    {
		    return tran_funcs[n];
	    }
      
              public:

              DiningPhilosophers(int time_step = 15) 
      { 
        Eat.add();
Think.add(PH.all());
UnusedChopsticks.add(CS.all());
        
      }
void TakeChopsticks()
            {
              if (lock(pl_Eat | pl_UnusedChopsticks | pl_Think))
              {
                 if (Think.have_tokens())
              {
                 int p_idx;
                                          PH p = Think.peek_indexed(p_idx);
 if (UnusedChopsticks.have(Chopsticks(p)))
                {
                  UnusedChopsticks.get(Chopsticks(p));
Think.get_indexed(p_idx);
;
Eat.add(p);
tran_ena(0, 0);
                }
              };
                unlock(pl_Eat | pl_UnusedChopsticks | pl_Think);
              }
            }
          
void PutDownChopsticks()
            {
              if (lock(pl_UnusedChopsticks | pl_Think | pl_Eat))
              {
                 if (Eat.have_tokens())
                {
                   int p_idx;
                                          PH p = Eat.peek_indexed(p_idx);
Eat.get_indexed(p_idx);
;
Think.add(p);
UnusedChopsticks.add(Chopsticks(p));
tran_ena(0, 0);
                };
                unlock(pl_UnusedChopsticks | pl_Think | pl_Eat);
              }
            }
          
            };
        