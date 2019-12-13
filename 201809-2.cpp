#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int H[n][2],W[n][2];
	for(int i=0;i<n;i++)
	{
		cin>>H[i][0]>>H[i][1];
	}
	for(int i=0;i<n;i++)
	{
		cin>>W[i][0]>>W[i][1];
	}
	int sum=0,j=1;
	for(int i=0;i<n;i++)
	{
		j--;
		for(j;j<n;j++)
		{
			if(W[j][0]>=H[i][0]&&W[j][0]<=H[i][1]&&W[j][1]>=H[i][1])
				sum += H[i][1] - W[j][0];
			else if(H[i][0]>=W[j][0]&&H[i][0]<=W[j][1]&&H[i][1]>=W[j][1])
				sum += W[j][1] - H[i][0];
			else if(W[j][0]>=H[i][0]&&W[j][1]<=H[i][1])
				sum += W[j][1] - W[j][0];
			else if(H[i][0]>=W[j][0]&&H[i][1]<=W[j][1])
				sum += H[i][1] - H[i][0];
			if(W[j][0]>=H[i][1])
			{
				j++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
 } 
