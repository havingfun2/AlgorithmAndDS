# include<cstdio>
# define mx 1000000
using namespace std;
	int a[1001][1001]={{0}};
void cat()
{

	for(int i=0;i<1001;++i)
	{
		for(int j=0;j<=i;++j)
		{
			if(j==0)
			a[i][j]=1;
			else
			a[i][j]=(a[i-1][j]+a[i][j-1])%mx;
		}
	}
}
int main()
{
	cat();
	int t;
	scanf("%d",&t);
	while(t)
	{
			printf("%d\n",a[t][t]);
			scanf("%d",&t);
	}
}
