#include<iostream>
#include<stdio.h>
using namespace std;
typedef unsigned int uint;


struct Node
{
      Node* left,*right,*p;
      uint val;

      Node(uint val)
      {
            this->val = val;
            left = right = p=NULL;
      } 
};


Node* make_tree(uint low, uint high)
{
	Node* root=NULL;
	
	if(low<=high)
	{
		uint mid = (low+high)/2;
		root = new Node(mid);
		root->left = make_tree(low,mid-1);
		root->right = make_tree(mid+1,high);	
	}	
	return root;
}

void inorder(Node* root)
{
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}

}

int main()
{
Node* root = make_tree(1,100);
inorder(root);

return 0;
}
