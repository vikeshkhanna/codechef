#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define MAX 7
#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
/*
 * @author: Vikesh Khanna
 */
using namespace std;
sint a[] = {137, 1315, 73, 136, 255, 1384, 16385};

void convert(sint x)
{
     if(x==0) printf("0");
     else if(x==1) printf("");
     else if(x==2) printf("2");
     else
     {
                   uint count=sizeof(sint)*8-1;
                   
                   while(x!=0)
                   {
                              while((x>0 && (x & 0x8000))==0){
                                       x<<=1;
                                       count--;
                                      }
                                            
                              printf("2");
                              if(count!=1) printf("(");
                              convert(count);
                              if(count!=1) printf(")");              
                              x<<=1;
                              count--;
                              if(x!=0) printf("+"); 
                   }         
     }
}
 

int main()
{
FOR(i,MAX){
          convert(a[i]);
          printf("\n");
}
system("Pause");
return 0;
}
