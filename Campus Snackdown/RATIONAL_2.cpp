#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


//The Euler Totient Function to give the number of coprime numbers less than x

#define TOTIENT_TABLE_SIZE 20
static unsigned short int totient_table[TOTIENT_TABLE_SIZE] = { /* phi(1), phi(2), ... */
       1,    1,    2,    2,    4,    2,    6,    4,    6,    4,
      10,    4,   12,    6,    8,    8,   16,    6,   18,    8 };
 
long long unsigned int gcd(long long unsigned int a, long long unsigned int b)
{
      long long unsigned int tmp;
      while (b) {
            tmp = b;
            b = a % b;
            a = tmp;
      }
      return a;
}


long long unsigned int phi(long long unsigned int n)
/* Return Euler's totient function. */
{
    long long unsigned int res=1,p,phip,pf=1,sqrtn=sqrt(n);
    char pflag;
 
    if (n <= 1) return 0;  /* Really DATA ERROR by Fundamental Theorem of Arithmetic  */
    if (n <= TOTIENT_TABLE_SIZE) return totient_table[n-1];
 
    for (p=2;;) {
        phip=p-1;
        pflag=0;
        while (n%p == 0) {  /* phi(p^k) = p^(k-1)*(p-1) */
            if (!pflag && !(gcd(pf,p) == 1)) break;
            res *= phip;
            phip = p;
            n = n/p;
            if (!pflag) pf *= p;
            pflag = 1;
        }
        if (pflag) sqrtn = sqrt(n);
        p = (p > 2)? p+2 : 3;
        if (p > sqrtn) break;
    }
    /* n is necessarily 1 or a distinct prime */
    if (n > 1) res *= (n-1);
 
    return res;
}


int main()
{
int t;
vector<int> vec;

long long unsigned int largest = 0;
cin>>t;

long long unsigned int n[t];

for(int i=0;i<t;i++)
        cin>>n[i];

for(int i=0;i<t;i++)
        if(n[i]>largest) largest=n[i];
        
long long unsigned int count = 0;

for(long long unsigned int  i=0;i<=largest;i++)
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
