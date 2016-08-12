# include<iostream>
using namespace std;
int main()
{
	int n,i,j,loc,min,a[100];
	cin>>n;
	for(i=0;i<n;++i)
	cin>>a[i];
	for(i=0;i<n;++i)
	{
		min=a[i];
		loc=i;
		for(j=i+1;j<n;++j)
		{
			if(a[j]<min)
			{
				min=a[j];
				loc=j;
			}
		}
		if(i!=loc)
		{
			int temp=a[i];
			a[i]=a[loc];
			a[loc]=temp;
		}
	
	}
	for(i=0;i<n;++i)
	cout<<a[i]<<endl;
}
