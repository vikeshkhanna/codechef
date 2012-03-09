#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;
typedef unsigned int uint;
#define FOR(i,n) for(int i=0;i<n;i++)
#define in(n) scanf("%d",&n)

struct Node
{
      Node* left,*right,*p;
      uint val,lcount;
      
      Node(uint val)
      {
            this->val = val;
	        left = right = p=NULL;
      } 
};


class Tree
{
	private:
		Node* make_tree(uint, uint, Node*);
	public:
		Node* root;
		Node* tree_successor(Node* );
		Node* tree_search_pos(uint);
		void tree_delete(Node* );
		void inorder(Node* );
		Tree(uint low, uint high,Node* p=NULL)
		{
			root = make_tree(low,high,p);
		}
};


Node* Tree::make_tree(uint low, uint high,Node* p=NULL)
{
	Node* root=NULL;

	if(low<=high)
	{
		uint mid = (low+high)/2;
		root = new Node(mid);
		root->p = p;
		root->lcount = mid-low;
       	root->left =  make_tree(low,mid-1,root);
		root->right = make_tree(mid+1,high,root);	
	}	
	return root;
}

Node* Tree::tree_successor(Node* z )
{
     Node* x=NULL;

     if(z->right!=NULL){
                       Node* temp = z->right;
                       
                       while(temp->left!=NULL)
                                             temp=temp->left;
                       x = temp;
     }
     else
     {
         Node* temp = z->p;
         
         while(temp!=NULL && z==temp->right)
                        { z=temp; temp=temp->p; }        
                       
                 if(temp!=NULL) x = temp;  
     }
    return x;	
}

/* Delete returns  */
void Tree::tree_delete(Node* z)
{
     Node* x=NULL;
     Node* y;
     //cout<<"Deleting :"<<z->val<<endl;    

     if(z->left==NULL || z->right==NULL)
                     y = z;
    else 
                     y = tree_successor(z); 
    
     if(y->left!=NULL) 
                x = y->left;
   
     else
                x = y->right;
      
    if(x!=NULL) x->p=y->p;
   
	
    //cout<<"To Splice :"<<y->val<<endl;    
    //if(x!=NULL)cout<<"x: "<<x->val<<endl;

    if(y!=z){ /* Update counts */
              z->val = y->val;
              Node* temp = y;
		      while(temp->p!=NULL && temp!=z)
              {
                            if(temp==temp->p->left) temp->p->lcount--;
                            temp = temp->p;              
              }
		  }
     
	if(y->p==NULL)
           root = x;
     else {
		  if(y==y->p->left) 
			y->p->left = x;
                   else 
			y->p->right = x; 
          }
 
  //cout<<"Deleted"<<y->val<<endl; 
  delete y;           
}

/* Debug */
void Tree::inorder(Node* root)
{
	if(root!=NULL){
		inorder(root->left);
		printf("%d (%d) ",root->val,root->lcount);
		inorder(root->right);
	}
}

/* Warning : Tree search pos aniticipates immediate deletion */
Node* Tree::tree_search_pos(uint search)
{
		Node* temp = root;
	    
	    while(search!=temp->lcount+1)
	    {
                       if(search>temp->lcount+1){
                                        search -=(temp->lcount+1);  
                                        temp = temp->right;
                       }                 
                       else
                           {
                                          temp->lcount--;
                                          temp =temp->left;
                           }
        }
	    
        return temp;
}


int main()
{
uint t;
in(t);

FOR(T,t)
{
	uint n;
	in(n);		
	uint a[n], ans[n];
	Tree T(1,n);
	FOR(i,n) in(a[i]);
	
	for(int i=n-1;i>=0;i--)
	{
		uint search = i+1 - a[i];
		//T.inorder(T.root);
	    Node* item = T.tree_search_pos(search);
		ans[i] = item->val;
		
	    T.tree_delete(item);
   	}
   	
   	FOR(i,n)
   	        printf("%d ",ans[i]);
    printf("\n");
}
//Node* x= tree_successor(root->right->right->right->right->right->right);

return 0;
}
