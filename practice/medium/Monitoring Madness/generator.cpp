#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<queue>
#include<algorithm>

#define OUTPUT "test"
#define MAX 1000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

#define MAXT 1000
#define MAXN 1000

FILE* ofp = fopen(OUTPUT,"w");
//FILE* ifp = stdin;

void print(int* a,int n)
{
        FOR(i,n)
            printf("%d ",a[i]);

    printf("\n");
}

int main()
{
    srand(time(NULL));
    int t = MAXT/2 + rand()%MAXT/2;
    fprintf(ofp,"%d\n",t);

    FOR(T,t)
    {
           int n = MAXN/2 + rand()%MAXN/2;
           fprintf(ofp,"%d\n",n);

           FOR(i,n)
                fprintf(ofp,"%c %c\n",(char)('A' + rand()%26), (char)('A' + rand()%26));

    }

    return 0;
}

