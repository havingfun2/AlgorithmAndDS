#include <iostream>
using namespace std;
# include<vector>
# define mo 1000003
long long pow(long long a,long long b){
	long long ans=1,temp;
	while(b){
		if(b%2)
		ans=(ans*a)%mo;
		a=(a*a)%mo;
		b/=2;
	}
	return ans%mo;
}
long long inveuler(long long n){
	return pow(n,mo-2);
}
long long C(long long n,long long r){
	vector<long long> v(n+1,1);
	for(long long i=2;i<=n;i++)
		v[i]=(v[i-1]*i)%mo;
		return (v[n]*((inveuler(v[r])*inveuler(v[n-r]))%mo))%mo;
}
long long lucas(long long n,long long m){
	if(!n&&!m) return 1;
	long long x=n%mo;
	long long y=m%mo;
	if(y>x) return 0;
	return lucas(n/mo,m/mo)*C(x,y);
}
int main() {
	int t;
	cin>>t;
	while(t--){
		long long n,r,res;
		cin>>n>>r;
		res=lucas(n,r);
		if(res<0)res+=mo;
		cout<<res%mo<<endl;
	}
	return 0;
}
