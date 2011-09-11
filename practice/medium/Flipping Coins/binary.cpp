#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
#define MAX 100000
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;

/*
 * @author: Vikesh Khanna
 */
struct Node
{
       Node *left, *right;
       uint low, high;
       uint count;
       
       Node(){
              count=0; 
              left = right = NULL;
       }
}; 


Node* construct(uint low, uint high)
{
     Node* root = new Node();
     
     if(high==low){
                     root->low = low;
                     root->high = high;
     }
     else{
                   root->low = low;
                   root->high = high;
                   
                   uint mid = (high+low)/2;  
                   root->left = construct(low,mid);
                   root->right = construct(mid+1,high);
     }
     
     return root;
}

void inorder(Node* root)
{
     if(root!=NULL){
                      inorder(root->left);
                      cout<<"("<<root->low<<","<<root->high<<")"<<endl;                  
                      inorder(root->right);
     }     
}

int arr_size(const int* a)
{
    uint i=0;
    while( a[i++]!=-1);
    return i;
}


int main()
{
int a[] = {10,2,6,8,3,9,4,8,17,25,14,56,19,27,78,43,-1};
Node* root = construct(0,3);
inorder(root);

system("Pause");
return 0;
}
