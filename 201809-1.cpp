#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int data[n],res[n];
	for(int i=0;i<n;i++)
	{
		cin>>data[i];
	}
	res[0] = (data[0] + data[1])/2;
	res[n-1] = (data[n-1] + data[n-2])/2;
	for(int i=1;i<n-1;i++)
	{
		res[i] = (data[i]+data[i-1]+data[i+1])/3;
	}
	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<" ";
	}
	return 0;
 } 
