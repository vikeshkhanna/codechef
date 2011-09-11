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
using namespace std;

/*
 * @author: Vikesh Khanna
 */

void postfix(const char* s, char* x)
{
     
}


int main()
{
ifstream in;
in.open(FILE);

uint t;
in>>t;


FOR(T,t)
{
        char *s,*x;
        in>>s;
        x = (char*)malloc(strlen(s));
        //printf("%s",s);       
        postfix(s,x);
        printf("%s",x);       
}

system("Pause");
return 0;
}
