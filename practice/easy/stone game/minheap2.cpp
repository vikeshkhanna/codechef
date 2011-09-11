#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2
#define PARENT(i) i/2

typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;

/*
 * @author: Vikesh Khanna
 */

template<class T>
class MinHeap
{
      public:
            T* a;
            uint size;
            uint max;
            
            MinHeap(T* arr,uint s,uint max=-1) {
                        size = s;
                        if(max ==-1) max=s;
                        a = new T[max];
                        
                        FOR(i,s)
                               a[i] = arr[i];
                                   
                        buildHeap();
            } 
            
           void buildHeap(){
                 for(int i=size/2;i>=0;i--){
                         heapify(i);   
                 }            
            }
            
            void heapify(uint i)
            {
                 while(true)
                 {
                     uint smallest = i;
                     uint left = LEFT(i), right = RIGHT(i);
                     
                     if(left<size && a[left]<a[i]) smallest = left;
                     if(right<size && a[right]<a[smallest]) smallest = right;
                     
                     if(smallest!=i)
                     {
                               T val = a[smallest];    
                               a[smallest] = a[i];
                               a[i] = val;                             
                               i = smallest;
                     }else break;
                 }
            }
            
            T extract_min()
            {
                           T ret;
                           if(!isEmpty()){
                                           ret = a[0];
                                           a[0]=a[size-1];
                                           size--;
                                           heapify(0);
                           }
                           return ret;
                         
            } 

            void insert(T val)
            {
                     if(!isFull())
                     {
                               size++;
                               a[size-1]=val;
                               uint i = size-1;
                               while(a[PARENT(i)]>a[i]){
                                             T val = a[i];    
                                             a[i] = a[PARENT(i)];
                                             a[PARENT(i)] = val;   
                                             i = PARENT(i);
                               }
                     }
            }
                 
            bool isEmpty() {return size==0;}
            bool isFull() {return size==max;}
                 

};

int main()
{
ifstream in;
in.open(FILE);

uint a[] = {1, 2, 4, 6 , 11, 3, 5,0};

MinHeap<uint>  H(a,8,100);

while(!H.isEmpty())
{
                   cout<<"\n"<<H.extract_min()<<endl;        
                   FOR(i,H.size) cout<<H.a[i]<<" ";         

}

cout<<endl;

FOR(i,8)
{
        H.insert(a[i]);
        cout<<endl;
        FOR(i,H.size) cout<<H.a[i]<<" ";       
}


system("Pause");
return 0;
}
