#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main(){
	while(1){
		long long n, i, j, k, a, b, c, ans=0, l2, b2, l1, b1;
		cin>>n;
		vector<pair< pair<int, int>, int> > s;
		if(n==0)break;
		long long box[n][3], dp[1001]={}, temp;
		for(i=0; i<n; i++){
			for(j=0; j<3; j++){
				cin>>box[i][j];
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<3; j++){
				a=box[i][j];
				b=box[i][(j+1)%3];
				c=box[i][(j+2)%3];
				if(a>b){
					temp=a;
					a=b;
					b=temp;
				}
				s.pb(mp(mp(a, b), c));
			}
		}
		sort(s.begin(), s.end());
		dp[0]=s[0].second;
		for(i=1; i<3*n; i++){
			l2=s[i].first.first;
			b2=s[i].first.second;
			dp[i]=0;
			for(j=i-1; j>=0; j--){
				l1=s[j].first.first;
				b1=s[j].first.second;
				if(l1<l2&&b1<b2){
					dp[i]=max(dp[i], dp[j]);
				}
			}
			dp[i]+=s[i].second;
			ans=max(ans, dp[i]);
		}
		cout<<ans<<endl;
	}
}
