#include<iostream>
#include<string>
#include<fstream>

#define FOR(i,n) for(int i=0;i<n;++i)
#define MAX 10

using namespace std;

FILE* ifp = fopen("input.txt","r");
//FILE* ifp = stdin;

void getline(char s[])
{
     int c, i =0;
     c = getchar();
                
     while(c!=EOF && c!='\n')
     {
                s[i++] = c;            
                c = getchar();
     }
     
     s[i] = 0;
}

bool is_correct(char s[])
{
    if(strlen(s)!=5) return false;
    
    if(s[0]< 'a' || s[0]>'h')     
             return false;
    if(s[1]<'1' || s[1] > '8')
             return false;
    
    if(s[3]< 'a' || s[3]>'h')     
             return false;
    if(s[4]<'1' || s[4] > '8')
             return false;
    
    if(s[2]!='-') 
         return false;
    
    return true;
}

bool is_valid(char s[])
{
      int dcol = s[0] - s[3], drow = s[1] - s[4];
      
      if(abs(dcol)==1 && abs(drow)==2)
                      return true;
      if(abs(dcol)==2 && abs(drow)==1)
                      return true;

      return false;                
}


int main()
{
int t;
char s[MAX+1];
scanf("%d", &t);
getchar();

FOR(T,t)
{ 
    //cout<<"Case: "<<T<<endl;
    getline(s);
    if(is_correct(s))
    {
                     if(is_valid(s))
                                    printf("Yes\n");                 
                     else
                                    printf("No\n");
    }    
    else
        printf("Error\n");
}

return 0;
}
