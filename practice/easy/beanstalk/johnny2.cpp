#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define in(i,v) scanf("%i",&v)
#define FOR(i,n) for(int i=0;i<n;i++)
#define LEVEL_LIM 20
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

uint num,k,t;
float current;
in(d,t);
   
FOR(T,t)
{
        in(d,k);
        uint i;
        current = 0.5;
        
        for(i=0;i<k && current>0;i++)
        {
              current *=2;
              scanf("%d",&num);
              current = current - num;
        } 
        
      if(i==k && current==0) 
              printf("Yes\n");
      else 
      {
           printf("No\n");
             if(i!=k)
                    FOR(j,k-i)    scanf("%d",&num);
       } 
}

system("Pause");
return 0;
}
