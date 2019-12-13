#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,num;
};
int main()
{
	int T,n;
	scanf("%d%d\n",&T,&n);              //n个进程，T份代码 
	string temp,temp1; 
	node p;
	while(T--)
	{
		queue<node>data[n];
		for(int i=0;i<n;i++)  //输入数据 
		{
			getline(cin,temp);
			stringstream ss;
			ss<<temp;
			while(ss>>temp1)
			{
				if(temp1[0]=='R')
				p.id=0;
				else
				p.id=1;
				p.num=stoi(temp1.substr(1,temp1.size()-1));
				data[i].push(p);
			}
		}
		int flag;
		while(1)
		{
			flag=0;
			for(int i=0;i<n;i++)
			{
				if(!data[i].empty())          //该进程还未结束
				{
					node h=data[i].front();
					if(data[h.num].empty())      //另一进程已经结束,提前自锁 
					{
						flag=-1;
						break;
					}				
					node h1=data[h.num].front();
					if(h.id!=h1.id&&h1.num==i)  //匹配 
					{
						data[i].pop();
						data[h.num].pop();
						flag=1;	 
						i--;
					}		
				}	 
			}
			if(flag!=1)
			break;
		}
		if(flag==-1)
		{
			printf("1\n");
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(!data[i].empty())
			{
				flag=1;
				break;
			}	
		}
		if(flag)
		printf("1\n");
		else
		printf("0\n");
	}
	return 0;
}
