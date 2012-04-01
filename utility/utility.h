/*
@author: Vikesh Khanna
*/

// Euclidean algorithm for GCD
int gcd(int r0,int r1)
{
    int temp;

    if(r1==0) return r0;
    else if(r0==0) return r1;

    if(r0<r1)
              {
                   temp = r0;
                   r0 = r1;
                   r1=temp;
              }

    //r0 is the larger number and r1 is the smaller number
    int remainder;

    do{
        remainder = r0%r1;

        r0=r1;
        r1=remainder;
        }while(remainder!=0);

    return r0;
}

// Sieve of erastrothenes for prime numbers
void sieve(bool a[],int n) /* 1 to n, bool a[n+1] */
{
   FOR(i,n)
   {
    a[i] = true;        
   }
   
   if(n<1) return;

   a[1] = false;

   for(int i=2;i<=n;i++)
    {
        if(a[i]) //prime
        {
            int j=2;
            while(j*i<=n)
            {
                    a[j*i] = false;
                    j++;
            }
        }
    }
}

// Breadth first search for node v starting from node u
bool bfs(vector<int> adj[], int n, int u, int v)
{
     int color[n];
     memset(color,WHITE,sizeof(int)*n);
     
     queue<int> q;
     q.push(u);
     color[u] = GRAY;
     
     while(!q.empty())
     {
          int node = q.front();
          q.pop();
          color[node]=BLACK;
          
          if(node==v)
                     return true;
                     
          int len = adj[node].size();
          
          FOR(i,len){
                    int x = adj[node][i];
                    
                    if(color[x]==WHITE){
                        q.push(x);          
                        color[x] = GRAY;
                    }
          }
     }
     
     return false;
}


// DFS for strongly connected components
void dfs_visit(vector<int> adj[], int u, int color[], int cnt, int scc[])
{
 color[u]=GRAY;
 scc[u] = cnt;
 int len = adj[u].size();
 
 FOR(i,len)
 {
  int v = adj[u][i];
  if(color[v]==WHITE)
  {
   dfs_visit(adj,v,color,cnt, scc);                  
  }          
 }  
 color[u]=BLACK;   
}

void dfs(vector<int> adj[], int n, int scc[])
{
 int color[n];
 memset(color, WHITE, sizeof(int)*n);
 memset(scc, 0, sizeof(int)*n);
 
 int cnt = 0;
 
 FOR(i,n)
 {
    if(color[i]==WHITE)
    {
     dfs_visit(adj, i, color, cnt, scc);
     ++cnt;                  
    }                      
 }      
}

# python - Sieve of erastrothenes for prime numbers
# 1 to n, bool a[n+1] 
def sieve(a,n):
	if n<1:
		return
		
	a = [False for i in range(0,n)]
	
	for i in range(2,n+1):
		if a[i]:
				j=2
				
				while j*i <= n:
					a[j*i] = False
					++j

	
				
