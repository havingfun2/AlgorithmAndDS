# include<iostream>
# include<string.h>
using namespace std;
int main()
{
	int n=10;
	while(n--)
	{
		char t[101],m[101];
		int k[200];
		cin>>t>>m;
		int l1, l2, a, j=199, l=1, sum=0, o, b, y, i, rem=0, z=0;
		l1=strlen(t);
		l2=strlen(m);
		i=l2-1;
		o=l1-1;
		while(i>=0)
		{
			a=t[o]-'0';
			b=m[i]-'0';
			y=a+b+sum;
			if(y>9)
			{
				k[j--]=y%10;
				sum=y/10;
			}
			else
			{
				k[j--]=y;
				sum=0;
			}
			o--;i--;
		}
		while(o>=0)
		{
			a=t[o]-'0';
			y=a+sum;
			if(y>9)
			{
				k[j--]=y%10;
				sum=y/10;
			}
			else
			{
				k[j--]=y;
				sum=0;
			}
			o--;
		}
		if(sum!=0)
		k[j]=sum;
		else
		j++;
		if(k[j]==1)
		{
			rem=1;
			j++;
		}
		if(k[199]%2==1)z=1;
		for(i=j;i<200;i++)
		{
			if(k[i]%2==0)
			{
				k[i]=(rem*10+k[i])/2;
				rem=0;
			}
			else
			{
				k[i]=(rem*10+k[i])/2;
				rem=1;
			}
		}
		for(i=j;i<200;i++)
		cout<<k[i];
		cout<<endl;
		
	}
	return 0;
}
