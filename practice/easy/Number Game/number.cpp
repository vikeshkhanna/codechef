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
//#include "../../../utility/utility.h"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

#define MAX 1000000


FILE* ifp = fopen(INPUT,"r");
//FILE* ofp = fopen("output","w");
//FILE* ifp = stdin;

int main()
{
    int t,n;
    fscanf(ifp,"%d",&t);

    FOR(i,t)
    {
            fscanf(ifp,"%d",&n);
            printf("%s\n",(n%2==0?"ALICE":"BOB"));
    }

    //delete a;
    return 0;
}



