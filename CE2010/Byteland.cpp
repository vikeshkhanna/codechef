#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
int t;
cin>>t;

string input[t];

for(int i=0;i<t;i++)
        cin>>input[i];

for(int i=0;i<t;i++)
{
        int len = input[i].length();
        int count=0;
        
        for(int j=0;j<len;j++)
                count = count +  (int)input[i][j];
        
        cout<<(char)(count/len)<<endl;
        
}

//system("Pause");
return 0;
}
