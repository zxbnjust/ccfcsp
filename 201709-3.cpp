#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>ans;//�洢��ֵ��
stringstream all;//���ո��ַ��ָ��ַ���
bool DFS(string key)
{
	string value;
	all>>value;
	if(value=="}")
	return 0;
	else if(value=="{")
	{
		if(key!="")
		ans[key]="{}";
		while(DFS(key));
	}
	else
	{
		string v=value.substr(1,value.rfind("\"")-1);
		if(value.back()==':')
		DFS(key.empty()?v:(key+"."+v));
		else
		ans[key]=v;
	}
	return 1;
}
int main(){
    int n,m;
    scanf("%d%d\n",&n,&m);
    string s="";
    while(n--)
	{
        string line;
        getline(cin,line);
        s+=line;
    }
    s=regex_replace(s,regex(" "),"");//ȥ��s�����еĿո��ַ�
    s=regex_replace(s,regex("\\\\\""),"\"");//������������\"�ַ�ת��Ϊ����"�ַ�
    s=regex_replace(s,regex("\\\\\\\\"),"\\");//������������\\�ַ�ת��Ϊ����\�ַ�
    s=regex_replace(s,regex(","),", ");//��ÿ��,�ַ������һ���ո��ַ�
    s=regex_replace(s,regex(":"),": ");//��ÿ��:�ַ������һ���ո��ַ�
    s=regex_replace(s,regex("\\{")," { ");//��ÿ��{�ַ����Ҿ���ӿո��ַ�
    s=regex_replace(s,regex("},?")," } ");//��ÿ��}�ַ����Ҿ���ӿո��ַ�
    all<<s;//���ַ���s����all�а��ո�ָ�
    DFS("");//�ݹ鴦��
    while(m--)
	{//���в�ѯ
        cin>>s;
        if(ans.find(s)==ans.end())
            puts("NOTEXIST");
        else if(ans[s]=="{}")
            puts("OBJECT");
        else
            printf("STRING %s\n",ans[s].c_str());
    }
    return 0;
}


