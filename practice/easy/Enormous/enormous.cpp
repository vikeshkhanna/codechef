#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<cmath>
#define INPUT "input"
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

#define MAX 1000000


FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

/* Sieve of Erastrothenes */
void sieve(bool a[],int n) /* 1 to n, bool a[n+1] */
{
   if(n<1) return;

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
    int n,k,x,count=0;
    bool a[MAX+1];
    fscanf(ifp,"%d%d",&n,&k);
    sieve(a,MAX);

    FOR(i,n)
    {
            fscanf(ifp,"%d",&x);
            if((x>MAX || !a[x]) && x%k==0) count++;
    }

    printf("%d\n",count);
    //delete a;
    return 0;
}



