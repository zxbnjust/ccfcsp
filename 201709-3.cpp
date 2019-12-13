#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>ans;//存储键值对
stringstream all;//按空格字符分割字符串
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
    s=regex_replace(s,regex(" "),"");//去掉s中所有的空格字符
    s=regex_replace(s,regex("\\\\\""),"\"");//将两个连续的\"字符转换为单个"字符
    s=regex_replace(s,regex("\\\\\\\\"),"\\");//将两个连续的\\字符转换为单个\字符
    s=regex_replace(s,regex(","),", ");//在每个,字符后添加一个空格字符
    s=regex_replace(s,regex(":"),": ");//在每个:字符后添加一个空格字符
    s=regex_replace(s,regex("\\{")," { ");//在每个{字符左右均添加空格字符
    s=regex_replace(s,regex("},?")," } ");//在每个}字符左右均添加空格字符
    all<<s;//将字符串s送入all中按空格分割
    DFS("");//递归处理
    while(m--)
	{//进行查询
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


