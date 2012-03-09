#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>

#define INPUT "input.txt"
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAXQ 100000
#define MAXN 200000

typedef unsigned int uint;
typedef unsigned short sint;
typedef unsigned long lint;
using namespace std;

FILE* ifp= fopen(INPUT,"r");
//FILE* ifp = stdin;

/*
 * @author: Vikesh Khanna
 */
class Node
{
    public:
            int val,low,high;
            Node* left, *right;

            Node(int _low,int _high,int _val=-1)
            {
                 val= _val;
                 low = _low;
                 high = _high;
                 left = right = NULL;
            }

            friend ostream& operator<<(ostream& out,const Node& N);
};

ostream& operator<<(ostream& out,const Node& N)
{
         return out<<"("<<N.low<<","<<N.high<<","<<N.val<<")";
}

Node* create_tree(const int a[], int low,int high)
{
      if(low==high)
      {
                   Node* root = new Node(low,high,a[low]);
                   return root;
      }
      else
      {
          Node* root = new Node(low,high);
          int mid = (low+high)/2;
          root->left = create_tree(a,low,mid);
          root->right = create_tree(a,mid+1,high);

          if(root->left!=NULL) root->val = (root->left)->val;
          if(root->right!=NULL && (root->right)->val>root->val) root->val = (root->right)->val;
          return root;
      }
}

int find_max(const int a[],Node* root,int low,int high)
{
    /*Leave if complete overlap, max(left,right)*/
    if(low<=root->low && high>=root->high)
                      return -1;
    else if(high<root->low || low>root->high)
                      return root->val;

    else
         return max(find_max(a,root->left,low,high),find_max(a,root->right,low,high));

    return 1;
}

void inorder(Node* root)
{
     if(root!=NULL)
                   {
                        inorder(root->left);
                        cout<<*root<<endl;
                        inorder(root->right);
                   }
}

int main()
{
int n,q,a[MAXN],x,y;

fscanf(ifp,"%d",&n);

FOR(i,n)
       fscanf(ifp,"%d",&a[i]);

Node* root = create_tree(a,0,n-1);
//inorder(root);
fscanf(ifp,"%d",&q);

FOR(i,q){
        fscanf(ifp,"%d%d",&x,&y);
        printf("%d\n",find_max(a,root,x-1,y-1));
}
//system("Pause");
return 0;
}
