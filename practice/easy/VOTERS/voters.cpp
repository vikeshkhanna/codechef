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

#define MAX 50000
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
    unsigned int a1[MAX+1],a2[MAX+1],a3[MAX+1];
    int n1,n2,n3,ans[3*MAX];

    fscanf(ifp,"%d%d%d",&n1,&n2,&n3);

    FOR(i,n1)
        fscanf(ifp,"%u",&a1[i]);

    FOR(i,n2)
        fscanf(ifp,"%u",&a2[i]);

    FOR(i,n3)
        fscanf(ifp,"%u",&a3[i]);

    a1[n1] = MAXID;
    a2[n2]=MAXID;
    a3[n3]=MAXID;

    sort(a1,a1+n1,compare);
    sort(a2,a2+n2,compare);
    sort(a3,a3+n3,compare);

    int largest = n1, p1=0,p2=0,p3=0, count=0;

    while(p1<n1 || p2<n2 || p3<n3)
    {
        /* 6 possible combinations */
        if(p1<n1 && p2<n2 && p3<n3 && a1[p1]==a2[p2]==a3[p3])
        {
                ans[count++] = a1[p1];
                p1++, p2++, p3++;
        }
        else if(p1<n1 && p2<n2 && a1[p1]==a2[p2])
        {
                ans[count++] = a1[p1];
                p1++; p2++;
        }
        else if(p1<n1 && p3<n3 && a1[p1]==a3[p3])
        {
                ans[count++] = a1[p1];
                p1++, p3++;
        }
        else if(p2<n2 && p3<n3 && a2[p2]==a3[p3])
        {
                ans[count++] = a2[p2];
                p2++, p3++;
        }
        else
        {
                if(a1[p1]<a2[p2])
                {
                        if(a1[p1]<a3[p3]) p1++;
                        else p3++;
                }
                else
                {
                        if(a2[p2]<a3[p3]) p2++;
                        else p3++;
                }

        }
    }

    printf("%d\n",count);
    FOR(i,count)
        printf("%u\n",ans[i]);

    return 0;
}


