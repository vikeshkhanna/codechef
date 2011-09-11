#include<iostream>
#include<stdio.h>
#include<fstream>

#define FILE "input"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
using namespace std;

/* @author: Vikesh Khanna
*/

int main()
{
ifstream in;
in.open(FILE);
uint t,n;
in>>t;

FOR(T,t)
{
    in>>n;
    char x[n][n],y[n][n],rc[n][n];

    FOR(i,n)
        FOR(j,n)
            in>>x[i][j];

    FOR(i,n)
        FOR(j,n)
            in>>y[i][j];

    FOR(i,n)
        FOR(j,n)
            rc[i][j] = x[i][j]^y[i][j];

    /*FOR(i,n){
            FOR(j,n)
                printf("%d ",rc[i][j]);
            printf("\n");
    }*/
    char r[n],c[n];
    r[0] = 0;

    FOR(i,n)
        c[i] = rc[0][i];

    int i=1;
    int j=1;

    for(i=1;i<n;i++){
            r[i] = c[0]^rc[i][0];

            for(j=1;j<n;j++)
                    if(c[j]^rc[i][j]!=r[i]) break;

            if(j!=n)
                break;
    }

    if(j!=n || i!=n) printf("-1\n");
    else
    {
            uint rcount=0, ccount = 0;
            FOR(i,n){
                 rcount+=r[i]; ccount+=c[i];
            }
            if(rcount+ccount==0)
                    printf("0\n");
            else  if(rcount+ccount<=n){
                    printf("%d\n",rcount);
                    FOR(i,n) if(r[i]) printf("%d\n",i);
                    printf("%d\n",ccount);
                    FOR(i,n) if(c[i]) printf("%d\n",i);
            }
            else
            {
                    printf("%d\n",n-rcount);
                    FOR(i,n) if(!r[i]) printf("%d\n",i);
                    printf("%d\n",n-ccount);
                    FOR(i,n) if(!c[i]) printf("%d\n",i);
            }
    }
}



return 0;
}
