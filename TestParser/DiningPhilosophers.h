class DiningPhilosophers : public petri_netTrue
            {
              typedef enum
         {
           pl_Eat = 0x1,
pl_Think = 0x2,
pl_UnusedChopsticks = 0x4
         } tplace;
typedef PH int;;
                                                     typedef ph int;

typedef CS int;;
                                                     typedef cs int;

random_array Eat;
random_array Think;
multi_set UnusedChopsticks;



      typedef enum 
      {
        tr_TakeChopsticks = 0x1,
tr_PutDownChopsticks = 0x2
      } ttran;

      tran_func tran_funcs[] = {TakeChopsticks,
PutDownChopsticks
      };
      
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
        Think.add(PH.all());
UnusedChopsticks.add(CS.all());
        
      }


bool TakeChopsticks()
            {
              bool res = false;
              if (lock(pl_Eat | pl_UnusedChopsticks | pl_Think, tr_TakeChopsticks))
              {
                 if (UnusedChopsticks.have(Chopsticks(p)))
              {
                 if (Think.have_tokens())
                {
                   int p_idx;
                                          PH p = Think.peek_indexed(p_idx);
Think.get_indexed(p_idx);
UnusedChopsticks.get(Chopsticks(p));
;
Eat.add(p);
res = true;
                }
              };
                unlock(pl_Eat | pl_UnusedChopsticks | pl_Think);
              }
              return res;
            }
          
bool PutDownChopsticks()
            {
              bool res = false;
              if (lock(pl_UnusedChopsticks | pl_Think | pl_Eat, tr_PutDownChopsticks))
              {
                 if (Eat.have_tokens())
                {
                   int p_idx;
                                          PH p = Eat.peek_indexed(p_idx);
Eat.get_indexed(p_idx);
;
Think.add(p);
UnusedChopsticks.add(Chopsticks(p));
res = true;
                };
                unlock(pl_UnusedChopsticks | pl_Think | pl_Eat);
              }
              return res;
            }
          
            };
        