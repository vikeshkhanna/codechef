#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define MAX 708 //sqrt (500,000)
#define MOD 10000
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

FILE* ifp = fopen("input.txt","r");
//FILE* ifp = stdin;
//FILE* ofp = fopen("output","w");

typedef long long unsigned int lint;

/*sieve with only primes*/
/* Sieve of Erastrothenes */
int sieve(int primes[], int n) /* 1 to n, bool a[n+1] */
{
   if(n<1) return 0;
   
   bool a[n+1];
   
   for(int i=1;i<=n;i++)
        a[i] = true;

   a[1] = false;

   for(int i=2;i<=n;i++)
    {
        if(a[i]) //prime
        {
            int j=2;
            while(j*i<=n)
            {
                    a[j*i] = false;
                    j++;
            }
        }
    }
    
    int cnt=0;
    FORS(i,1,n+1)
    {
              if(a[i])
                  primes[cnt++]=i; 
    }   
    return cnt;
}



int main()
{
int n, t, primes[MAX+1], prod; //cnt = sieve(primes, MAX), prod;
fscanf(ifp,"%d",&t);
    
FOR(T,t)
{
  fscanf(ifp,"%d",&n);
  prod = 1;
  
  double d = sqrt(n);
  int dc = (int)d;
  
  FORS(i,2,dc+1)
  {
    if(!(n%i))
    {
              
              prod = (prod * i * (n/i==i ? 1 : n/i)) % MOD;
    }
  }
  
  if(prod>0)
            printf("%d\n",prod);
  else
  {
            printf("0000\n");
  }
}
  
system("Pause");
return 0;
}



