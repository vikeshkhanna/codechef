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
    int n, a[MAX];
    fscanf(ifp,"%d",&n);

    while(n!=0)
    {
        FOR(i,n)
            fscanf(ifp,"%d",&a[i]);

        sort(a,a+n);
        int count=0;

        FOR(i,n)
        {
              int ip = i+1,low,high,mid;

              FORS(j,ip,n-1)
              {
                  /* Binary search from j+1 to n*/
                  low=j+1, high = n-1, mid;

                  while(low<high)
                  {
                        mid = (low+high)/2;

                        if(a[i]+a[j]>=a[mid])//degenerate triangles are allowed
                            low=mid+1;
                        else
                            high = mid;
                  }

                  count = count + n-low + (a[i]+a[j]>=a[low]?-1:0);
              }
        }
        printf("%d\n",count);
        fscanf(ifp,"%d",&n);
    }

    return 0;
}


