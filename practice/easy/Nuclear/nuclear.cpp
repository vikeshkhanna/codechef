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
#define INPUT "input"
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

#define MAX 100
#define MAXID 2147483648U
FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

inline bool compare(int a,int b)
{
        return a<b;

}

int main()
{
    int a,n,k,ptr=0,ans[MAX];
    memset(ans,0,sizeof(int)*MAX);

    fscanf(ifp,"%d%d%d",&a,&n,&k);
    n++;

    while(a>0 && ptr<k)
    {
        ans[ptr] = a%n;
        a = (a - a%n)/n;
        ptr++;
    }

    FOR(i,k)
        printf("%d\n",ans[i]);

    return 0;
}



