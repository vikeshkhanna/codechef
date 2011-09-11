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
int w,l=0,n,x,y,z=0;
scanf("%d",&n);

FOR(i,n){
         scanf("%d",&x);
         scanf("%d",&y);
         z += x-y;
         
         if(z>l) { l = z; w=1;  }
         else if(z<0 && l+z<0) { l=-1*z; w=2;  } 
}

printf("%d %d",w,l);

system("Pause");
return 0;
}
