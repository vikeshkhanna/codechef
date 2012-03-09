#include<iostream>
#include<cmath>
using namespace std;


int num(int x)
{
     
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
      
   return (int) prod;     
       
}


int main()
{
int a;

while(a!=-1){cin>>a;
cout<<num(a)<<endl;    
}



system("Pause");
return 0;
}
