#include<iostream>
using namespace std;

int gcd(int a, int b)
{
      int tmp;
      while (b) {
            tmp = b;
            b = a % b;
            a = tmp;
      }
      return a;
}

int main()
{
int a,b;
cin>>a>>b;
cout<<gcd(a,b);


system("Pause");
return 0;
}
