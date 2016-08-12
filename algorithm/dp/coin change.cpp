#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	int a[m],res[n+1]={0},i,j;
	res[0]=1;
	for(i=0;i<m;i++) cin>>a[i];
	for(i=0;i<m;i++){
		for(j=a[i];j<=n;j++){
			res[j]+=res[j-a[i]];
		}
	}
	cout<<res[n]<<endl;
	return 0;
}
