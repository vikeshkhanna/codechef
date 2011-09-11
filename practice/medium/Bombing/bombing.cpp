#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<algorithm>

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
       uint low, high,count;
       
       Node(){
              left = right = p = NULL;
              count=0;
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

void add(const uint* b, Node* root,uint low, uint high, int val=1)
{
     if(root==NULL) return;
     
     uint rlow = root->low, rhigh = root->high;
     if(high<b[rlow] || low>b[rhigh]) return;
     else if(b[rlow]>=low && b[rhigh]<=high)
                        root->count+=val;    
     else
     {
                        if(root->left!=NULL && b[root->left->high]<=low)
                               add(b,root->right,low,high);
                        else if(root->left!=NULL && b[root->left->high]>=low && b[root->left->high]>=high)
                               add(b,root->left,low,high);
                        else
                            {
                                add(b,root->left,low,root->left->high);
                                add(b,root->right,root->right->low,high);                        
                            } 
     }
}

void update(const uint* b,uint p[][2], Node* root,uint index,uint shift)
{
     uint olow = p[index][0], ohigh = p[index][1];
     add(b,root,olow,ohigh,-1);
     add(b,root,olow+shift,ohigh+shift);
}

uint count(uint* b,Node* root,uint index)
{
                 uint sum=0;
                 
                 while(b[root->low]!=index || b[root->high]!=index)
                 {
                          sum+=root->count;
                          
                          if(b[root->left->high]<index) root=root->right;
                          else root=root->left;
                 }

}

int comp(const void* a, const void* b)
{
     return (*(int*)a - *(int*)b);
} 


int main()
{
ifstream in;
in.open(FILE);

uint n,m,in1,in2;
in>>n>>m;
uint com[m][3],p[m][2],b[m];
char c;
uint cp=0,cb=0;

FOR(i,m)
{
          in>>c;
          com[i][0] = c;
          
          if(c==(uint)'P'){
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

Node* root = construct(0,cb-1);
qsort(b,cb,sizeof(uint),comp);

FOR(i,m){
        if(com[i][0]==(uint)'B')
                          printf("%d\n",count(b,root,com[i][1]));
         else if(com[i][0]==(uint)'P')
                           add(b,root,com[i][1],com[i][2]);
         else if(com[i][0]==(uint)'M') 
                            update(b,p,root,com[i][1]-1,com[i][2]); 
}                              
      
system("pause");
return 0;
}
