#include<bits/stdc++.h> 
using namespace std;
void left_mov(int pos,int summon[][2]);    
void right_mov(int pos,int summon[][2]);
//Â¯Ê¯´«Ëµ 
int main(){
	int first[7][2]={0},enemy[7][2]={0};  
	int hp1=30,hp2=30;
	int count,win=0,sum1=0,sum2=0;
	int pos,hp,at,pos1,pos2;
	char com[10];
	bool flag=0;
	cin>>count;
	for (int i=0;i<count;i++)
	{
		cin>>com;
		//cout<<com<<endl; 
		if (com[0]=='s')
		{
			cin>>pos>>at>>hp;
			if(!flag){
				right_mov(pos,first);
				first[pos-1][0]=at,first[pos-1][1]=hp;
				sum1++;
			}	
			if(flag){
				right_mov(pos,enemy);
				enemy[pos-1][0]=at,enemy[pos-1][1]=hp;
				sum2++;
			}		
		}
		
		if (com[0]=='e')  flag=!flag;
		

		if(com[0]=='a')
		{
			cin>>pos1>>pos2;
			if(!flag)
			{
				if(pos2==0)	hp2-=first[pos1-1][0];
				else
				{
					enemy[pos2-1][1]-=first[pos1-1][0];
					first[pos1-1][1]-=enemy[pos2-1][0];
					if(enemy[pos2-1][1]<=0) left_mov(pos2,enemy),sum2--;

					if(first[pos1-1][1]<=0) left_mov(pos1,first),sum1--;		
				}
			}
			if(flag)
			{
				if(pos2==0){
					hp1-=enemy[pos1-1][0];
				}
				else{
					enemy[pos1-1][1]-=first[pos2-1][0];
					first[pos2-1][1]-=enemy[pos1-1][0];
					if(enemy[pos1-1][1]<=0) left_mov(pos1,enemy),sum2--;
					if(first[pos2-1][1]<=0) left_mov(pos2,first),sum1--;		
				}		
			}
		
		}
		
		
	}
	if(hp1<=0) win=-1;
	if(hp2<=0) win=1;

	cout<<win<<endl;
	cout<<hp1<<endl;
	cout<<sum1;
	for(int i=0;i<sum1;i++) cout<<" "<<first[i][1];
	cout<<endl;
	
	
	cout<<hp2<<endl;
	cout<<sum2;
	for(int i=0;i<sum2;i++) cout<<" "<<enemy[i][1];	
	
	return 0;

}

void left_mov(int pos,int summon[7][2])
{
	for(int i=pos;i<7;i++)
	{
		summon[i-1][0]=summon[i][0];
		summon[i-1][1]=summon[i][1];
	}
}

void right_mov(int pos,int summon[7][2])
{
	for(int i=5;i>=pos-1;i--)
	{
		summon[i+1][0]=summon[i][0];
		summon[i+1][1]=summon[i][1];
	}
}





	
 
