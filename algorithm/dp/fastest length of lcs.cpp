#include<cstdio>
# include<cstring>
using namespace std;
int r(char *s)
{
	char c;
	int i=0;
	while((c=getchar())!='\n')
	{
		s[i++]=c;
	}
	s[i]='\0';
	return i;
}
int lcs(int m,int n,char * x,char *y,int *a,int *b)
{
	int i,j,*t;
	for(i=1;i<=m;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(x[i-1]==y[j-1])
    			a[j]=b[j-1]+1;
    		else 
    			a[j]=a[j-1]>b[j]?a[j-1]:b[j];
		}
		t=a;
		a=b;
		b=t;
    }
    return a[n];
}
int main()
{
	
	char x[50010],y[50010];
	int a[50010],b[50010],z;
    int m = r(x),i,j;
    int n=r(y);
    z=lcs(m,n,x,y,a,b);
    printf("%d\n",z);
}

