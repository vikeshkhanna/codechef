#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define MAX 65536
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

FILE* ifp = fopen("input.txt","r");
//FILE* ofp = fopen("output","w");



//FILE* ifp = stdin;
typedef long long unsigned int lint;

int main()
{
    int t, k;
    char str[MAX+1], ans[MAX+1];
    
    fscanf(ifp,"%d",&t);
    
    FOR(T,t)
    {
            fscanf(ifp,"%d",&k);       
            fscanf(ifp,"%s",str);       
            
            int n,x, len = (int)pow(2.0,k) ;
            
            FOR(i,len)
            {
                n = 0, x = i;
                
                FOR(j,k)
                {
                        n = 2*n;
                        n+= x&1;
                        x >>= 1;
                }
                
                ans[n] = str[i];    
                //cout<<"n : "<<n<<endl;        
            }
            
            ans[len] = 0;
            printf("%s\n",ans);
    }
    
    system("Pause");
    return 0;
}



