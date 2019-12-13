#include<bits/stdc++.h>
using namespace std;
int data[1010][1010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	scanf("%d",&data[i][j]);
	for(int j=m-1;j>=0;j--)
	{
		for(int i=0;i<n;i++)
		printf("%d ",data[i][j]);
		puts("");
	}
	return 0;
}
