#include<bits/stdc++.h>
#include <string>
using namespace std;
void deal(string &s);
int main()
{
	string line;
	int type=2;              //1���� 2���� 3�����б�
	while(getline(cin,line))
	{
		if(line.empty())
		{
			if(type==3)
			{
				cout<<"</ul>"<<endl;            //�б�ĩ�� 
				type=2;
			}
			if(type==1)
			{
				cout<<"</p>"<<endl;            //����ĩ�� 
				type=2;
			}
			continue;	
		}
		if(line[0]=='#')
		{
			type=2;
			int h=0;            //#�ĸ���ͳ�� 
			while(line[h]=='#') 
			h++;
			int pos=line.find(" ");
			while(line[pos]==' ')
			pos++;
			string head=line.substr(pos,line.size()-pos);   //û��#�Ϳո�ı��� 
			deal(head);
			cout<<"<h"<<h<<">"<<head<<"</h"<<h<<">"<<endl;
		}
		else if(line[0]=='*')
		{
			if(type!=3)           //�б�����
			{
				type=3;
				cout<<"<ul>"<<endl;
			} 
			int pos=line.find(" ");
			while(line[pos]==' ')
			pos++;
			string item=line.substr(pos,line.size()-pos);   ////û��*�Ϳո���б�
			deal(item);
			cout<<"<li>"<<item<<"</li>"<<endl;	 
		}
		else
		{
			if(type==1)
			cout<<endl;
			if(type!=1)           //��������
			{
				type=1;
				cout<<"<p>";
			} 
			deal(line);
			cout<<line; 				
		}	
	}
	if(type==3)
	{
		cout<<"</ul>"<<endl;            //�б�ĩ�� 
		type=2;
	}
	if(type==1)
	{
		cout<<"</p>"<<endl;            //����ĩ�� 
		type=2;
	}
	return 0;
}
void deal(string &s)          //�������ڽṹ 
{
	while(s.find("_")!=-1)
	{
		int pos=s.find('_');
		s.replace(pos,1,"<em>");
		pos=s.find('_');
		s.replace(pos,1,"</em>");
	}
	while(s.find('[')!=-1)
	{
		int pos=s.find('[');
		int pos1=s.find(']',pos+1);
		int pos2=s.find(')',pos1+1);
		string text=s.substr(pos+1,pos1-pos-1);
		string link=s.substr(pos1+2,pos2-pos1-2);
		string need = "<a href="+string("\"")+link+string("\"")+">"+text+"</a>";
		s.replace(pos,pos2-pos+1,need);
	}

}
