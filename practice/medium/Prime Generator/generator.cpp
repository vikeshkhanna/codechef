#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<queue>
#include<cmath>


#define OUTPUT "test"
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

#define MAXT 10
#define MAX 1000000000

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
    int t;
    t=10;
    //t = MAXT/2 + rand()%MAXT/2;
    fprintf(ofp,"%d\n",t);

    FOR(T,t){
            int m = MAX/2 + rand()%MAX/2;
            int n = m + rand()%100000;

            fprintf(ofp,"%d %d ",m,n);
            fprintf(ofp,"\n");
    }

    return 0;
}

