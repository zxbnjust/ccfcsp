#include<bits/stdc++.h>
using namespace std;
struct Vertex
{
    int r,c,t;
    Vertex(int rr,int cc,int tt):r(rr),c(cc),t(tt) {}
};
bool obstacle[105][105][305];//��־�ϰ����߽�ֹͬһʱ���ظ����� 
int n,m,t,direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//����
int main(){
    scanf("%d%d%d",&n,&m,&t);
    while(t--)
	{
        int r,c,a,b;
        scanf("%d%d%d%d",&r,&c,&a,&b);
        for(int i=a;i<=b;++i)//������Σ��ʱ����ڵĸ���ֱ�ӱ�־Ϊ�������
        obstacle[r][c][i]=true;
    }
    queue<Vertex>q;
    q.push(Vertex(1,1,0));
    obstacle[1][1][0]=true;
    while(!q.empty())
	{
        Vertex v=q.front();
        q.pop();
        if(v.r==n&&v.c==m){//�������յ㣬���ʱ��
            printf("%d",v.t);
            return 0;
        }
        for(int i=0;i<4;++i){
            int r=v.r+direction[i][0],c=v.c+direction[i][1],t=v.t+1;
            if(r>0&&r<=n&&c>0&&c<=m&&!obstacle[r][c][t]){
                q.push(Vertex(r,c,t));
                obstacle[r][c][t]=true;
            }
        }
    }
    return 0;
}
