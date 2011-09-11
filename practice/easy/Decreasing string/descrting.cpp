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
#define MAX 2000
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)

using namespace std;

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int main()
{
    int t,k;
    fscanf(ifp,"%d",&t);

    FOR(T,t)
    {
            fscanf(ifp,"%d",&k);

            int iter = k/25, last = k%25;


            if(last>0)
            {
                int s = 'a' + last;

                while(s>='a')
                {
                        printf("%c",s);
                        s--;
                }
            }

            FOR(i,iter)
            {
                    FOR(i,26)
                        printf("%c",'z'-i);
            }

            printf("\n");

    }
    return 0;
}



