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
#define MAX 100000

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

inline bool compare(const pair<int,int>& a,const pair<int,int>& b)
{
        return a.first<b.first;

}

int main()
{
    int t,n,x[MAX][3];
    pair<int,int> a[MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%d",&n);

            FOR(i,n)
                fscanf(ifp,"%d%d",&a[i].first,&a[i].second);

            sort(&a[0],&a[0]+n,compare);

            //FOR(i,n)cout<<a[i].first<<" "<<a[i].second<<endl;

            int ptr=0,dist=0,count=0;

            while(ptr<n)
            {
                   int miny, maxy;
                   int now = x[count][0]  = a[ptr].first;
                   miny = maxy = a[ptr].second;

                   do
                    {
                        if(a[ptr].second<miny) miny = a[ptr].second;
                        if(a[ptr].second>maxy) maxy = a[ptr].second;
                        ptr++;
                    }while(ptr<n && a[ptr].first==now);

                    x[count][1] = miny;
                    x[count][2] = maxy;
                    count++;
            }

            double sum=0;
            FOR(i,count)
            {
                    //cout<<x[i][0]<<" "<<x[i][1]<<" "<<x[i][2]<<endl;
                    sum+= x[i][2] - x[i][1];

                    if(i+1<count){
                            int difx = x[i+1][0] - x[i][0], dify = x[i+1][2] - x[i][1];
                            sum+=   sqrt(difx*difx + dify*dify);
                    }
            }
            printf("%0.2f\n",sum);
    }
    //delete a;
    return 0;
}


