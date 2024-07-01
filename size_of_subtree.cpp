//-->single source sortest path
#include<bits/stdc++.h>
using namespace std;
# define N 1000006

vector<int>adj[10005];
int vis[10005];
int dis[10005];
int sub_sz[N];
int dfs(int u){
	
     vis[u]=1;
     
     int cur_sz=1;
     
	for(auto v:adj[u])
	{
		if(!vis[v])
		{
			cur_sz+=dfs(v);
		}
	}
	sub_sz[u]=cur_sz;
	return cur_sz;
	
	
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
    
    int ans=dfs(4);
    for(int i=1;i<=n;i++)
    {
    	cout<<sub_sz[i]<<" ";
    }
	
}	