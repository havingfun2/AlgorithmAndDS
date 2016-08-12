# include<iostream>
# include<algorithm>
using namespace std;
int main()
{
	string x,y;
	cin>>x>>y;
	int m,n,i,j;
	m=x.length();
	n=y.length();
	int c[m+1][n+1];
	for(i=0;i<=m;++i)
	for(j=0;j<=n;++j)
	{
		if(i==0||j==0)
		c[i][j]=0;
		else if(x[i-1]==y[j-1])
		c[i][j]=c[i-1][j-1]+1;
		else
		c[i][j]=max(c[i-1][j],c[i][j-1]);
	}
	cout<<c[m][n];
}
