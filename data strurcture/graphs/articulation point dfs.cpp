#include<iostream>
#include<vector>
using namespace std;
#include<cmath>
int s[10005],par[10005],dis[10005],low[10005],tim=0,ar[10005];
vector<int>v[10005];
void dfs(int i,int root)
{
	int ch = 0;
	int j,z;
	s[i]=1;
	dis[i]=tim;
	low[i]=tim;
	tim++;
	for(j=0;j<(int)v[i].size();j++)
	{
		z=v[i][j];
		if(!(s[z]))
		{
			ch++;
			par[z]=i;
			dfs(z,0);
			if(!root && low[z]>=dis[i])
			ar[i]=1;
			low[i]=min(low[i],low[z]);
		}
		else if (z != par[i])
            low[i]  = min(low[i], dis[z]);
	}
		if(root &&ch>1)
			ar[i]=1;
}

int main()
{
	int t,q=1;
	cin>>t;
	while(t--)
	{
		int i,o,des,n,m,ct=0;
		cin>>n>>m;
		ct=0;
		tim=0;
		for(i=0;i<10005;i++)
		{
			s[i]=0;par[i]=0;dis[i]=0;low[i]=0;
			v[i].clear(),ar[i]=0;
		}
		for(i=0;i<m;++i)
		{
			cin>>o>>des;
			v[o].push_back(des);
			v[des].push_back(o);
			}
		for(int i =1; i <= n;i++){
			if(!s[i])
			dfs(i,1);
		}
		for(i=0;i<10005;i++)
		if(ar[i])
		ct++;
		cout<<"Case "<<q++<<": "<<ct<<endl;
	}
	return 0;
}


