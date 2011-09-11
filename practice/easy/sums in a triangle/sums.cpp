#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;


/*
 * @author: Vikesh Khanna
 */

using namespace std;

int main()
{
ifstream in;
in.open(FILE);

uint n,t;
in>>t;

FOR(T,t)
{
        in>>n;
        uint maximum=0, a[n][n];
        FOR(i,n){
                 FOR(j,i+1)
                     in>>a[i][j];           
        }
        
        for(int i=1;i<n;i++){
                FOR(j,i+1)
                {
                     if(j==0) a[i][j] += a[i-1][j];
                     else if(j<i)a[i][j] += max(a[i-1][j],a[i-1][j-1]);
                     else a[i][j] +=  a[i-1][j-1];                               
                }        
        }
        
        
        FOR(j,n)
                if(a[n-1][j] > maximum) maximum = a[n-1][j];        

        printf("%d\n",maximum);
}

system("Pause");
return 0;
}
