n#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
ifstream in;
in.open(FILE);

int t, m,n,g;
int a,b;

in>>t;

FOR(i,t)
{
         in>>n>>m>>g;
         int arr[n];
        
         FOR(j,m)
         {
                in>>a>>b;
                arr[a]=arr[b]=-1;
         }
                
         int len0=0;
         FOR(j,n)
         {
                 if(arr[
         
         }

}



system("Pause");
return 0;
}
