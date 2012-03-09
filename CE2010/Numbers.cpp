#include<iostream>
#include<vector>
#include<string>
using namespace std;

int checkNumber(int num)
{
        int hash[10] = {0};
        int d = num*2;
               
        while(num!=0)
                     {
                           int digit = num%10; 
                           
                           hash[digit]++;
                           num=num/10;     
                     }
         
         int hash2[10] = {0};
         
         while(d!=0)
                    {
                            int digit = d%10;
                            
                            hash2[digit]++;                  
                            d = d/10;
                    }        
        
        for(int i=0;i<10;i++)
                if(hash[i]!=hash2[i]) return 0;

return 1;
}                    


int main()
{
int t;
cin>>t;

int input[t];

for(int i=0;i<t;i++)
        cin>>input[i];

for(int i=0; i<t;i++)
    cout<<checkNumber(input[i])<<endl;

system("Pause");
return 0;
}
