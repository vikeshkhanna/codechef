#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "output.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;


/*
 * @author: Vikesh Khanna
 */

int main()
{
ifstream in;
in.open(FILE);
int t,n;
in>>t;

FOR(T,t)
{
        in>>n;
        uint a[n], b[n];
        
        FOR(i,n) in>>a[i];
        FOR(i,n) b[i]=i+1;
        
        for(int i=n-1;i>=0;i--){
                uint j = i-a[i];
                uint key = b[j];
                for(int k=j;k<i;k++)
                        b[k] = b[k+1];
                        
                b[i] = key;
        }
        
        FOR(i,n)
                printf("%d ",b[i]);
        printf("\n");
}


system("Pause");
return 0;
}
