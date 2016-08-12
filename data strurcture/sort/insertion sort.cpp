# include<iostream>
using namespace std;
int main()
{
	int a[100],i,n,temp,j;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=1;i<n;++i)
	{
		temp=a[i];
		j=i-1;
		while(a[j]>temp && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	for(i=0;i<n;++i)
	cout<<a[i]<<endl;
}
