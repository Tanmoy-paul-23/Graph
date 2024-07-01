#include<bits/stdc++.h>
using namespace std;

#define ll long long 

#define INF (1LL<<62)
# define N 1000006
# define mod 1000000007

vector<int> adj[N];
int vis[N];
int cur_cc=0;
int cc[N];
void dfs(int u)
{
	vis[u]=1;
	cc[u]=cur_cc;
	
	for(int v:adj[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	int  t; cin>>t;
	string op;
	
	while(t--)
	{	
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>>edges;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			adj[i].clear();
		}
		
		for(int i=0;i<m;i++)
		{
			int a , b;
			cin>>a>>op>>b;
			
			if(op == "=")
			{
				adj[a].push_back(b);
				adj[b].push_back(a);
				
			}
			else
			{
				edges.push_back({a,b});
			}
		}
		cur_cc=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cur_cc++;
				dfs(i);
			}
		}
		
		int ok=true;
		
		for(int i=0;i<edges.size();i++)
		{
			int a=edges[i].first;
			int b=edges[i].second;
			if(cc[a]==cc[b])
			{
				ok=false;
				break;
			}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
		
		
		
		
		
		
	
	
      


	
	}
	
}
