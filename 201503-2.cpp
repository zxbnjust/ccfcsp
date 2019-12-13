#include<bits/stdc++.h>
using namespace std;
struct record
{
	int a,t;
};
bool cmp(record r1,record r2);
int main()
{
	int n;
	scanf("%d",&n);
	record data[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i].a);
	}
	for(int i=0;i<n;i++)
	{
		int k=0;
		for(int j=0;j<n;j++)
		{
			if(data[i].a==data[j].a)
			k++;
		}
		data[i].t=k;
	}
	sort(&data[0],&data[n],cmp);
	for(int i=0;i<n;i++)
	{
		if(i>0&&data[i].a==data[i-1].a)
		continue;
		printf("%d %d\n",data[i].a,data[i].t);
	}
	
	return 0;
}
bool cmp(record r1,record r2)
{
	if(r1.t!=r2.t)
	return r1.t>r2.t;
	return r1.a<r2.a;
}
