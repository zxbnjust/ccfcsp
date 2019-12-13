#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,sum=0;
	cin>>n;
	m = n%50;  //买5整数倍瓶酱油剩余钱
	k = m%30;  //之后，买3整数倍瓶酱油剩余钱
	sum = k/10;//之后，能买多少瓶酱油
	sum = sum + (n-m)/50*7 +(m-k)/30*4;
	cout<<sum<<endl;  
	return 0;
}
