#include<cstdio>
# include<cstring>
#include<algorithm>
using namespace std;
char x[50010],y[50010];
int a[2][50010];
int main()
{
    scanf("%s%s",x,y);
    int m = strlen(x),i,j;
    int n=strlen(y);
    for(i=1;i<=m;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(x[i-1]==y[j-1])
    			a[1][j]=a[0][j-1]+1;
    		else 
    			a[1][j]=max(a[0][j],a[1][j-1]);
		}
		for(j=0;j<=n;j++)
		a[0][j]=a[1][j];
    }
    printf("%d\n",a[1][n]);
}

