#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d%d\n",&m,&n);
	string temp[m];
	unordered_map<string,string>var;
	string key,value;
	for(int i=0;i<m;i++)
	getline(cin,temp[i]);
	for(int i=0;i<n;i++)
	{
		getline(cin,key);
		int p=key.find(" ");
		value = key.substr(2+p,key.size()-p-3);
		key = key.substr(0,p);
		var[key]=value;	
	}
 //�пӣ�������name {{ name }},����ѭ�� 
    int p,q; 
	for(int i=0;i<m;i++)
	{
		p=-1;
		while(temp[i].find("{{",p+1)!=-1)       //�б���,��p+1λ�ÿ�ʼѰ�� 
		{
			
			p=temp[i].find("{{");
			q=temp[i].find("}}");
			key=temp[i].substr(p+3,q-p-4);
			value=var[key];
			temp[i].replace(p,q-p+2,value);	
		}
		cout<<temp[i]<<endl;
	}
	return 0;
}
