# include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],i,ans=1,sum=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(i=0;i<n-1;i++)
	ans=ans<<1;
	cout<<ans*sum<<endl;
}