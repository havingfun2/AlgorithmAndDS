# include<iostream>
# include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,a[n],sum=0,j,max1=0;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=i;j<n;j++)
		{
			sum+=a[j];
			max1=max(sum,max1);
			/*FOR TAKING OUT THE INDEX BTW WHICH NO. ARE THERE
					IF(SUM>=MAX)
					{
						MAX=SUM;
						START=I;
						END = J;
				}
			*/
		}
	}
	cout<<max1<<endl;
}
