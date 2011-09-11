#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<stdlib.h>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
using namespace std;

bool found=false;


int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

/*
 * @author: Vikesh Khanna
 */


uint find(uint* a, uint s,  uint sum,uint n, uint m)
{
     if(s<n)
          if(a[s]+sum<m){
                           if(!find(a,s+1,sum+a[s],n,m))  //include
                                               find(a,s+1,sum,n,m);   //do not include
                        }       
          else if(a[s]+sum==m) found=true;

    return (found==true ? 1:0);
}




int main()
{
ifstream in;
in.open(FILE);

uint t,n,m;
in>>t;

FOR(T,t)
{
         in>>n>>m;
         uint a[n];
         
         FOR(i,n)
                 in>>a[i];
         
         qsort(a,n,sizeof(uint),compare);
       
       /*  FOR(i,n)
                 cout<<a[i]<<" ";
         cout<<endl;
       */
       
         found = false;
         printf("%s",(find(a,0,0,n,m)==1) ? "Yes\n" : "No\n");         
}

system("Pause");
return 0;
}
