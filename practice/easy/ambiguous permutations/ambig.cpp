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

uint n;
in>>n;
  

do{
  uint i=0,a[n];
 
  FOR(i,n)
        in>>a[i];         
 
  for(;i<n;i++)
          if(a[a[i]-1]!=i+1) break;
  
  if(i==n) printf("ambiguous\n");
  else printf("not ambiguous\n");
  in>>n;
}while(n!=0);

system("Pause");
return 0;
}
