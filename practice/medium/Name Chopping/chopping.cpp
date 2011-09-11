#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

#define FILE "input"
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 52

using namespace std;
typedef unsigned int uint;


class Node
{
        public:
            char key;
            Node* ptr[MAX];
            Node(char key)
            {
                this->key = key;
                FOR(i,MAX)
                    ptr[i] = NULL;
            }
};

class Tree
{

        public:
                Node* root;
                Tree() {root=NULL;}
};


int main()
{
ifstream in;
in.open(FILE);

Tree t[MAX];

uint n;
int max=-1;
in>>n;

FOR(T,n){
        char s[100];
        int offset, count=0;
        in>>s;

        uint len = strlen(s);
        if(s[0]>='a' && s[0]<='z') offset = s[0] - 'a';
        else offset = s[0] - 'A' + 26;

        if(t[offset].root==NULL) t[offset].root = new Node(s[0]);
        else
                count++;

        Node* root = t[offset].root;

        for(int i=1;i<len;i++){

                if(s[i]>='a' && s[i]<='z') offset = s[i] - 'a';
                else offset = s[i] - 'A' + 26;


                if(root->ptr[offset]==NULL)
                        root->ptr[offset] = new Node(s[i]);
                else count++;
                root = root->ptr[offset];
        }
        if(count>max) max=count;
        //cout<<"End\n";
}

printf("%d\n",max);

return 0;
}
