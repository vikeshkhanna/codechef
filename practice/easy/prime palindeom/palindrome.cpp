#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<cstring>


#define INPUT "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 2000000

typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;

//FILE* ifp= fopen(INPUT,"r");
FILE* ifp = stdin;

void sieve(bool a[][2],int n) /* 1 to n, bool a[n+1] */
{
   if(n<1) return;

    for(int i=1;i<=n;i++)
        a[i][0] = true;

   a[1][0] = false;

   for(int i=2;i<=n;i++)
    {
        if(a[i][0]) //prime
        {
            int j=2;
            while(j*i<=n)
            {
                    a[j*i][0] = false;
                    j++;
            }
        }
    }
}

bool is_palindrome(char str[])
{
        int len=strlen(str), n = len/2;
        FOR(i,n)
            if(str[i]!=str[len-i-1]) return false;
        return true;
}

void palindrome(bool a[][2],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][0]){
                char str[8];
                int x=i,j=0;

                while(x>0)
                {
                        //cout<<x<<endl;
                        str[j++]='0' + x%10;
                        x/=10;
                }
                str[j++]=0;
                //cout<<str<<endl;
                if(is_palindrome(str)) a[i][1]=true;
                else a[i][1]=false;
        }
    }
}

int main()
{
int n;
bool a[MAX+1][2];
sieve(a,MAX);
palindrome(a,MAX);
fscanf(ifp,"%d",&n);

 //   cout<<i<<" "<<a[i][0]<<" "<<a[i][1]<<endl;
int i=1;

while(i<n || !a[i][0] || !a[i][1])
    i++;

printf("%d\n",i);
//system("Pause");
return 0;
}
