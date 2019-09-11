#include<bits/stdc++.h>
using namespace std;
int find(int data[][3],int K) 
{
	int min=20000;
	for(int i=1;i<K+1;i++)      //最小取钥匙（还钥匙）时刻 
	{
		if(data[i][1]<min) 
			min=data[i][1];
		if(data[i][2]<min) 
			min=data[i][2];
	}
	int min_key=1000;           //同一时刻要还的钥匙的最小编号 
	for(int i=1;i<K+1;i++)       
	{
		if(data[i][2]==min&&min_key>data[i][0]) 
		{
			min_key = data[i][0];
			
		} 
	}
		for(int i=1;i<K+1;i++)      //先还钥匙,负的i代表还 
	{
		if(data[i][2]==min&&min_key==data[i][0]) 
		{
			data[i][2]=20000;   //不再考虑此值 
			return i*-1;
			
		} 
	}
	for(int i=1;i<K+1;i++)      //后取钥匙,正的i代表取 
	{
		if(data[i][1]==min) 
		{
			data[i][1]=20000;   //不再考虑此值 
			return i;
		} 
	}

}
void get_key(int keys[],int key_seq,int N) 
{
		for(int i=0;i<N;i++)
	{
		if (keys[i]==key_seq)
		{
				keys[i] = 0;
				break;
		}
					      
	}
}
void return_key(int keys[],int key_seq,int N) 
{
		for(int i=0;i<N;i++)
	{
		if (keys[i]==0)
		{
			keys[i] = key_seq;	
			break;
		}
				      
	}
}
int main()
{
	int N,K;
	cin>>N>>K;
	int data[K+1][3];
	for(int i=1;i<K+1;i++)
	{
		cin>>data[i][0]>>data[i][1]>>data[i][2];
		data[i][2] += data[i][1] ;          //还钥匙时间 
	}
	int keys[N];           //钥匙序列 
	for(int i=0;i<N;i++)
	{
		keys[i]=i+1;       
	}
	
	for(int i=0;i<2*K;i++)  //取还钥匙,共2*K次 
	{
		int num =find(data,K);
		if(num>0) //取钥匙
			 get_key(keys,data[num][0],N);
		if(num<0)  //还钥匙 
			 return_key(keys,data[num*-1][0],N);
	}
		for(int i=0;i<N;i++)     //输出结果 
	{
		cout<<keys[i]<<' ';       
	}
	return 0;
}
