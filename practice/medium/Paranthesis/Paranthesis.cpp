#include<iostream>
#include<vector>

#define X 10000

using namespace std;

int main()
{
int t;
cin>>t;

int a[t];

vector<long long> vec;


int largest=-1;

for(int i=0;i<t;i++){
                cin>>a[i];
                
                if(a[i]>largest) largest = a[i];
                }
vec.resize(largest+1);
vec[0]=0;
vec[1]=1;
vec[2]=1;

for(int i=3;i<=largest;i++){
        
         vec[i]=0;
         
        if(i%2!=0) //Odd
        {
                   int center = i/2;
              
                   for(int j=1;j<=center;j++){
                           vec[i] += (vec[j]*vec[i-j])%X;        
                   }
                   vec[i] *=2;
        }
        
        else
            {
                    int center = i/2 - 1;
                   
                   for(int j=1;j<=center;j++){
                           vec[i] += (vec[j]*vec[i-j])%X;        
                   }
                   vec[i] = (vec[i]*2 + vec[center+1]*vec[center+1])%X;
                   
            }
                   
}

for(int i=0;i<t;i++){
        cout<<vec[a[i]]%X<<endl;
}
     


system("Pause");
return 0;
}
