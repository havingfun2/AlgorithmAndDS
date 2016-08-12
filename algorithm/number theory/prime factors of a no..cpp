# include<stdio.h>
# include<iostream>
using namespace std;
# include<math.h>
# include<string.h>
# include<stdlib.h>
# include<algorithm>
# include<conio.h>
void prime(int x)
{
	int c,i;
	c=x;
	while(c%2==0)
	{
		c=c/2;
		cout<<2<<"\t";
		
		
	}
	i=3;
//	while(i<=sqrt(c))
		while(i*i<=c)               //better compared to above as square root of impearfect sq is not accurate

	{if(c%i==0)
	{
		cout<<i<<"\t";
		c=c/i;
	}
		else
		i+=2;
	}
	if(c>1)
	cout<<c;
	
}
int main()
{
	int a;
	cin>>a;
	prime(a);
	return 0;
}

