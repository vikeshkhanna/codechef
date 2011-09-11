#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)

#define LIM (unsigned int)pow(10.0,8.0)

using namespace std;

unsigned int cache[LIM] = {0};

unsigned coins(unsigned n)
{
         if(n==0 || n==1 ) return n;
         
         if(n<LIM && cache[n]!=0) return cache[n];
             
         if(((unsigned int)n/2 + (unsigned int)n/3 + (unsigned int)n/4) > n)
                               {
                                   unsigned ans = coins(n/2) + coins(n/3) + coins(n/4);
                                   
                                   if(n<LIM)
                                     cache[n] = ans;
                                    
                                   return ans;
                               }
         else return n;
} 


int main()
{
ifstream in;
in.open(FILE);

unsigned n;

while(in.eof())
{
       in>>n;
       cout<<coins(n)<<"\n";
       
       
}


system("Pause");
return 0;
}
