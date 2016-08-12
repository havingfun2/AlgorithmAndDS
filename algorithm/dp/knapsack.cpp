# include<cstdio>
# include<algorithm>
using namespace std;
int a[2000005]={0};
int main()
{
	int c,n,i,j;
	scanf("%d%d",&c,&n);
	int v[n],w[n];
	for(i=1;i<=n;i++)
	scanf("%d%d",&w[i],&v[i]);
	for(i=1;i<=n;i++)
	for(j=c;j>=w[i];j--)
	a[j]=max(a[j],a[j-w[i]]+v[i]);
	printf("%d",a[c]);
}
