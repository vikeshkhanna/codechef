#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;


/* 0 - Empty 1st.
1- Empty second.
2 - Fill 1st by pump
3- Fill 2nd by pump
4 - From 1st to 2nd
5 - From 2nd to 1st
Kill the node when there is no further exapnsion possible - BFS
*/

class State
{
      public:
             int a; //First jug;
             int b; //Second jug;
             State* parent;
             
      State(int a, int b, State* parent)
      {
                 this->a = a;
                 this->b = b;
                 this->parent= parent;
      }   
      
      void operator=(const State& S)
      {
           this->a = S.a;
           this->b = S.b;  
      }
      
      bool operator!=(const State* S)
      {
            if(this==NULL && S==NULL) return false;
           
            if(this!=NULL && S==NULL) return true;
           
           
           if(this->a==S->a && this->b==S->b)      
                           return false;
           else 
                           return true;                     
      }
      
       bool operator==(const State* S)
      {
           if(this==NULL && S==NULL) return true;
           
           if(this!=NULL && S==NULL) return false;
           
           if(this->a==S->a && this->b==S->b)      
                           return true;
           else 
                           return false;              
      }
      
      friend ostream& operator<<(ostream& out, const State* S)
      {
                      return out<<"("<<S->a<<","<<S->b<<")";    
      }
      
};


int findSteps(int, int , int);


int main()
{
int t;
cin>>t;

vector<int> a(t);
vector<int> b(t);
vector<int> c(t);

    for(int i=0; i<t;i++)
    {
            int ai,bi,ci;
            cin>>ai>>bi>>ci;
            
            a[i] =ai; b[i]=bi; c[i] = ci;
    }


 for(int i=0; i<t;i++)
    {
         cout<<findSteps(a[i],b[i],c[i])<<endl;
    }

system("Pause");
return 0;
}

bool isAllowed(State* S, const vector<const State*>& V)
{
     int len= V.size();
     
     for(int i=0;i<len;i++)
             if(*S==V[i]) return false;
     
     return true;
}


int findSteps(int a, int b, int c)
{
    //Desired states are (c,x) and (x,c)
    queue<State*> Q;
    vector<const State*> V;
    
    State* state = new State(0,0,NULL);
    
    if(c>a && c>b) return -1;
    
    
    Q.push(state);
    V.push_back(state);
    
    while(Q.size()!=0)
    {
                    state = Q.front();
                    
                    if(state->a==c || state->b == c)
                                       break;
                     
                    
                     Q.pop();
                  
                     //cout<<state; cout<<endl;
                    
                       //0 - Empty first  
                            if(state->a!=0)
                                    {
                                                   State* new_state = new State(0,state->b,state);
                                                   
                                                   if(isAllowed(new_state,V))
                                                          {
                                                                              Q.push(new_state);                                        
                                                                              V.push_back(new_state);
                                                          }
                                    }
                    
                     //1 - Empty second
                            if(state->b!=0)       {
                                                   State* new_state = new State(state->a,0,state);                       
                                                  
                                                   if(isAllowed(new_state,V))
                                                          {
                                                                              Q.push(new_state);                                        
                                                                              V.push_back(new_state);
                                                          } 
                                   }     
                     
                    if(state->a<a)  //2- Fill first by pump
                                   {   
                                         State* new_state = new State(a,state->b,state);                       
                                               
                                               if(isAllowed(new_state,V))
                                                          {
                                                                              Q.push(new_state);                                        
                                                                              V.push_back(new_state);
                                                          } 
                                   }
                                   
                    
                    if(state->b<b) //3- Fill second by Pump
                                   {
                                          State* new_state = new State(state->a,b,state);                       
                                               
                                               if(isAllowed(new_state,V))
                                                          {
                                                                              Q.push(new_state);                                        
                                                                              V.push_back(new_state);
                                                          } 
                                   }
                    
                    if(state->b<b && state->a!=0) //4 - Transfer from 1st to second
                                  {
                                              int temp1, temp2;
                                              
                                              if(state->a >= b-state->b)
                                                                     {
                                                                          temp1 = state->a - (b-state->b);
                                                                          temp2 = b;
                                                                     }
                                              else
                                                  {
                                                                     temp1 = 0;
                                                                     temp2 = state->b + state->a;                  
                                                  }
                                              
                                              State* new_state = new State(temp1,temp2,state);                       
                                               
                                               if(isAllowed(new_state,V))
                                                          {
                                                                              Q.push(new_state);                                        
                                                                              V.push_back(new_state);
                                                          }    
                                  }
                    
                    
                          if(state->a<a && state->b!=0) //5 - Transfer from 2nd to 1st
                                  {
                                              int temp1, temp2;
                                              
                                              if(state->b>=a-state->a)
                                                                     {
                                                                          temp2 = state->b - (a-state->a);
                                                                          temp1 = a;
                                                                     }
                                              else
                                                  {
                                                                     temp1 = state->a + state->b;
                                                                     temp2 = 0;               
                                                  }
                                              
                                              State* new_state = new State(temp1,temp2,state);                       
                                               
                                               if(isAllowed(new_state,V))
                                                          {
                                                                              Q.push(new_state);                                        
                                                                              V.push_back(new_state);
                                                          }    
                                  }
            }
       
       int count=0;
       stack<State* > stack_states;
       
       if(Q.size()==0) return -1; //Not possible to reach
       
       while(state->parent!=NULL)   //Can reach in count number of steps
                                {
                                  //cout<<state; cout<<endl;
                                  count++;       
                                  stack_states.push(state);                   
                                  state=state->parent;
                                }  
       
       stack_states.push(state);                   
                                   
       while(stack_states.size()!=0)
                             {
                                    cout<<stack_states.top(); cout<<endl;
                                    stack_states.pop(); 
                             }
       return count; 

}

