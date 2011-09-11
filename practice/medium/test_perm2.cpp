#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;

long long combinations(int k, int r){
   if(k==1) return 1;
   
   if(k==2) return r+1;
   
   for(int i=0;i<=r;i++)
           vec.push_back(1);
    
    for(int i=0;i<k-2;i++){
                          int sum=0;
                          //cout<<"k loop"<<endl;
                          
                          for(int j=r;j>=0;j--)
                                  {
                                               vec[j]+=sum;
                                               sum=vec[j];
                            //                   cout<<vec[j]<<" ";
                                 }
                          //cout<<endl;
            }                     
    
    long long count = 0;
    
    for(int i=0;i<=r;i++)
            count+=vec[i];
            
    return count; 
}


int main()
{
int k,r;
cin>>k>>r;

cout<<combinations(k,r)<<endl;
system("Pause");
return 0;
}
