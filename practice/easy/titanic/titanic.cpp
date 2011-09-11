#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define MAX 30
#define FOR(i,n) for(int i=0;i<n;i++)
typedef long unsigned int uint;
/*
 * @author: Vikesh Khanna
 */

using namespace std;

int main()
{
ifstream in;
in.open(FILE);

uint x,n,t,a[MAX+1],count;
in>>t;

a[0]=1;
for(int i=1;i<=MAX;i++) a[i] = a[i-1]*2;



FOR(T,t){
         in>>n;
         uint i=0;
         while(n>a[i]) i++;    
         
         if(i!=0) i--;
         printf("%ld\n",a[i]);
         
}

system("Pause");
return 0;
}
