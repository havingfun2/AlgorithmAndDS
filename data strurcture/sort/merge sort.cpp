# include<iostream>
# include<algorithm>
using namespace std;
int main()
{
	int n,n1,a[100],b[100],i,j,k,x;
	cin>>n>>n1;
	for(i=0;i<n;++i)
	cin>>a[i];
	for(i=0;i<n1;++i)
	cin>>b[i];
	x=n+n1;
	int c[x];
	sort(a,a+n);w
	sort(b,b+n1);
	for(i=j=k=0;;)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=b[j];
			j++;
			k++;
		}
		if(i==n||j==n1)
		break;
	}
	for(;i<n;)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	for(;j<n1;)
	{
		c[k]=b[j];
		j++;
		k++;
	}
	for(i=0;i<x;++i)
	cout<<c[i]<<endl;
}
