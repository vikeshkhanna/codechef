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
typedef long unsigned int lint;
/*
 * @author: Vikesh Khanna
 */

using namespace std;

int main()
{
lint x,n,t,a[MAX+1],count;
scanf("%ld",&t);

a[0]=1;
for(int i=1;i<=MAX;i++) a[i] = a[i-1]*2;


FOR(T,t){
         scanf("%ld",&n);
         lint i=0;
         while(n>a[i]) i++;    
         
         if(i!=0) i--;
         printf("%ld\n",a[i]);
}

system("Pause");
return 0;
}
