#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>

#define FILE "input.txt"
using namespace std;

typedef unsigned long long int ulong;

ifstream in;


int main()
{
in.open(FILE);

int t;
in>>t;

for(int i=0;i<t;i++)
{
        int n, m;
        in>>n; in>>m;
        
        int p=m*n;
        ulong imp;
        
        
        if(m==1 || n==1) //1
        {
               if(m==1) imp=n; else imp=m;
               
               cout<<imp*(imp-1)<<endl;
               continue;    
        }
    
        if((m==2 && n>=5) || (n==2 && m>=5)) //2
        {
                if(m==2) imp=n; else imp=m;
                    cout<<(ulong)(8*(imp*2-2) + (imp*2-3)*(imp*2-8))<<endl;
                
                continue;
        }        
        
        if((m==3 && n>=5) || (n==3 && m>=5))//3
        {
                if(m==3) imp=n; else imp=m;
                    cout<<(ulong)(8*(imp*3-3) + 2*(imp*6-7) + 2*(imp-4)*(imp*3-3) + (imp-4)*(imp*3-5))<<endl; 
                
                continue;
        }        
        
         switch(p)
                 {
                     case 4: cout<<12<<endl; continue;
                     case 6: cout<<26<<endl; continue;
                     case 8: cout<<48<<endl; continue;
                     case 9: cout<<56<<endl; continue;
                     case 12: cout<<90<<endl; continue;
                    
                    }
    
    
    ulong ans = (m-4)*(n-4)*(p-9) + 2*(p-12)*(m+n-8) + (4*p-16)*4;
    cout<<ans<<endl;                   
        //cout<<n*m<<endl;
}
    
    
    
system("Pause");
return 0;
}
