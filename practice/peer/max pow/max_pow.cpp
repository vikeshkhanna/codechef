#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define MAX 1000001
#define LIM 31623 //sqrt(10^9)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

FILE* ifp = fopen("input.txt","r");
//FILE* ofp = fopen("output","w");

//FILE* ifp = stdin;
typedef long long unsigned int lint;


/* Sieve of Erastrothenes */
void sieve(bool a[],int n) /* 1 to n, bool a[n+1] */
{
   if(n<1) return;

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
}

int main()
{
    int t;
    bool* a = (bool*)malloc(MAX*sizeof(bool));
    int* primes = new int[MAX];
    int cnt = 0;
    sieve(a,MAX);
    
    FORS(i,1,MAX)
    {
              if(a[i])
                  primes[cnt++]=i; 
    }    
    
    //FOR(i,cnt) cout<<primes[i]<<endl;    
    //cout<<cnt<<endl;
    //cout<<primes[0]<<endl;
    lint x, y, z;
    
    fscanf(ifp,"%d",&t);
    
    FOR(T,t)
    {
            fscanf(ifp, "%llu %llu %llu",&x,&y,&z);
            
            lint n = x*y, p;
            int i=0, sim=1, last=-1;
            
            while(z>1 && i<cnt)
            {
                  if(!(z%primes[i]))  
                  {  
                      if(last!=i)
                      {
                                 sim = 0;
                                 last = i;           
                      }
                      z /= primes[i]; 
                      sim++;                                     
                  }
                  else
                  {
                      i++;
                  }
            }
            
            p = (z==1 ? primes[last] : z);
            sim = (z!=1 ? 1 : sim);
            
            lint ans = 0;
            
            while(n>0)
            {
                      ans+= n/p;
                      n = n/p;
            }     
            //cout<<sim<<endl;
            printf("%llu\n",ans/sim);   
    }
    
    system("Pause");
    return 0;
}



