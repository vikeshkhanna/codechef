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
#include<algorithm>
#include<cstring>
#define INPUT "input"
#define MAX 30
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int main()
{
    int t,n,w[MAX],l[MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
        fscanf(ifp,"%d",&n);

        FOR(i,n)
                fscanf(ifp,"%d",&w[i]);

        FOR(i,n)
                fscanf(ifp,"%d",&l[i]);

        sort(w,w+n);
        sort(l,l+n);

        int ptr1=0, ptr2=0, count=0;

        while(ptr1<n && ptr2<n)
        {
            if(w[ptr1]<=l[ptr2])
                {
                        ptr1++;
                        ptr2++;
                        count++;
                }
            else
                ptr2++;
        }
        printf("%d\n",count);
    }
    return 0;
}


