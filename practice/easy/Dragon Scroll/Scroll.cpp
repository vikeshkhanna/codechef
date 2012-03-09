#include<iostream>
#include<string>
#include<fstream>

#define FOR(i,n) for(int i=0;i<n;++i)
#define MAX 10000

using namespace std;

//FILE* ifp = fopen("input.txt","r");
FILE* ifp = stdin;

int num_of_ones(int x)
{
    int cnt = 0;
    
    while(x!=0)
    {
               x &= (x-1);          
               ++cnt; 
    }
    return cnt;
}

int main()
{
int t, n, a, b;
scanf("%d",&t);

FOR(T,t)
{
        scanf("%d%d%d",&n,&a,&b);
        int n1 = num_of_ones(a);
        int n2 = num_of_ones(b);
        
        int nl = n1 > n2 ? n1 : n2;
        int ns = nl == n1 ? n2 : n1;
        
        int l = ((1<<nl) - 1)<<(n-nl);
        int s = (1<<ns)-1;
        
        int diff = ns - (n - nl);
               
        if(diff < 0)
        {
               s = s<<abs(diff);     
        }
        else
        {
               l = ((l >> ns)<<ns) + ((1<<diff)-1); 
        }
        
        printf("%d\n",l ^ s);        
}

return 0;
}
