#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
vector< vector<int> > vec;
int t;
cin>>t;

vector<int> temp;
for(int i=0;i<t;i++)
        {           
                    int a;
                    while(!eof())
                               {
                                 cin>>a;
                                 temp.push_back(a);
                               }        
                    vec.push_back(temp);
        }

system("Pause");
return 0;
}
