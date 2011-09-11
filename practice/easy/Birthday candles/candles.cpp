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
    int t, a[10],min,mini;
    fscanf(ifp,"%d",&t);

    FOR(T,t){
        min = 9;

        FOR(i,10)
        {
                  fscanf(ifp,"%d",&a[i]);
                  if(a[i]<min) {
                        min=a[i];
                        mini = i;
                }
        }

        if(mini==0)
        {
                FORS(i,1,10)
                    if(a[i]==min)
                        {
                                mini = i;
                                break;
                        }
        }

        if(mini==0){
                printf("1");
                FOR(i,min+1)
                    printf("0");
                printf("\n");
        }
        else
            {
                    FOR(i,min+1)
                        printf("%d",mini);
                    printf("\n");
            }
    }

    return 0;
}


