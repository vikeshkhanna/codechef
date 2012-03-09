#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


//The Euler Totient Function to give the number of coprime numbers less than x
int phi(int x)
{
    
    if(x==1 || x==0) return 0;
     
	long i;			/* counter */
	long c;			/* remaining product to factor */
    
    c = x;
    double prod = x;
    
     if((c%2)==0)
          prod = prod*(double)(1- 1/2.0);       

    
	while ((c % 2) == 0)
		c = c / 2;
    
  // cout<<prod<<endl;
    
	i = 3;

	while (i <=c) {
		if ((c%i) == 0 ){
			   prod *=(double)(1-(double)1/i);
            
            while(i<=c && c%i==0)
                  c = c / i;
      }
      	else
			i = i + 2;
	}
  
  if(c==x)
      return c-1;
  
   return  (int)prod;          
}


int main()
{
int t;
vector<int> vec;

int largest = -1;
cin>>t;

int n[t];

for(int i=0;i<t;i++)
        cin>>n[i];

for(int i=0;i<t;i++)
        if(n[i]>largest) largest=n[i];
        
long long count = 0;

for(int i=0;i<=largest;i++)
       {
                 count += phi(i);
                 vec.push_back(count);                         
       }

for(int i=0;i<t;i++)
        {
                    cout<<vec[n[i]]<<endl;
        }

system("Pause");
return 0;
}
