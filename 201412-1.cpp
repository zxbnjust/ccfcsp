#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	scanf("%d",&n);
	int data[n];
	for(int i=0;i<n;i++)
	{
		int k=1;
		scanf("%d",&data[i]);
		for(int j=0;j<i;j++)
		{
			if(data[j]==data[i])
			k++;
		}
		printf("%d ",k);
	}
	return 0;
} 
