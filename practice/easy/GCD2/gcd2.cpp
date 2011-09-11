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
#define MAX 251
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

#define INF -1

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int gcd(int r0,int r1)
{
    int temp;

    if(r1==0) return r0;
    else if(r0==0) return r1;

    if(r0<r1)
              {
                   temp = r0;
                   r0 = r1;
                   r1=temp;
              }

    //r0 is the larger number and r1 is the smaller number
    int remainder;

    do{
        remainder = r0%r1;

        r0=r1;
        r1=remainder;
        }while(remainder!=0);

    return r0;
}


int main()
{
    int t,a;
    char str[MAX+1];
    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
            fscanf(ifp,"%d",&a);
            fscanf(ifp,"%s",str);

            //cout<<str<<endl;

            int len = strlen(str), ptr=0, sum=0;

            while(ptr<len || sum>=a)
            {
                if(sum>=a)
                        sum = sum-(sum/a)*a;
                else sum = sum*10 + str[ptr++] - '0';
            }
        //cout<<sum<<endl;
        printf("%d\n",gcd(a,sum));
    }

    //delete a;
    return 0;
}


