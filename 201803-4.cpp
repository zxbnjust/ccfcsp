#include<bits/stdc++.h>
using namespace std;
int data[3][3];
int empty();
int score();     
void DFS();
bool visit[2][9]={0};     
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			scanf("%d",&data[i][j])	;
		}
	}
	DFS();
	return 0; 
}
void DFS() 
{
	int s=score(); 
	int e=empty();
	if(s!=20)              //有胜负 
	{
		printf("%d",s);
		return 0;
	}
	for(int i=0;i<e;i++)
	
	
	
	
	
	
	
	
	
	
	
}

int score()
{
	if(!empty())              //平局 
	return 0;
	int a=empty()+1;
	for(int i=0;i<3;i++) 
	{
		if(data[i][0]==data[i][1]&&data[i][1]==data[i][2]&&data[i][0])      //行获胜 
		{
			if(data[i][0]==1)
			return a;
			else
			return -a;	
		}
		if(data[0][i]==data[1][i]&&data[1][i]==data[2][i]&&data[1][i])      //列获胜 
		{
			if(data[0][i]==1)
			return a;
			else
			return -a;	
		}	
	}
	if(data[0][0]==data[1][1]&&data[1][1]==data[2][2]&&data[0][0])         //对角线获胜 
	{
		if(data[0][0]==1)
		return a;
		else
		return -a;
	}
	if(data[0][2]==data[1][1]&&data[1][1]==data[2][0]&&data[1][1])         ///次对角线获胜 
	{
		if(data[1][1]==1)
		return a;
		else
		return -a;
	}
	return 20;
}
int empty()
{
	int a=0;
	for(int i=0;i<3;i++) 
	for(int j=0;j<3;j++) 
	{
		if(!data[i][j])
		a++;
	}
	return a;
}
