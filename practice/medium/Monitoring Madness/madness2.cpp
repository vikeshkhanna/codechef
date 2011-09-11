#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>

#define INPUT "input"
#define parent(i) (int)((i-1)/2)
#define left(i) 2*i+1
#define right(i) 2*i+2
#define MAX 100
#define ind(v) fscanf(ifp,"%d",&v)
#define inc(v) fscanf(ifp,"%c",&v)
#define ins(str) fscanf(ifp,"%s",str)
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
FILE* ifp = fopen(INPUT,"r");

class Maxheap
{
        public:
            int size;
            int a[26];
            int *deg, *back;
            bool* admin;

            Maxheap(int* deg, int* back,bool* admin)
            {
                    size = 0;
                    this->deg = deg;
                    this->back = back;
                    this->admin = admin;
            }

            void build_heap()
            {
                FOR(i,26)
                        if(deg[i]!=-1){
                                a[size] = i;
                                back[i] = size;
                                size++;
                            }
               for(int i=size/2;i>=0;i--)
                    max_heapify(i);

            }

            void max_heapify(int i)
            {
                int left, right, largest;

                while(i<size){
                        largest = i;
                        left = left(i);
                        right = right(i);

                        if(left<size && deg[a[left]]>deg[a[largest]]) largest = left;
                        if(right<size && deg[a[right]]>deg[a[largest]]) largest = right;

                        if(largest!=i)
                        {
                            int temp = a[i];
                            a[i]  = a[largest];
                            a[largest] = temp;
                            back[a[i]] = i;
                            back[a[largest]] = largest;
                        }
                        else break;
                        i=largest;
                    }
            }

            void decrease_key(int i) //i is the (0.26) vertex number
            {
                int index = back[i];
                //cout<<"back found: "<<back[i]<<endl;
                deg[a[index]]--;
                max_heapify(index);
            }

            int extract_max()
            {
                int ret = a[0];
                a[0] = a[size-1];
                a[size-1] = ret;
                back[a[0]] = 0;
                back[a[size-1]] = size-1;
                size--;
                max_heapify(0);
                back[ret] = -1;
                //admin[ret]=true;
                return ret;
            }

            bool empty()
            {
                    return size==0;
            }

            void print()
            {
                cout<<"******************"<<endl;
                    FOR(i,size){
                        cout<<"("<<(char)('A' + a[i])<<","<<deg[a[i]]<<","<<back[a[i]]<<","<<admin[a[i]]<<")"<<endl;
                  }

                cout<<"******************"<<endl;
            }

};


int main()
{
    int t,n, deg[26],back[26];
    bool admin[26];
    vector<int> adj[26];

    char a,b;
    fscanf(ifp,"%d",&t);
    fgetc(ifp);

    FOR(T,t)
    {
        int count=0;
        fscanf(ifp,"%d",&n);
        fgetc(ifp);

        FOR(i,26)
            {
                deg[i] = back[i] = -1;
                admin[i] = false;
                adj[i].clear();
            }

        FOR(i,n){
                a = fgetc(ifp); fgetc(ifp);
                b = fgetc(ifp); fgetc(ifp);
                //cout<<i<<": "<<a<<b<<endl;
                adj[a-'A'].push_back(b-'A');
                adj[b-'A'].push_back(a-'A');
        }

        /*
                FOR(i,26){
            FOR(j,adj[i].size())
                    cout<<adj[i][j]<<" ";
            cout<<endl;
        }*/

        FOR(i,26){
            int len = adj[i].size();
            if(len>0)
                    deg[i] = len;
                //cout<<deg[i]<<endl;
            }

        Maxheap H(deg,back,admin);
        H.build_heap();

        while(!H.empty())
        {
            //H.print();
            int v = H.extract_max();

           // cout<<"general: "<<(char)('A' + v)<<endl;

            //cout<<v<<"admin: "<<admin[v]<<endl;  sleep(1);
            //cout<<v<<"admin: "<<admin[v]<<endl;  sleep(1);
            int len = adj[v].size();

            if(!admin[v]){
                //cout<<"Counted: "<<(char)('A' + v)<<endl;
                count++; admin[v]=true;
                FOR(i,len)
                {
                    int n = adj[v][i], len2 = adj[n].size();

                    if(!admin[n]) {
                                H.decrease_key(n);
                                admin[n] = true;
                            }
                    //cout<<"Editing adj "<<(char)('A' + adj[v][i])<<endl;

                    FOR(j,len2)
                    {
                        //cout<<"Editing adj inside "<<(char)('A' + adj[n][j])<<endl;
                        int n2 = adj[n][j];
                        if(!admin[n2]) H.decrease_key(n2);
                    }
                }
            }
        }

        printf("%d\n",count*100);
        //H.decrease_key(0);
        //cout<<H.extract_max()<<endl;
        /*
        FOR(i,H.size){
            cout<<(char)('A' + H.a[i])<<endl;
        }*/
        /*
        FOR(i,26)
            cout<<back[i]<<endl;

        */
    }

return 0;
}
