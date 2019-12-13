#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,low,high;
	scanf("%d",&n);
	int data[n];
	for(int i=0;i<n;i++)
	scanf("%d",&data[i]);
	for(int i=0;i<n;i++)
	{
		low=0;
		high=0;
		for(int j=0;j<n;j++)
		{
			if(i!=j&&data[i]<data[j])
			high++;
			if(i!=j&&data[i]>data[j])
			low++;
		}
		if(low==high)
		{
			printf("%d",data[i]);
			return 0;
		}
	}
	printf("-1");
	return 0;
} 
