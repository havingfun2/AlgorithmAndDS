//if start time of current activity is greater than the finish time of last activity than prinnt it :D
# include<iostream>
# include<algorithm>
using namespace std;
int act(int a[],int b[],int n)
{
	int j,i=0;
	cout<<i<<"\t";
	for(j=1;j<n;j++)
	{
		if(a[j]>=b[i])
		{
			cout<<j<<"\t";
			i=j;
		}
	}
}
int main()
{
	int a[100],b[100],i,n,x;
	cout<<"Toatal No. Of Elements To Be Inserted\n";
	cin>>n;
	cout<<"Enter elements of start time array\n";
	for(i=0;i<n;++i)
	cin>>a[i];
	cout<<"Enter elements of finish time array\n";
	for(i=0;i<n;++i)
	cin>>b[i];
	sort(b,b+n);
	act(a,b,n);
	return 0;
}
