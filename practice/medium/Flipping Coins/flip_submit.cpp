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
       uint heads, n, flip;
      
       
       Node(){
              heads=0; 
              left = right = p = NULL;
              flip = 0;
       }
}; 

Node* construct(uint low, uint high, Node* parent = NULL)
{
     Node* root = new Node();
     root->n = high-low + 1;
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
                      cout<<"("<<root->low<<","<<root->high<<","<<root->heads<<","<<root->n<<")"<<endl;                  
                      inorder(root->right);
     }     
}

void flip( Node* root,uint low,uint high,uint f=0)
{
                if(root->low==low && root->high==high){
                           if((f + root->flip)%2==0)
						 root->heads = root->n-root->heads;
			   else 
			   {
					

			   }			                           
			root->flip = (root->flip+1)%2;
                           
                           Node* temp=root->p;
                           while(temp!=NULL){
                                            temp->heads = temp->left->heads + temp->right->heads;
                                            temp = temp->p;
                           }
                           
                }else
                {
                    if(root->left!=NULL && low<=root->left->high){
                           if(high>=root->right->low)
                                  {
                                      flip(root->left,low,root->left->high,(f+root->flip)%2);
                                      flip(root->right,root->right->low,high,(f+root->flip)%2);
                                  }
                           else 
                                      flip(root->left,low,high,(f+root->flip)%2);
                      }else
                                      flip(root->right,low,high,(f+root->flip)%2);
                 }
}

uint head_count(const Node* root, uint low, uint high, uint flip=0)
{
     if(root==NULL) return 0;
     else if(root->low>high || root->high<low) return 0;
     else if(root->low>=low && root->high<=high)
                        return (flip==0?root->heads:root->n-root->heads);
     else{
                      if(root->left!=NULL && low<=root->left->high){
                           if(high>=root->right->low)
                                 return (head_count(root->left,low,root->left->high,(flip+root->flip)%2) + head_count(root->right,root->right->low,high, (flip+root->flip)%2));
                           else 
                                 return head_count(root->left,low,high,(flip+root->flip)%2);
                      }
                      else
                          return head_count(root->right,low,high,(flip+root->flip)%2);
     }
}


int main()
{
ifstream in;
in.open(FILE);

uint n,q,c,a,b;
scanf("%d",&n);
scanf("%d",&q);

Node* root = construct(0,n-1);

FOR(i,q)
{
          scanf("%d",&c);
          scanf("%d",&a);
          scanf("%d",&b);
      
          if(c==0)
            flip(root,a,b);
          else
              printf("%d\n",head_count(root,a,b));
} 

system("Pause");
return 0;
}
