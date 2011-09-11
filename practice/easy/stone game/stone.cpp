#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>


#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2
#define PARENT(i) i/2

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;

/*
 * @author: Vikesh Khanna
 */
template<class T>
class MinHeap
{
      public:
            T* a;
            uint size;
            uint max;
            
            MinHeap(uint max, T* arr=NULL, uint s=0) {
                        size = s;
                        this->max = max;
                        a = new T[max];
                        
                        if(arr!=NULL){
                            FOR(i,s)
                                   a[i] = arr[i];
                            buildHeap();
                        }
            } 
            
           void buildHeap(){
                 for(int i=size/2;i>=0;i--){
                         heapify(i);   
                 }            
            }
            
            void heapify(uint i)
            {
                 while(true)
                 {
                     uint smallest = i;
                     uint left = LEFT(i), right = RIGHT(i);
                     
                     if(left<size && a[left]<a[i]) smallest = left;
                     if(right<size && a[right]<a[smallest]) smallest = right;
                     
                     if(smallest!=i)
                     {
                               T val = a[smallest];    
                               a[smallest] = a[i];
                               a[i] = val;                             
                               i = smallest;
                     }else break;
                 }
            }
            
            void extract_min(T& ret)
            {
                           if(!isEmpty()){
                                           ret = a[0];
                                           a[0]=a[size-1];
                                           size--;
                                           heapify(0);
                           }
            } 

            void insert(T val)
            {
                     if(!isFull())
                     {
                               T* newnode = new T;
                               *newnode = val;
                               size++;
                               a[size-1]=*newnode;
                               uint i = size-1;
                               while(a[PARENT(i)]>a[i]){
                                             T sw = a[i];    
                                             a[i] = a[PARENT(i)];
                                             a[PARENT(i)] = sw;   
                                             i = PARENT(i);
                               }
                     }
            }
                 
            bool isEmpty() {return size==0;}
            bool isFull() {return size==max;}
};


/* pair class */
class Pair
{
      public:
       uint num,index;     
      
      bool operator>(const Pair& b)
      {
           if(num>b.num) return true;
           else return false;
      }
      
      bool operator<( const Pair& b)
      {
           if(num<b.num) return true;
           else return false;
      }
      
      void operator=(const Pair& a)
      {
           num = a.num;
           index = a.index;
      }
      
      friend ostream& operator<<(ostream& out,const Pair& a);
};

ostream& operator<<(ostream& out,const Pair& a)
{
         return out<<"("<<a.index+1<<" "<<a.num<<")";         
}      

int main()
{
ifstream in;
in.open(FILE);

uint n,t;
in>>t;

FOR(T,t)
{
        in>>n;
        MinHeap<Pair> Q(n);
       
        FOR(i,n)
                {
                      Pair pile;
                      pile.index = i;
                      in>>pile.num;
                      if(pile.num>=pile.index+1) Q.insert(pile);
              }
              
        //FOR(i,Q.size) cout<<Q.a[i]<<" "; cout<<endl;

        /*Algorithm */
        uint turns=0; // even count = bob;
        
        while(!Q.isEmpty())
        {
                     Pair pile;
                     Q.extract_min(pile);
                     pile.num  = pile.num - (pile.index + 1);
                     
                     if(pile.num>pile.index)
                                            Q.insert(pile);                       
                     turns++;
                     printf("After turn %d, %s : ", turns, turns%2==0 ? "Bob": "Alice"); FOR(i,Q.size) cout<<Q.a[i]<<" "; cout<<endl;
        }
        
        if(turns%2==0) printf("BOB\n");
        else printf("ALICE\n"); 
}

system("Pause");
return 0;
}
