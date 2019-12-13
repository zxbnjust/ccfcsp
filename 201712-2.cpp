#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;    
    cin>>n;
    vector<int>obj;
    vector<int>::iterator it;
    for(int i=0;i<n;i++) 
    {
        obj.push_back(i+1);
    }

	for(it=obj.begin();it!=obj.end();) //end返回向量尾指针，指向向量最后一个元素的下一个位置 
	{
		obj.erase(it);
	}	

	cout<<obj.size()<<endl;
    return 0;
}
