#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename T1,typename T2>
struct less_second
{
	typedef pair<T1,T2>temp;
	bool operator()(temp const& a,temp const& b)const
	{
		return a.second<b.second;
	}
 
};
int main()
{
	vector<pair<int,int> >v;
	vector<pair<int,int> >::iterator it;
	for(int i=0;i<10;i++)
	{
		int x,y;
		cin>>x>>y;
		v.push_back(pair<int,int> (x,y));
	}
	sort(v.begin(),v.end(),less_second<int, int>());
	for(it=v.begin();it!=v.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}
