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
#define MAX 1000

#define WHITE 0
#define GRAY 1
#define BLACK 2

//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

void dfs_visit(const char a[MAX][MAX],int val[MAX][MAX],int r,int c,int n)
{

    //cout<<"("<<r<<","<<c<<")"<<" : "<<endl;
    val[r][c]=0;


    if(r>1 && c<n-1){
        if(val[r-2][c+1]==-1)
            dfs_visit(a,val,r-2,c+1,n);

        if(val[r-2][c+1]>val[r][c])
            val[r][c] = val[r-2][c+1];
    }


    if(r>0 && c<n-2)
    {
        if(val[r-1][c+2]==-1)
               dfs_visit(a,val,r-1,c+2,n);

        if(val[r-1][c+2]>val[r][c])
            val[r][c]= val[r-1][c+2];
    }

    if(r<n-1 && c<n-2)
    {
        if(val[r+1][c+2]==-1)
                dfs_visit(a,val,r+1,c+2,n);

        if(val[r+1][c+2]>val[r][c])
            val[r][c] = val[r+1][c+2];
    }

    if(r<n-2 && c<n-1)
    {
        if(val[r+2][c+1]==-1)
            dfs_visit(a,val,r+2,c+1,n);

        if(val[r+2][c+1]>val[r][c])
            val[r][c] = val[r+2][c+1];
    }

    if(a[r][c]=='P') val[r][c]++;
}

/* Depth first search with 2D matrix*/
int dfs(const char a[MAX][MAX],const int sr, const int sc, const int n)
{
    int val[MAX][MAX],max=0;

    FOR(i,n)
        FOR(j,n)
            val[i][j]=-1;

    dfs_visit(a,val,sr,sc,n);
    return val[sr][sc];

    FOR(i,n){
        FOR(j,n)
            cout<<val[i][j]<<" ";
        cout<<endl;
    }
}


int main()
{
    int t,n,sr,sc;
    char str[MAX+1],a[MAX][MAX];
    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
        fscanf(ifp,"%d",&n);

        FOR(i,n)
            {
                    fscanf(ifp,"%s",str);

                    FOR(j,n){
                            if((a[i][j] = str[j])=='K'){
                                sr = i, sc=j;
                            }
                    }
            }
            printf("%d\n",dfs(a,sr,sc,n));

    }


    return 0;
}
