//no. of path in grid pasing through the given points
#include <iostream>
using namespace std;
# define mo 1000000007

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,i1=0,j1=0,ct=1,i,j;
		cin>>n>>m;//cout<<n<<m<<" ";
		while(m--)
		{
			long long x,y;
			cin>>x>>y;
			long long a[x-i1+1][y-j1+1];
			for(i=0;i<x-i1+1;i++)
			{
				for(j=0;j<y-j1+1;j++)
				{
					if(!i&&!j)
					a[i][j]=1;
					else if(!j&&i)
					a[i][j]=a[i-1][j]%mo;
					else if(!i&&j)
					a[i][j]=a[i][j-1]%mo;
					else
					a[i][j]=((a[i-1][j]%mo)+(a[i][j-1]%mo))%mo;
				}
			}
			ct=((ct%mo)*(a[x-i1][y-j1]%mo))%mo;//cout<<ct<<endl;
			i1=x;
			j1=y;
		}
		long long a[n-i1][n-j1];
			for(i=0;i<n-i1;i++)
			{
				for(j=0;j<n-j1;j++)
				{
					if(!i&&!j)
					a[i][j]=1;
					else if(!j&&i)
					a[i][j]=a[i-1][j]%mo;
					else if(!i&&j)
					a[i][j]=a[i][j-1]%mo;
					else
					a[i][j]=((a[i-1][j]%mo)+(a[i][j-1]%mo))%mo;
				}
			}
			ct=((ct%mo)*(a[n-i1-1][n-j1-1]%mo))%mo;
		cout<<ct<<endl;}
	return 0;
}

