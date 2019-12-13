#include<bits/stdc++.h>
using namespace std;
int cal(int s);
int main()
{
	int n,b;
	scanf("%d",&n);
	b=n-n%100;
	while(1)
	{
		int money=cal(b);
		if(money==n)
		{
			printf("%d",b);
			return 0;
		}
		b=b+100;
	}
	return 0;
} 
int cal(int s)
{
	if(s<=3500)
	return s;
	if(s<=5000)
	return s-(s-3500)*3/100;
	if(s<=8000) 
	return s-(s-5000)/10-45;
	if(s<=12500)
	return s-(s-8000)/5-345;
	if(s<=38500)
	return s-(s-12500)/4-1245;
	if(s<=58500)
	return s-(s-38500)*3/10-7745;
	if(s<=83500)
	return s-(s-58500)*35/100-13745;
	return s-(s-83500)*45/100-22495;
}
