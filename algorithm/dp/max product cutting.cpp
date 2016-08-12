# include<iostream>
using namespace std;
int ma(int n)
{
	if(n==1 || n==0)
	return 0;
	else if(n==2 || n==3)
	return n;
	else
	{
		int r=1;
		while(n>4)
		{
			n-=3;
			r*=3;
		}
		return n*r;
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int t;
		cin>>t;
		cout<<ma(t)<<endl;
	}
}
