# include<iostream>
# include<algorithm>
# include<cmath>
# define maxo 1000000000
using namespace std;
long long g_sum(long long a[],long long beg,long long end,long long x,long long y,long long i)
{
	if(x<=beg&&y>=end)
	return a[i];
	if(end<x||beg>y)
 return -99999999999999;
	long long mid=(beg+end)/2;
	return max(g_sum(a,beg,mid,x,y,2*i+1),g_sum(a,mid+1,end,x,y,2*i+2));
}
long long gsum(long long a[],long long n,long long x,long long y)
{
	return g_sum(a,0,n-1,x,y,0);
}
long long cons(long long a[],long long beg,long long end,long long *s,long long i)
{
	if(beg==end)
	{
		s[i]=a[beg];
		return a[beg];
	}
	else
	{
		long long mid=(beg+end)/2;
		s[i]= max(cons(a,beg,mid,s,2*i+1),cons(a,mid+1,end,s,2*i+2));
		return s[i];
	}
}
long long *cons_tree(long long a[],long long n)
{
	long long x=(long long)ceil(log2(n)),msize=2*(long long)pow(2,x)-1;
	long long *s=new long long[msize];

	cons(a,0,n-1,s,0);
	return s;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	
	long long n,x,y;
	cin>>n;
	long long a[n],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	long long *tree=cons_tree(a,n);
	long long q;
	cin>>q;
	while(q--){
	cin>>x>>y;
	x--;
	y--;
	if(x>y)
	{
		long long t=x;
		x=y;
		y=t;
	}
	printf("%d\n",gsum(tree,n,x,y));}
}
    return 0;
}
