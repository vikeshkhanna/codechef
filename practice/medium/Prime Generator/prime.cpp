#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>


#define INPUT "test"
#define MAX 1000000
#define LIM 31623 //sqrt(10^9)
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

FILE* ifp = fopen(INPUT,"r");
FILE* ofp = fopen("output","w");

//FILE* ifp = stdin;

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


bool isprime(int x)
{
        int lim=sqrt(x);
        int i=2;

        for(;i<=lim;i++)
                if(x%i==0)
                    return false;
       return true;

}

int main()
{
    int t,m,n,count;
    bool prime[MAX+1];
    int ans[MAX+1];
    memset(prime,1,MAX+1);
    sieve(prime,MAX);
    /*FOR(i,MAX+1)
        cout<<i<<" "<<prime[i]<<endl;*/

    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        count=0;
        int j = MAX+1;
        fscanf(ifp,"%d%d",&m,&n);

        if(m<=MAX){
            for(int i=m;i<=n && i<=MAX;i++){
                    if(prime[i])
                    {
                        ans[count++] = i;
                    }
            }
        }
        else
            j=m;

        //cout<<(n-m<=100000)<<endl;
        //cout<<j<<" "<<n<<" "<<" "<<n-j<<" "<<j-m<<endl;
        for(;j<=n;j++)
        {
            //cout<<"Testing: "<<n-j<<endl;
            int k=2;
            for(;k<=LIM;k++)
                if(prime[k])
                    if(j%k==0) //Divisible, not prime
                        break;
            if(k==LIM+1)
                ans[count++]=j;
        }

        FOR(i,count){
            printf("%d\n",ans[i]);
            //sleep(1);
        }

        //for(int i=m;i<=n;i++)
          //  if(isprime(i)) fprintf(ofp,"%d\n",i);

        printf("\n");
    }
    //delete a;
    return 0;
}


