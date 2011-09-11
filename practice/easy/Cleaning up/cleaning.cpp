#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<cstring>


#define INPUT "input"
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000

typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;

FILE* ifp= fopen(INPUT,"r");
//FILE* ifp = stdin;

int main()
{
int t,n,m,temp;
bool a[MAX+1];
int u[MAX+1];

fscanf(ifp,"%d",&t);

FOR(T,t)
{
        fscanf(ifp,"%d%d",&n,&m);

        FOR(i,n+1)
            a[i] = true;

        FOR(i,m)
            {
                    fscanf(ifp,"%d",&temp);
                    a[temp]=false;
            }

        int c=0;
        for(int i=1;i<=n;i++)
             if(a[i]){
                u[c++]=i;
             }
        //FOR(i,c)
          //  printf("%d ",u[i]);

        FOR(i,c)
           if(i%2==0) printf("%d ",u[i]);

        printf("\n");

        FOR(i,c)
            if(i%2!=0) printf("%d ",u[i]);

        printf("\n");

}

//system("Pause");
return 0;
}
