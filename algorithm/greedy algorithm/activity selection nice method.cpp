# include<cstdio>
# include<algorithm>
using namespace std;
pair<int,int> a[1000000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int t,n,i,count=0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		scanf("%d %d",&a[i].second,&a[i].first);
		sort(a,a+n);
		int last=-1;
		for(i=0;i<n;++i)
			if(a[i].second>=last)
			{
				count++;
				last=a[i].first;
			}
		 printf("%d\n",count);
	}
}
