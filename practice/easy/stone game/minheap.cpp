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
            T** a;
            uint size;
            uint max;
            
            MinHeap(int s){
                        size = 0;
                        max = s;
                        a = new T*[max];
            } 
            
            bool isEmpty() { return size==0;}
            bool isFull() { return size==max;}      
            
            void buildHeap(){
                 for(int i=size/2;i>=0;i--){
                         heapify();   
                 }            
            }
            
            void heapify(uint i)
            {
                 while()
                 {
                     uint left = LEFT(i), right = RIGHT(i);
                     uint largest = i;
                     
                     
                     if(*a[left]>*a[largest]) largest = left;
                     if(*a[right]>*a[largest]) largest = right;
                     
                     if(largest!=i)
                     {
                               *a[left]                            
                                   
                     }
            }
      
};



int main()
{
ifstream in;
in.open(FILE);

system("Pause");
return 0;
}
