#include<bits/stdc++.h> 
using namespace std;
int main()
{
	char ISBN[14];
	gets(ISBN);
	int j=1,sum=0;
	for(int i=0;i<12;i++)
	{

		if (ISBN[i]<='9'&&ISBN[i]>='0')
		{
			sum = sum + j*(ISBN[i]-'0');

			j++;
		}
	}
	sum = sum % 11;
	if(sum==(ISBN[12]-'0')||(sum==10&&ISBN[12]=='X'))
		cout<<"Right"<<endl;
	else
	{
		for(int i=0;i<12;i++)
		{
			cout<<ISBN[i]; 
		}
		if(sum==10) 
			cout<<"X"<<endl;
		else
			cout<<sum<<endl;
	}
	return 0;
}
