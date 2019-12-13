#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	int data[n];
	for(int i=0;i<n;i++)
	scanf("%d",&data[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(abs(data[i]-data[j])==1)
			ans++;
		}
	}
	printf("%d",ans/2);	
	return 0;
} 
