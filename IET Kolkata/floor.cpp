#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
int n,t,sum;
scanf("%d",&t);

for(int i=0;i<t;i++)
{
	sum=0;
	scanf("%d",&n);
	
	if(n%2==0){
		sum = n/2-1;
		sum = sum*(sum+1) + n/2;
	}
	else
	{
		sum = n/2;
		sum = sum*(sum+1);
	}
	
	printf("%d\n",sum);
}
system("Pause");
return 0;
}
