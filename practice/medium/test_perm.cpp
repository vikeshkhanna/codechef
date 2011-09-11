#include<iostream>
using namespace std;

long long combinations(int k, int r){
     
     if(k==1)
             return 1;
     else    
             {
                    long long count=0;
                    
                    for(int i=0;i<=r;i++)
                            count+=combinations(k-1,r-i);
                    
                    return count;
             }
}


int main(){
int r,k;

while(1){
cin>>k>>r;
cout<<combinations(k,r)<<endl;        
}
system("Pause");
return 0;
}
