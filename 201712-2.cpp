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

	for(it=obj.begin();it!=obj.end();) //end��������βָ�룬ָ���������һ��Ԫ�ص���һ��λ�� 
	{
		obj.erase(it);
	}	

	cout<<obj.size()<<endl;
    return 0;
}
