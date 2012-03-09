#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef unsigned int uint;

int main()
{
uint t,n,r, k, len;
cin>>t;

FOR(T,t)
{
       cin>>k;
       n = k/25;
       r = k%25;
       
       if(r!=0) r++;
       
       FOR(i,r)
               printf("%c",'a'+r-1-i); 
      
       FOR(i,n)
               FOR(j,26)
                   printf("%c",'z'-j);
                   
       printf("\n");
}

system("Pause");
return 0;
}
