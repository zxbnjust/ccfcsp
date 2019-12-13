#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> data;
	for(int i=1;i<=n;i++)
	data.push_back(i);
	int p,q,k;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		for(int j=0;j<n;j++)
		{
			if(data[j]==p)
			{
				k=j;
				break;
			}
		}
		data.erase(data.begin()+k);
		k = k+q;
		data.insert(data.begin()+k,p);
	}
	for(int i=0;i<n;i++)
	printf("%d ",data[i]);
	return 0;
} 
