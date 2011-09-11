#include<iostream>
using namespace std;

void test(const int& x)
{
     cout<<"Address : "<<&x;
}

int main()
{
int x=10;

cout<<"Main : "<<&x;
test(x);

system("Pause");
return 0;
}
