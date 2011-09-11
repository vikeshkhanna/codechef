#include<iostream>
#include<queue>

using namespace std;

int main()
{
int x=10;
queue<int* > Q;   //Replace int* by int and see the difference!

Q.push(&x);

x = 5;
cout<<"x : "<<x<<endl;
cout<<"Q: "<<*Q.front()<<endl;
cout<<"Adress of x: "<<&x<<endl;
cout<<"But Adress of Q.front(): " <<&Q.front()<<endl;   // A new int* was created and pushed to the Queue

int* y = new int(5);
Q.push(y);
cout<<"Popped out y : "<<*Q.front()<<endl;
Q.pop();
cout<<"Y still exists in the memory although not in Q: "<<*y<<endl;
cout<<"This happened because Q pushes pointers by value, i.e. by copying them"<<endl;


system("Pause");
return 0;
}
