#include<iostream>
#include<fstream>
#include<stdio.h>
#define FILE "input.txt"

#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
using namespace std;


uint merge(uint* a,uint p, uint q, uint r)
{
	uint n1 = q-p+1;
	uint n2 = r-q;
	
	uint count=0, L[n1+1], R[n2+1];
	
	FOR(i,n1) L[i] = a[p+i];
	FOR(i,n2) R[i] = a[q+i+1];
	
	L[n1] = R[n2] =  L[n1-1] + R[n2-1];
	uint i=0,j=0;

	for(int k=p;k<=r;k++){
                             if(L[i]<=R[j])	
                                             a[k]=L[i++];
                             else
                             {
                                             a[k]=R[j++];            
                                             count+=(n1-i);
                             }
	}
  //cout<<"Merge: "<<count<<endl;
  return count;
}

uint num_inversions(uint* a,const uint p, const uint r)
{
    uint count=0;
   
   	if(p<r)
	{
		uint q = (p+r)/2;
		count =  num_inversions(a,p,q) + num_inversions(a,q+1,r);
		count += merge(a,p,q,r);
	}	
	 return count;
}


int main()
{
uint n;
ifstream in;
in.open(FILE);

//scanf("%d",&n);
in>>n;
uint a[n];

FOR(i,n)
	in>>a[i];
    //scanf("%d",&a[i]);

printf("%d\n",num_inversions(a,0,n-1));

system("Pause");
return 0;
}
