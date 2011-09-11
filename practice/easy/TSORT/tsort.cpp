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
#define MAX 10
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

#define MAX 1000000

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int compare(const void* a, const void* b)
{
        return *(int*)a - *(int*)b;

}

int main()
{
    int t, a[MAX];
    fscanf(ifp,"%d",&t);

    FOR(i,t)
        fscanf(ifp,"%d",&a[i]);

    qsort(a,t,sizeof(int),compare);

    FOR(i,t)
        printf("%d\n",a[i]);

    //delete a;
    return 0;
}


