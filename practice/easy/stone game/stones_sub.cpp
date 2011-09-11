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
scanf("%d",&t);

FOR(T,t)
{
        scanf("%d",&n);
        
        turns=0;
        FOR(i,n){
                scanf("%d",&stones);
 
                 if(stones>=i+1)
                        turns += stones/(i+1);
        }
        printf("%s\n",turns%2==0 ? "BOB" : "ALICE");
}


system("Pause");
return 0;
}
