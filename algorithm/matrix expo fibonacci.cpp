# include<iostream>
using namespace std;
long long m=1000000007;
long long fib(int n)
{
	int i,j,k;
	long long fib[2][2]={{1,1},{1,0}}, ans[2][2]={{1,0},{0,1}}, temp[2][2]={{0,0},{0,0}};
	while(n)
	{
		if(n%2)
		{
			for(i=0;i<2;++i)
				for(j=0;j<2;++j)
					temp[i][j]=0;
			for(i=0;i<2;++i)
				for(j=0;j<2;++j)
					for(k=0;k<2;++k)
						temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%m;
			for(i=0;i<2;++i)
				for(j=0;j<2;++j)
					ans[i][j]=temp[i][j];
		}
			for(i=0;i<2;++i)
				for(j=0;j<2;++j)
					temp[i][j]=0;
			for(i=0;i<2;++i)
				for(j=0;j<2;++j)
					for(k=0;k<2;++k)
						temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%m;
			for(i=0;i<2;++i)
				for(j=0;j<2;++j)
					fib[i][j]=temp[i][j];
			n/=2;
			cout<<"fib[i][j]------>\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				cout<<fib[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl<<endl;
			cout<<"ans[i][j]------>\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				cout<<ans[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl<<endl;
	}
	return (ans[0][1])%m;
}
int main()
{
	cout<<"no. of test cases : ";
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout<<"answer----->"<<fib(n)<<endl<<endl;
	}
}



