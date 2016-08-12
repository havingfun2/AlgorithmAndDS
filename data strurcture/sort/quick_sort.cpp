# include<iostream>
using namespace std;
void quick_sort(int a[],int lower, int upper);
int split(int a[],int lower,int upper);
void quick_sort(int a[],int lower, int upper)
{
	int s;
	if(upper>=lower)
	{
		s=split(a,lower,upper);
		quick_sort(a,lower,s-1);
		quick_sort(a,s+1,upper);
	}
}
int split(int a[],int lower,int upper)
{
	int pivot,p,q,temp;
	pivot=a[lower];
	p=lower+1;
	q=upper;
	while(q>=p)
	{
		while(a[p]<=pivot)
		p++;
		while(a[q]>pivot)
		q--;
		if(q>p)
		{
			temp=a[p];
			a[p]=a[q];
			a[q]=temp;
		}
	
	}
	temp=a[q];
	a[q]=a[lower];
	a[lower]=temp;
	return q;
}
int main()
{
	int a[100],i,n;
	cin>>n;
	for(i=0;i<n;++i)
	cin>>a[i];
	quick_sort(a,0,n-1);
	for(i=0;i<n;++i)
	cout<<a[i]<<endl;
	return 0;
}
