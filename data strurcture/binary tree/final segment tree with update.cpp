//http://www.spoj.com/problems/COURAGE/
#include<bits/stdc++.h>
using namespace std;
long long  a[1000000];
#define ll long long
class segtree{
	public:
	ll mn, sum;
	void merge(segtree l, segtree r){
		mn=min(l.mn, r.mn);
		sum=l.sum+r.sum;
	}
	void assignleaf(ll n){
		this->mn=n;
		this->sum=n;
	}
}node[1000001];

void construct_tree(int cur, int lo, int hi){
	if(lo==hi){
		node[cur].assignleaf(a[lo]);
	}
	else{
		int left=2*cur;
		int right= 2*cur+1;
		int mid=(lo+hi)/2;
		construct_tree(left, lo, mid);
		construct_tree(right, mid+1, hi);
		node[cur].merge(node[2*cur], node[2*cur+1]);
	}
}

segtree get_sum(int cur, int left, int right, int lo, int hi){
	int mid=(left+right)/2;
	if(lo==left&&hi==right)return node[cur];
	if(mid>=hi){
		//left tree
		return get_sum(2*cur,left, mid, lo, hi);
	}
	else if(lo>mid){
		//right tree
		return get_sum(2*cur+1, mid+1, right, lo, hi);
	}
	segtree l, r, c;
	l=get_sum(2*cur, left, mid, lo, mid);
	r=get_sum(2*cur+1,mid+1, right, mid+1, hi);
	c.merge(l, r);
	return c;
}
void update(int cur, int index, ll val, int left, int right){
	if(left==right){
		node[cur].assignleaf(val);
		return;
	}
	int mid=(left+right)/2;
	if(index>mid){
		update(2*cur+1, index, val, mid+1, right);
	}
	else{
		update(2*cur, index, val, left, mid);
	}
	node[cur].merge(node[cur*2], node[2*cur+1]);
}
int main(){
	ll i, j, sum, l, r, n, m;
	cin>>n;
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	cin>>m;
	string s;
	construct_tree(1,0,n-1);
	for(i=0; i<m; i++){
		cin>>s>>l>>r;
		if(s[0]=='C'){
			segtree st=get_sum(1,0,n-1,l,r);
			cout<<st.sum-st.mn<<endl;
		}
		else if(s[0]=='G'){
			a[r]+=l;
			update(1,r,a[r],0,n-1);
			
		}
		else{
			a[r]-=l;
			update(1,r,a[r],0,n-1);
			
		}
	}
	return 0;
	
}
