#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#define N 200000

#define FILE "output.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;


/*
 * @author: Vikesh Khanna
 */

int main()
{
ofstream out;
out.open(FILE);
srand(time(NULL));

uint n = 1 + rand()%N/2;
out<<"1\n"<<n<<"\n0"<<" ";

for(int  i=1;i<n;i++)
{
        out<<rand()%i<<" ";
}

system("Pause");
return 0;
}
