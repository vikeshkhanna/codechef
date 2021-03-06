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
#define INPUT "input"
#define MAX 50
#define FREE '.'
#define WALL '#'
#define BOX 'B'
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;


#include "../../../utility/utility.h"

FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int main()
{
    int t,len, a[MAX],b[MAX];
    char str[MAX+1], ans[MAX+1];

    fscanf(ifp,"%d",&t);

    FOR(T,t){
            fscanf(ifp,"%s",str);
            len = strlen(str);

            FOR(i,len)
                b[i] = str[i] - '0';

            int sol=0;

            FOR(count,4){
                    a[0] = count%2;
                    a[1] = (count>>1)%2;

                    for(int i=1;i<len-1;i++)
                        a[i+1] = b[i]^a[i-1]^a[i];

                    //print(a,len);
                    //cout<<endl;
                    if(a[len-2]^a[len-1]^b[len-1]==a[0] && a[len-1]^a[0]^a[1]==b[0])
                    {
                            if(sol++>0)
                                break;

                            FOR(i,len)
                                ans[i] = a[i] + '0';
                            ans[len] = 0;
                    }
            }

        if(sol==0)
            printf("No solution\n");
        else if(sol>1)
            printf("Multiple solutions\n");
        else
            printf("%s\n",ans);
     }
    //delete a;
    return 0;
}


