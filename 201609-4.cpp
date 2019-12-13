//�ڱ�֤��̾��루Dijkstra�������ǰ����,ʹ��ÿ�����н����������ľ�����С 
#include<bits/stdc++.h>
using namespace std;
int const maxn=10010;
int const INF=pow(10,9);
struct node
{
	int u,cost;
};
vector<node>G[maxn],F[maxn];
bool visit[maxn];
int n,m,d[maxn],d1[maxn],ans=0;                  //d1Ϊ����ǰ�ڵ��������������С���� 
void Dijkstra();
 int main()
{
	scanf("%d%d",&n,&m);
	int a,b,c;
	node temp;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		temp.cost=c;
		temp.u=b;
		G[a].push_back(temp);
		temp.u=a;
		G[b].push_back(temp);
	}
	Dijkstra();
	printf("%d",ans);
	return 0;
}
void Dijkstra()
{
	fill(d,d+maxn,INF);
	memset(visit,0,sizeof(visit));
	memset(d1,0,sizeof(d1));
	d[1]=0;            //�׶�
	for(int i=1;i<=n;i++) 
	{
		int u=-1,MIN=INF;
		for(int j=1;j<=n;j++)
		{
			if(!visit[j]&&d[j]<MIN)
			{
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)
		return;
		visit[u]=1;
		ans+=d1[u];
		for(int j=0;j<G[u].size();j++)
		{
			int v=G[u][j].u;               //ͨ���ڽӱ�õ���u���ڽӵ� 
			if(!visit[v]&&G[u][j].cost+d[u]<d[v])
			{
				d[v]= G[u][j].cost+d[u];
				d1[v]=G[u][j].cost;
			}
			else if(!visit[v]&&G[u][j].cost+d[u]==d[v]&&d1[v]>G[u][j].cost)
			d1[v]=G[u][j].cost;
		}
	}

}
