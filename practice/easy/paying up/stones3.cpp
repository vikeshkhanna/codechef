#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
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
ifstream in;
in.open(FILE);

uint t,n,stones,turns;
in>>t;
cout<<t;

FOR(T,t)
{
        in>>n;
        turns=0;
        FOR(i,n){
                 in>>stones;
                 
                 if(stones>=i+1)
                        turns += stones/(i+1);
        }
        printf("%s\n",turns%2==0 ? "BOB" : "ALICE");
}


system("Pause");
return 0;
}
