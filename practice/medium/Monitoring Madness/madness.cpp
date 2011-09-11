#include<iostream>
#include<stdio.h>
#include<fstream>

#define FILE "input"
#define parent(i) (int)((i-1)/2)
#define left(i) 2*i+1
#define right(i) 2*i+2
#define MAX 26
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

class Node
{
        public:
            Node* next;
            char val;

            Node(){
                next = NULL;
                }

            Node(char val){
                next = NULL;
                this->val = val;
            }
};

class HeapNode
{
        public:
                char val;
                int* ptr;
};

class MaxHeap
{
    public:
           int size;
           HeapNode arr[MAX];
           int back[MAX];

           MaxHeap(int* a, int n){
                size = 0;

                FOR(i,n){

                    if(a[i]){
                                arr[size].ptr = &a[i];
                                arr[size].val = 'A' + i;
                                back[i] = size;
                                size++;
                            }
                }


                for(int i=n/2;i>=0;i--)
                        max_heapify(i);
            }

    void max_heapify(int );
    void decrease_key();
};

void MaxHeap::max_heapify(int i)
{
    int left, right, largest;

              while(i<size)
              {
                 //printf("%d\n",i);
                 largest = i;
                 left = left(i);
                 right = right(i);

                 if(left<size && *arr[left].ptr>*arr[largest].ptr) largest = left;
                 if(right<size && *arr[right].ptr>*arr[largest].ptr) largest = right;

                 if(largest!=i) //Swap
                 {
                              HeapNode temp = arr[i];
                              arr[i]=arr[largest];
                              arr[largest] = temp;
                              back[arr[i].val-'A']

                 } else break;

                  i = largest;
              }
}



int main(int argc, char** argv)
{
ifstream in;
in.open(FILE);

int t,n, i1,i2,degree[MAX];
char a,b;

in>>t;

FOR(T,t){
    in>>n;
    Node list[MAX];

    FOR(i,MAX){
            list[i].val = 'A'+i;
            degree[i] = 0;
    }

    FOR(i,n){
                in>>a>>b;
                i1 = a-'A';
                i2 = b-'A';

                Node* temp = list[i1].next;
                Node* newnode = new Node(b);
                list[i1].next = newnode;
                newnode->next =temp;

                temp = list[i2].next;
                newnode = new Node(a);
                list[i2].next = newnode;
                newnode->next = temp;

                degree[i1]++; degree[i2]++;
    }

    MaxHeap heap(degree,MAX);
    FOR(i,heap.size)
    {
            cout<<heap.arr[i].val<<endl;
    }

    /*
    FOR(i,MAX)
    {
            if(degree[i]!=0){
                    Node* temp = &list[i];

                    while(temp!=NULL)
                    {
                            printf("%c ",temp->val);
                            temp = temp->next;
                    }
                printf("\n");
            }
    }*/

}


return 0;
}
