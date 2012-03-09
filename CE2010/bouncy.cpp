#include<iostream>
#include<vector>
#include<string>
using namespace std;

int checkBouncy(int num)
{
                    int check = 0;  //1 for increasing, 2 for decreasing
                    int digit = num%10;
                    num = num/10;
                    
                     check = ( digit-num%10>=0 ? 1 : 2);
                                    
                    while(num!=0)
                                 {
                                      if(check==1 && digit-num%10 < 0 )
                                                  return 1;
                                      else if(check==2 && digit-num%10>=0)  
                                                  return 1;
                                        
                                      digit = num%10;
                                       num=num/10;
                                 }
return 0;
}


int main()
{
int t;
cin>>t;

int input[t];

for(int i=0;i<t;i++)
        cin>>input[i];

for(int i=0;i<t;i++)
        cout<<checkBouncy(input[i])<<endl;        


system("Pause");
return 0;
}
