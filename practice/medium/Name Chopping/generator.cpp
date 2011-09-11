#include<fstream>
#include<cmath>
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define FILE "input"
#define MAX 100000
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
ofstream out;
out.open(FILE);

out<<MAX<<"\n";
srand(time(NULL));


FOR(i,MAX){
            int len = 1+rand()%100;

            FOR(i,len)
                out<<(char)('A'+rand()%26);
            out<<"\n";
    }

}
