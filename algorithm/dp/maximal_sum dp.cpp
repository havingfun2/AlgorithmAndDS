# include<iostream>
# include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	int sum=a[0],pos=0,max_start,max_end,max1=a[0];
	for(i=1;i<n;i++)
	{
		sum=max(sum+a[i],a[i]);
		max1=max(max1,sum);
		/*FOR TAKING OUT THE INDEX BTW WHICH NO. ARE THERE
					IF(S>0)
					S=S+A[I];
					ELSE
					{
						S=A[I];
						POS=I;
					}
					IF(SUM>=MAX)
					{
						MAX=SUM;
						max_start=pos;
						max_end= i;
					}
			*/
	}
	cout<<max1<<endl;
}
