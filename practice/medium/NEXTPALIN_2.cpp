#include<iostream>
using namespace std;

int main()
{
int t;
vector<vector<int> > vec;

cin>>t;
cin.ignore();  //Ignore the remaining \n on the input stream.

char str[t][lim];

vec.resize(t);

for(int i=0;i<t;i++)
        {
                    cin.getline(str[i],lim);
                    //cout<<str[i]<<endl;
        }

//Add to the vector
for(int i=0;i<t;i++)
{
        int j=-1;
        
        while(str[i][++j]!='\0');
        
        vec[i].resize(j);
        
        for(int k=0;k<j;k++)
                            vec[i][k] = (int)str[i][k] - 48;        
        
        process(vec[i]);
        display(vec[i]);
}



system("Pause");
return 0;
}
