#include<cstdio>
# include<cstring>
using namespace std;
int a[50010],b[50010];
/*void swap(int *a,int *b)
{
	int *t;
	t=a;
	a=b;
	b=t;
}*/
int main()
{
   char x[50010],y[50010];
	scanf("%s%s",x,y);
    int m = strlen(x),i,j;
    int n=strlen(y);
    for(i=1;i<=m;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(x[i-1]==y[j-1])
    			a[j]=b[j-1]+1;
    		else 
    			a[j]=a[j-1]>b[j]?a[j-1]:b[j];
		}
		for(j=0;j<=n;j++)
		b[j]=a[j];
    }
    printf("%d\n",a[n]);
}

