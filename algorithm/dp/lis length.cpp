#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int i,a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	int l[n],j;
	for(i=0;i<n;i++)
	l[i]=1;
	for(i=0;i<n;i++)
	for(j=0;j<i;j++)
	if(a[i]>a[j])
	l[i]=max(l[j]+1,l[i]);
	cout<<l[n-1]<<endl;
	return 0;
}
