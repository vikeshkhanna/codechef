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

#define MAXN 100
#define MAXQ 100
#define MAXFE 10
#define MAXFN 50
#define MAXMT 50



//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int main()
{
    int n,q;
    char e[MAXN][MAXFE+1], mt[MAXN][MAXMT+1];
    char str[MAXFN + MAXFE+1];


    fscanf(ifp,"%d %d",&n,&q);

    FOR(i,n)
        fscanf(ifp,"%s%s",&e[i],&mt[i]);
        //cout<<e[i]<<" "<<mt[i]<<endl;
    FOR(i,q)
    {
            fscanf(ifp,"%s",str);
            char ext[MAXFN + MAXFE + 1];
            int count=0,j=0;
            bool found=false;

            while(str[j])
            {
                if(str[j]=='.') { count=0; found=true;}
                else ext[count++]=str[j];
                j++;
            }
            ext[count]=0;

            if(found)
            {
                found=false;
                FOR(i,n){
                        if(!strcmp(ext,e[i])) {
                                printf("%s\n",mt[i]);
                                found=true;
                                break;
                        }
                }
            }

            if(!found)
                    printf("unknown\n");

            //cout<<str<<endl;
    }


    return 0;
}
