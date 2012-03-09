#include<iostream>
#include<cmath>
using namespace std;
bool coprime(int a, int b)
{
  
 if(a<b)
 {
 int temp=a;
 a=b;
 b=temp;
 }

int r0=a,r1=b;
int t0=0,t1=1;
int q=a/b;
int r=a%b;

    while(r!=0)
    {
        int temp=t0-q*t1;
        if(temp<0)
        temp=(a+temp)%a;
        else
        temp=temp%a;
        t0=t1;
        t1=temp;
        r0=r1;
        r1=r;
        q=r0/r1;
        r=r0%r1;
    }
if(r1==1) return true;
else return false;

}  


int main()
{
int a,b;
cin>>a>>b;

cout<<coprime(a,b)<<endl;    

system("Pause");
return 0;
}
