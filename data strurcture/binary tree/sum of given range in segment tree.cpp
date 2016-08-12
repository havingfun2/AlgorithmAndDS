# include<iostream>
# include<cmath>
# include<cstdio>
using namespace std;
int g_sum(int a[],int beg,int end,int x,int y,int i)
{
	if(x<=beg&&y>=end)
	return a[i];
	if(end<x||beg>y)
	return 0;
	int mid=(end+beg)/2;
	return g_sum(a,beg,mid,x,y,2*i+1)+g_sum(a,mid+1,end,x,y,2*i+2);
}
int gsum(int a[],int n,int x,int y)
{
	if(x<0||y>n-1||x>y)
	{
		cout<<"INVALID INPUT";
		return -1;
	}
	else
		return g_sum(a,0,n-1,x,y,0);
		
}	
int cons(int a[],int beg,int end,int *s,int i)
{
	if(beg==end)
	{
		s[i]=a[beg];
		return a[beg];
	}
	else
	{
		int mid=(end+beg)/2;
		s[i]=cons(a,beg,mid,s,2*i+1)+cons(a,mid+1,end,s,2*i+2);
		return s[i];
	}
}
int *cons_tree(int a[],int n)
{
	int x=(int)ceil(log2(n)),msize=2*(int)pow(2,x)-1;
	
	int *s = new int[msize];
	cons(a,0,n-1,s,0);
	 
	return s;
}
int main()
{
	int n,x,y;
	cout<<"TOTAL NO> OF ELEMENTS\n";
	cin>>n;
	int a[n],i;
	cout<<"ARRAY ELEMENTS\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	int *tree=cons_tree(a,n);
	cout<<"Enter the range to do sum (x<y)";
	cin>>x>>y;
	cout<<"SUM IS :"<<gsum(tree,n,x,y);
    return 0;
	
}
