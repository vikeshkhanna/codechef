#include<iostream>
#include<fstream>
#include<string.h>

#define FILE "input"
#define MAX 1000
#define FOR(i,n) for(int i=0;i<n;i++)
#define DIV 23102009

using namespace std;
typedef long unsigned int uint;

int main()
{
uint t, m, n;
char S[MAX], T[MAX];

scanf("%d",&t);

FOR(X,t)
{
	cin>>S;
	cin>>T;
	
	m = strlen(S);
	n = strlen(T);

	uint c[m+1][n+1], count[m+1][n+1];

	FOR(i,m+1){  
			c[i][0] = 0;
			count[i][0] = 0;
		}
   		
	FOR(i,n+1){  
			c[0][i] = 0;
			count[0][i] = 0;
		}
   	

	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
				if(S[i-1]==T[j-1])
				{
					c[i][j] = c[i-1][j-1]+1;
					count[i][j] = (count[i-1][j-1]==0?1:count[i-1][j-1]);
			        }  
				else 
				{
					c[i][j] = max(c[i-1][j],c[i][j-1]);
					count[i][j] = 0;
			
					if(c[i][j]==c[i-1][j]) count[i][j] = count[i][j]+ count[i-1][j];
					if(c[i][j]==c[i][j-1]) count[i][j] = count[i][j]+ count[i][j-1];
					if(c[i][j]==c[i-1][j-1]) count[i][j] = count[i][j] - count[i-1][j-1];
					count[i][j] = (count[i][j]+DIV)%DIV;
				}
		}
	} 	
	printf("%d %d\n",c[m][n],count[m][n]);
}
return 0;
}
