#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>

#define FILE "input"
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 31

using namespace std;
typedef unsigned int uint;

int hash_alpha[26][26]={
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0},
 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0},
 {0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
 {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0},
 {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
 {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
 {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
};


int hash_digits[10][10]={
{0,0,0,0,0,0,0,0,0,1},
{0,0,1,0,0,0,0,0,0,0},
{0,1,0,1,0,0,0,0,0,0},
{0,0,1,0,1,0,0,0,0,0},
{0,0,0,1,0,1,0,0,0,0},
{0,0,0,0,1,0,1,0,0,0},
{0,0,0,0,0,1,0,1,0,0},
{0,0,0,0,0,0,1,0,1,0},
{0,0,0,0,0,0,0,1,0,1},
{1,0,0,0,0,0,0,0,1,0},
};

int LCS(char next[], char prev[])
{
        if(!strcmp(next,prev)) return -1;

        const int m=strlen(next);
        const int n=strlen(prev);
        int c[m+1][n+1];
        int b[m+1][n+1];
        int points=0;

        FOR(i,m+1) c[i][0]=0;
        FOR(i,n+1) c[0][i] =0;
        //0: left, 1:up, 2:diagnol
        //printf("%s  %s\n",next,prev);

        for(int i = 1;i<m+1;i++){
                    for(int j=1;j<n+1;j++){
                                b[i][j] = 0;

                                if(next[i-1]==prev[j-1]){
                                            c[i][j] = c[i-1][j-1]+1;
                                            b[i][j] = 2;
                                    }
                                else
                                {
                                        if(c[i-1][j]>c[i][j-1])
                                            {
                                                    c[i][j] = c[i-1][j];
                                                    b[i][j] = 1;
                                            }
                                        else
                                        {
                                                    c[i][j] = c[i][j-1];
                                                    b[i][j] = 0;
                                        }
                                }
                    }
        }

        int lcs = c[m][n];

       /* for(int i=1;i<m+1;i++){
                for(int j=1;j<n+1;j++)
                        cout<<b[i][j]<<" ";
                cout<<endl;
        }*/


        if(max(m - lcs,n-lcs)>2) return 0;  //Surcharge is zero
        else{  //Non zero surcharge. Please calculate
                int nex[lcs],pre[lcs];
                int count = lcs-1;
                int r=m, c=n;

                while(r!= 0 && c!=0)
                {
                        if(b[r][c]==0) //left
                            c--;
                        else if(b[r][c]==1) //up
                            r--;
                        else //diagnol
                        {
                            r--; c--;
                            nex[count] = r;
                            pre[count] = c;
                            //cout<<nex[count]<<" "<<pre[count]<<endl;
                            count--;

                        }
                }

                 /*FOR(i,lcs) printf("%d ",nex[i]); cout<<endl;
                 FOR(i,lcs) printf("%d ",pre[i]); cout<<endl;//*/
                int x = 0, y=0,l=0;
                while(x<m && y<n){
                      if(x==nex[l] && y==pre[l]) //nothing
                            {
                                    x++; y++; l++;
                            }
                       else if(x==nex[l] && y!=pre[l]) //deletion
                            {
                                    points++;
                                    y++;
                            }
                        else if(x!=nex[l] && y==pre[l]) //insertion
                        {
                                points++;
                                x++;
                        }
                        else //Replacement
                        {
                            if(next[x]>='a' && next[x]<='z' && prev[y]>='a' && prev[y]<='z'){
                                  if(hash_alpha[next[x] -'a'][prev[y]-'a'])
                                            points++;
                                 else points+=2;
                            }
                            else if(next[x]>='0' && next[x]<='9' && prev[y]>='0' && prev[y]<='9'){
                                    if(hash_digits[next[x]-'0'][prev[y]-'0'])
                                             points++;
                                    else
                                            points+=2;
                            }
                            else points+=2;
                            x++; y++;
                        }
                    }

                    if(x>=m) points+=n-y;
                    else points+= m-x;
                }

        //printf("returning points: %d\n",points);
        if(points<=2) return 50/points;
        else return 0;

}

int main()
{
ifstream in;
in.open(FILE);
uint m,n;

in>>m>>n;
char prev[m][MAX], next[n][MAX];
FOR(i,m)
        in>>prev[i];

FOR(i,n)
        in>>next[i];


FOR(i,n){
        int scharge=0;
        int temp;
        int j=0;
        int count=0;

        for(j=0;j<m;j++){
                            temp = LCS(next[i],prev[j]);
                            if(temp==-1){ scharge=-1; break; }
                            if(temp==25 || temp==50) count++;
                            if(temp>scharge) scharge = temp;
        }

        if(scharge==25 || scharge==50){
            double sum = (double)scharge + (log(count)/log(10));
            //printf("%s: %f\n",next[i],log(count)/log(10));
            printf("%d\n",(int)sum);
        }
        else
            printf("%d\n",scharge);
}

return 0;
}
