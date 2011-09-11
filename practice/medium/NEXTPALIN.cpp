#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

#define lim 1000000

void overflowHandler(vector<int>& vec)
{
     
     
}


void process(vector<int>& vec)
{
     int m=vec.capacity();
     int center = m/2 - 1;
     bool changed = false;
     
     
     for(int i=center;i>=0;i--)
             {
                               if(vec[i]!=vec[m-i-1])
                                       {
                                                     if(changed)
                                                                  vec[m-i-1]=vec[i];
                                                     else
                                                                   {
                                                                               if(vec[m-i-1]>vec[i])
                                                                                                vec[i]++;
                                                                               vec[m-i-1]=vec[i];
                                                                               changed=true;    
                                                                   }
                                       }
             }
     
     if(changed==false) //Itself a palindrome. Find a higher
                       {
                                 vec[center+m%2]++;
                                 vec[m-center-1]=vec[center];
                       }
}

void display(vector<int> vec)
{
     int m=vec.capacity();
     
     for(int i=0;i<m;i++)
             {
                         cout<<vec[i];                         
             }     
     cout<<endl;
}



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
