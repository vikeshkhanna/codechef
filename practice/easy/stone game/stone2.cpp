#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;


/*
 * @author: Vikesh Khanna
 */

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
         return out<<"("<<a.index<<" "<<a.num<<")";         
} 

int compare(const void* a, const void* b)
{
   int num = ((Pair*)a)->num - ((Pair*)b)->num;
   return num;
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
        Pair piles[n];
        
        uint stones, count=0;
        
        FOR(i,n)
        {
                in>>stones;
                
                if(stones>=i+1)
                    {
                               piles[count].index = i+1;
                               piles[count].num = stones;
                               count++;
                    }
        }        
    
        qsort(piles,count,sizeof(Pair),compare);
        //FOR(i,count) cout<<piles[i]<<" ";
        uint turns = 0;
        FOR(i,count)
                {
                       uint index = piles[i].index;
                       uint num = piles[i].num;
                        turns += num/index;
                }
        printf("%s",turns%2==0 ? "BOB\n":"ALICE\n");
}

system("Pause");
return 0;
}
