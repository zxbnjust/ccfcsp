#include<bits/stdc++.h>
using namespace std;
int n,m;
int const maxn=1010;
bool G[maxn][maxn]={0}; 
void floyd();
int main()
{
	scanf("%d%d",&n,&m);
	memset(G,0,sizeof(G));
	int a,b;
	while(m--)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
	}
	for(int i=1;i<=n;i++)
	G[i][i]=1;
	floyd();
	int know[maxn];
	memset(know,0,sizeof(know));
	for(int i=1;i<=n;i++)            //ÐÐ 
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if(!G[i][j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		know[i]=1;
	}
	for(int i=1;i<=n;i++)          //ÁÐ 
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if(!G[j][i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		know[i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	ans+=know[i];
	printf("%d",ans);
	return 0;
}

void floyd()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(G[i][j])
		continue;
		if(!G[i][k]||!G[k][j])
		continue;
		G[i][j]=1;	
	}
}
