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

ofstream out("output.txt");

void convert(sint x)
{
     if(x==0) out<<"0";
     else if(x==1) out<<"";
     else if(x==2) out<<"2";
     else
     {
                   uint count=sizeof(sint)*8-1;
                   
                   while(x!=0)
                   {
                              while((x>0 && (x & 0x8000))==0){
                                       x<<=1;
                                       count--;
                                      }
                                            
                              out<<"2";
                              if(count!=1) out<<"(";
                              convert(count);
                              if(count!=1) out<<")";              
                              x<<=1;
                              count--;
                              if(x!=0) out<<"+"; 
                   }         
     }
}
 

int main()
{
FOR(i,MAX){
           out<<a[i]<<"=";
          convert(a[i]);
          out<<"\n";
}
system("Pause");
return 0;
}
