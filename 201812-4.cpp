#include<bits/stdc++.h>
using namespace std;
int n,m,root;
int const maxn=50010;
int const INF=pow(10,9);
struct node
{
	int v,cost;
};
vector<node>G[maxn];
int d[maxn];              
bool visit[maxn]={0};
int prim(int r);
int main()
{
	int v,u,t;
	scanf("%d%d%d",&n,&m,&root);
	node temp;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&v,&u,&t);
		temp.v=v;
		temp.cost=t;
		G[u].push_back(temp);
		temp.v=u;
		G[v].push_back(temp);
	}
	int ans=prim(root);
	printf("%d",ans);
	return 0;
}
int prim(int r)
{
	fill(d,d+maxn,INF);
	d[r]=0;
	int a=0;
	for(int i=1;i<=n;i++)
	{
		int u=-1,min=INF;
		for(int j=1;j<=n;j++)
		{
			if(!visit[j]&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1)
		break;
		visit[u]=1;
		if(min>a)
		a=min;
		for(int j=0;j<G[u].size();j++)
		{
			int v=G[u][j].v;
			if(!visit[v]&&G[u][j].cost<d[v])
			d[v]=G[u][j].cost;
		}	
	}
	return a;
}
