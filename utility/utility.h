/*
@author: Vikesh Khanna
*/

// Euclidean algorithm for GCD
int gcd(int r0,int r1)
{
    int temp;

    if(r1==0) return r0;
    else if(r0==0) return r1;

    if(r0<r1)
              {
                   temp = r0;
                   r0 = r1;
                   r1=temp;
              }

    //r0 is the larger number and r1 is the smaller number
    int remainder;

    do{
        remainder = r0%r1;

        r0=r1;
        r1=remainder;
        }while(remainder!=0);

    return r0;
}

// Sieve of erastrothenes for prime numbers
void sieve(bool a[],int n) /* 1 to n, bool a[n+1] */
{
   if(n<1) return;

   a[1] = false;

   for(int i=2;i<=n;i++)
    {
        if(a[i]) //prime
        {
            int j=2;
            while(j*i<=n)
            {
                    a[j*i] = false;
                    j++;
            }
        }
    }
}
