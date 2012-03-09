/*
@author: Vikesh Khanna
*/

//Sieve of erastrothenes

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
