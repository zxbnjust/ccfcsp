#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n,data[1000],times[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>data[i];
	}
	for(int i =0;i<n;i++)
	{
		times[i] = 0;
		for(int j =0;j<n;j++)
		{
			if (data[i]==data[j])
			{
				times[i] ++;
				
			}
		}
	}
	int max =0;         //出现的最多次数 
	for(int  i =0;i<n;i++)
	{
		if(times[i]>max) 
			max = times[i];
	}
	int min=0,flag=0;     //min是出现最多次数的最小数字 
	for(int i =0;i<n;i++)
	{
		if (times[i]==max &&flag==0)
			{
				min = data[i];
				flag=1;	
			}
		if (times[i]==max &&flag==1 && data[i]<min)
			{
				min = data[i];	
			}
	}
	cout<<min<<endl;
	return 0;
}
