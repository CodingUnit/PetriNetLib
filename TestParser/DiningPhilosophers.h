class DiningPhilosophers : public petri_net
            {
              typedef PH int;;
                                                     typedef ph int;

typedef CS int;;
                                                     typedef cs int;

random_array Eat;
random_array Think;
multi_set UnusedChopsticks;
static const int n = 5;
System.Collections.Generic.IEnumerable[int-] Chopsticks(PH i)
                                                       {
                                                         return token_iter_utils.concat(token_iter_utils.repeat(cs(i), 1), token_iter_utils.repeat(cs(i == n ? 1 : i + 1), 1));
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
              if (lock(TakeChopsticks))
              {
                  
              if (Think.have_tokens())
              {
                 int p_idx;
                                          PH p = Think.peek_indexed(p_idx);
                  
              if (UnusedChopsticks.have(Chopsticks(p)))
              {
                
                UnusedChopsticks.get(Chopsticks(p));
Think.get_indexed(p_idx);

Eat.add(p);
                
              }
          
              }
          ;
                unlock();
              }
            }
          
void PutDownChopsticks()
            {
              if (lock(PutDownChopsticks))
              {
                  
              if (Eat.have_tokens())
              {
                 int p_idx;
                                          PH p = Eat.peek_indexed(p_idx);
                Eat.get_indexed(p_idx);

Think.add(p);
UnusedChopsticks.add(Chopsticks(p));
                
              }
          ;
                unlock();
              }
            }
          
            };
        