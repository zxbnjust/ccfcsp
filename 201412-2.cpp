#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int data[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&data[i][j]);
	bool flag=0;
	for(int i=0;i<=2*n-2;i++)
	{
		int k=max(0,i-n+1);
		if(flag)
		{
			flag=!flag;
			for(int j=k;j<n;j++)
			{
				if(i-j>=0&&i-j<n)
				printf("%d ",data[j][i-j]);
				else
				break;
			}
		}
		else
		{
			flag=!flag;
			for(int j=k;j<n;j++)
			{
				if(i-j>=0&&i-j<n)
				printf("%d ",data[i-j][j]);
				else
				break;
			}
		}
	}
	return 0;
}
