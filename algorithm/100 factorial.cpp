#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[500], i, j=499, k, rem, n, z;
		for(i=0; i<499; i++)a[i]=0;
		a[i]=1;cin>>n;
		if(n==0)cout<<"1\n";else{
		
		for(i=n; i>1; i--)
		{
			rem=0;
			for(k=499; k>=j; k--)
			{
				z=i*a[k]+rem;
				a[k]=z%10;
				rem=z/10;
			}
			while(rem)
			{
				a[k--]=rem%10;
				rem/=10;
			}
			j=k;
		}
		while(a[j]==0)j++;
		for(i=j; i<500;i++)
		cout<<a[i];cout<<endl;}
		
	}
	return 0;
}


