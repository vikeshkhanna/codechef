#include<iostream>
#include<stdio.h>
#include<cstring>
#define MAX 100000
using namespace std;

int main()
{
int t,rem=0,n;
char str[MAX+1];
scanf("%d",&t);

for(int i=0;i<t;i++)
{
        scanf("%s",str);
        n = strlen(str);
        rem=0;
                
        for(int j=0;j<n && rem>=0 ;j++)
                {
                  if(str[j]=='T') 
                       rem++;
                  else 
                       rem--;
                }
                
        if(rem!=0)
               printf("NO\n");
        else
               printf("YES\n");
}


system("Pause");
return 0;
}
