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
      Node* left,*right;
      uint val, lcount, rcount;
      
      Node(uint val)
      {
            this->val = val;
            lcount = rcount = 0;
            left = right = NULL;
      } 
};

void inorder(Node* root,Node* last)
{
     if(root!=NULL){
                    inorder(root->left,last);
                    printf("%d",root->val);
                    if(root!=last) printf(" "); else printf("\n");
                    inorder(root->right,last);
      }
}


int main()
{
ifstream in;
in.open(FILE);
uint t,n;
scanf("%d",&t);

FOR(T,t)
{
        scanf("%d",&n);
        Node* root;
        uint a[n];
        
        FOR(i,n)scanf("%d",&a[i]);

        root = new Node(1);
       
        for(int i=1;i<n;i++)
        {
                uint shift = a[i];
                Node* newnode = new Node(i+1);
                
                Node* temp = root;
                Node* p = temp;
                uint dir;
                
                while(temp!=NULL){
                                     p = temp;
                                     
                                     if(temp->rcount>=shift){
                                           temp->rcount++;
                                           temp=temp->right;
                                           dir = 1;
                                     }
                                     else
                                     {
                                           dir = 0;
                                           shift-= temp->rcount + 1;
                                           temp->lcount++;
                                           temp=temp->left;
                                     }
                }
                
                if(dir==1) p->right = newnode;
                else p->left = newnode;
        }
        
         Node* temp = root;
         while(temp->right!=NULL) temp = temp->right;
         inorder(root,temp);
}


system("Pause");
return 0;
}
