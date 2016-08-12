# include<iostream>
using namespace std;
# include<cstring>
void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void permute(char *s,int a,int b)
{
	int j;
	if(a==b)
	cout<<s<<endl;
	else
	{
		for(j=a;j<=b;++j)
		{
			swap(s+a,s+j);
			permute(s,a+1,b);
			swap(s+a,s+j);
		}
	}
}
int main()
{
	char s[100];
	int i=0,count=0;
	cin>>s;
	while(s[i]!='\0')
	{
		count++;
		i++;
	}
	permute(s,0,count-1);
	return 0;
}
