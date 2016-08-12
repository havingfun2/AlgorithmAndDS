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
	int in=c[m][n];
	i=m;
	j=n;
	char lcs[in+1];
	lcs[in]='\0';
	while(i>0&&j>0)
	{
		if(x[i-1]==y[j-1])
		{
			lcs[in-1]=x[i-1];
			i--;
			j--;
			in--;
		}
		else if(c[i-1][j]>c[i][j-1])
		i--;
		else
		j--;
	}
	cout<<lcs;
}
