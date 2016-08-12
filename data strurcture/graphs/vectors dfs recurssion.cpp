# include<iostream>
# include<vector>
using namespace std;
int s[10000];
vector<int>v[10000000];
void dfs(int i)
{
	int j;
	if(s[i])
	return ;
	s[i]=1;
	cout<<i<<endl;
	for(j=0;j<v[i].size();j++)
	{
		if(!(s[v[i][j]]))
		dfs(v[i][j]);
	}
}
int main()
{
	int i,o,des,n;
	cin>>n;
	
	for(i=0;i<n;++i)
	{
		cin>>o>>des;
		v[o].push_back(des);
	}
	cin>>i;
	dfs(i);
}

