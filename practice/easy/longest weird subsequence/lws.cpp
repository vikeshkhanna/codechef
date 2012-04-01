#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORS(i,s,n) for(int i=s;i<n;++i)

#define MAX 2000

using namespace std;

int hash[MAX];

FILE* ifp = fopen("input","r");
//FILE * ifp = stdin;

int main()
{
int t;
char s[MAX+1];
fscanf(ifp,"%d",&t);

FOR(T,t)
{
 fscanf(ifp,"%s",s);
 int len = strlen(s);
 
 int a[len+1][26][26];
 memset(a,0,sizeof(a));
 
 FORS(i,1,len+1)
 {
  FOR(j,26)
  {
   FOR(k,26)
   {
     int c1 = j + 'a', c2 = k + 'a';
     //cout<<"T:"<<T<<","<<i<<","<<j<<","<<k<<endl;
     a[i][j][k] = max(a[i][j][k], a[i-1][j][k]);
     //cout<<"clear"<<endl;
     
     if(c1 <= s[i-1])
     {
      a[i][s[i-1]-'a'][k] = max(a[i][s[i-1]-'a'][k], a[i-1][j][k] + 1);
     }
     
     if(c2 >= s[i-1])
     {
      a[i][j][s[i-1] - 'a'] = max(a[i][j][s[i-1]-'a'], a[i-1][j][k] + 1);
     }      
   }         
  } 
 }
 
 int m = 0;
 
 FOR(i,26)
 {
  FOR(j,26)
  {
   m=a[len][i][j]>m ? a[len][i][j] : m;           
  }         
 }
 
 printf("%d\n",m);
}

system("pause");
return 0;
}
