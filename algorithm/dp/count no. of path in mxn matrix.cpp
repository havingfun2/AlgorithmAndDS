# include<iostream>
using namespace std;
int path(int m, int n)
{
	int c[m][n],i,j;
	for(i=0;i<m;++i)
	c[i][0]=1;
	for(j=0;j<n;++j)
	c[0][j]=1;
	for(i=1;i<m;++i)
	for(j=1;j<n;++j)
	c[i][j]=c[i-1][j]+c[i][j-1];
	return c[m-1][n-1];
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<path(m,n);
}
