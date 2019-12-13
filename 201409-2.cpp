#include<bits/stdc++.h>
using namespace std;
bool G[110][110]={0};
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	int x1,y1,x2,y2;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=x1;j<x2;j++)
		for(int k=y1;k<y2;k++)
		G[j][k]=1;
	}
	for(int i=0;i<101;i++)
	for(int j=0;j<101;j++)
	{
		if(G[i][j])
		ans++;
	}
	printf("%d",ans);
	return 0;
} 
