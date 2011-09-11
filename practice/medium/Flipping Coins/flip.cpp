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
uint flips = 0;

struct Node
{
       Node *left, *right, *p;
       uint low, high;
       uint heads, n, flip, timestamp;
      
       
       Node(){
              heads=0; 
	      timestamp = 0;
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

uint flip( Node* root,uint low,uint high,uint f=0,uint max=0)
{
                if(root->low==low && root->high==high){
			   uint oldval = root->heads;
                           if(root->timestamp<=max && f==0) root->heads = root->n-root->heads;
                           root->flip = (root->flip+1)%2;
                           root->timestamp = ++flips;
			   return (root->heads -oldval);
	         }else
                {
                    if(root->left!=NULL && low<=root->left->high){
                           if(high>=root->right->low)
                                  {
                                      if(root->timestamp<max && f==0) root->heads = root->n - root->heads;

				      uint change1= flip(root->left,low,root->left->high,(f+root->flip)%2,root->timestamp>max?root->timestamp:max);
                                      uint change2= flip(root->right,root->right->low,high,(f+root->flip)%2,root->timestamp>max?root->timestamp:max);
                                      
					   				      
						
				}
                           else 
                                     {
					  flip(root->left,low,high,(f+root->flip)%2,root->timestamp>max?root->timestamp:max);
				     	  	
				     }
                      }else
                                      flip(root->right,low,high,(f+root->flip)%2,root->timestamp>max?root->timestamp:max);
		
			                
		}
}

uint head_count(const Node* root, uint low, uint high, uint flip=0,uint max=0)
{
     
     if(root==NULL) return 0;
     //else if(root->low>high || root->high<low) return 0;
     else if(root->low>=low && root->high<=high)
                       {
				//cout<<"TS: "<<root->timestamp<<"Max: "<<max<<endl;				
				if(root->timestamp<max) return (flip==0?root->heads:root->n-root->heads);
				else return root->heads;
  	   		}
     else{
                      if(root->left!=NULL && low<=root->left->high){
                           if(high>=root->right->low)
                                 return (head_count(root->left,low,root->left->high,(flip+root->flip)%2,root->timestamp>max?root->timestamp:max) + head_count(root->right,root->right->low,high, (flip+root->flip)%2),root->timestamp>max?root->timestamp:max);
                           else 
                                 return head_count(root->left,low,high,(flip+root->flip)%2,root->timestamp>max?root->timestamp:max);
                      }
                      else
                          return head_count(root->right,low,high,(flip+root->flip)%2,root->timestamp>max?root->timestamp:max);
     }
}


int main()
{
ifstream in;
in.open(FILE);

uint n,q,c,a,b;
in>>n>>q;

Node* root = construct(0,n-1);

FOR(i,q)
{
          in>>c>>a>>b;
        
          if(c==0)
            flip(root,a,b);
          else
              printf("%d\n",head_count(root,a,b));
} 

//system("Pause");
return 0;
}
