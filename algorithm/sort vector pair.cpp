#include<bits/stdc++.h>
using namespace std;
#define ll long long
//vector<int> v, u;
	vector< pair<int, int> >v;
bool fnc(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first)return (a.second<b.second);
    return (a.first<b.first);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,y,i;
		cin>>n;
		for(i=0;i<n;i++){
		    cin>>x>>y;
		    v.push_back(make_pair(x,y));
		}
		sort(v.begin(),v.end(),fnc);
		for(i=0;i<n;i++)cout<<v[i].first<<" "<<v[i].second<<endl;
		
		v.clear();
	}
} 
