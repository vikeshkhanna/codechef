#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)

#define LIM (unsigned int)pow(10.0,7.0)

using namespace std;

unsigned int cache[10000000] = {0};

unsigned coins(unsigned n)
{
         if(n==0 || n==1 ) return n;
         
         if(n<LIM && cache[n]!=0) return cache[n];
             
          unsigned ans = coins(n/2) + coins(n/3) + coins(n/4);
      
                            if(n>ans)
                                        ans=n;          
                            if(n<LIM)
                               cache[n] = ans;
                               
        return ans;
} 


int main()
{

unsigned n;
int out=1;

while(out>0)
{
       out = scanf("%u",&n);
       
       if(out>0)
                printf("%u\n",coins(n));
}


system("Pause");
return 0;
}
