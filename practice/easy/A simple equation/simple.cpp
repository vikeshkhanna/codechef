#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define MAX 65536
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

FILE* ifp = fopen("input.txt","r");
//FILE* ofp = fopen("output","w");

//FILE* ifp = stdin;
typedef long long unsigned int lint;

int main()
{
    int t, n, a, b, c;
    fscanf(ifp,"%d",&t);
    
FOR(T,t)
{
  fscanf(ifp,"%d %d %d %d",&n,&a,&b,&c);
  int l1 = min(a,n) + 1;
  lint cnt = 0;
  
  FOR(i,l1)
  {
           int l2 = min(b, n - i) +  1;
           
           FOR(j,l2)
           {
                      cnt += min(c, n - (i+j)) + 1;                 
           }         
  }          
  printf("%llu\n",cnt);
}
    
system("Pause");
return 0;
}



