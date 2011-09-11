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

#define INF -1
#define MAX 1000

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

inline bool compare(const pair<int,int>& a,const pair<int,int>& b)
{
        return a.first<b.first;

}

int main()
{
    int n,a[MAX][2], ans[MAX][MAX];
    fscanf(ifp,"%d",&n);

    FOR(i,n)
        {
                fscanf(ifp,"%d",&a[i][0]);
                a[i][1] = 1;
        }

    int count=0;
    FOR(i,n)
    {
        if(a[i][1]==1) //valid i
        {
            //cout<<"entered@ "<<i<<endl;

            int ptr = i, len=0;
            do{
                a[ptr][1] = 0;
                //cout<<"rep: "<<ptr<<endl;
                ans[count][len++]=ptr+1;
                ptr = a[ptr][0]-1;
            }while(ptr!=i);
            ans[count][len++] = i + 1;
            ans[count++][len] = -1;

        }
    }

    printf("%d\n",count);
    FOR(i,count)
    {
            int ptr=0;
            while(ans[i][ptr]!=-1)
                printf("%d ",ans[i][ptr++]);
            printf("\n");

    }

    //delete a;
    return 0;
}


