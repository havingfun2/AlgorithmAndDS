#include <iostream>
#include<algorithm>
using namespace std;
bool wayToSort(int i, int j) { return i > j; }
int main()
{
    long long t,i,a[100001];
    cin>>t;
    while(t--)
    {
    	long long n;
    	cin>>n;
    	for(i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}
    	sort(a,a+n, wayToSort);
    	for(i=0;i<n;i++)
    	cout<<a[i]<<' ';
    	cout<<'\n';
    }
}

