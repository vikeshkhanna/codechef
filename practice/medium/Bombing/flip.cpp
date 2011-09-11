#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define FILE "input.txt"
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
       Node *left, *right, *p;
       uint low, high;
       
       Node(){
              left = right = p = NULL;
       }
}; 

Node* construct(uint low, uint high, Node* parent = NULL)
{
     Node* root = new Node();
     root->p = parent;
     
     if(high==low){
                     root->low = low;
                     root->high = high;
     }
     else{
                   root->low = low;
                   root->high = high;
                        
                   uint mid = (high+low)/2;  
                   root->left = construct(low,mid,root);
                   root->right = construct(mid+1,high,root);
     }
     
     return root;
}

/* Debug */
void inorder(Node* root)
{
     if(root!=NULL){
                      inorder(root->left);
                      cout<<"("<<root->low<<","<<root->high<<endl;                  
                      inorder(root->right);
     }     
}


int main()
{
ifstream in;
in.open(FILE);

uint n,m,in1,in2;
in>>n>>m;
uint c,com[m][3],p[m][2],b[m];
uint cp=0,cb=0;

Node* root = construct(0,n-1);

FOR(i,m)
{
          in>>c;
          com[i][0] = c;
          
          if(c=='P'){
                in>>in1>>in2;
                com[i][1] = p[cp++][0] = in1;
                com[i][2] = p[cp++][1] = in2;
          }
          else if(c=='M')
              {
                  in>>in1>>in2;
                  com[i][1] = in1;
                  com[i][2] = in2;
              }
          else {
                  in>>in1;
                  com[i][1] = b[cb++] = in1;
          }
} 

FOR(i,m)
        cout<<com[i][0]<<endl;
        
system("pause");
return 0;
}
