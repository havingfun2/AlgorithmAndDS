/*
“add P F” – this means that “F” no. of fans came to the office at Position “P”

“find A B” – this means that Trey and Matt wants to know the sum of fans present at offices at positions “A” to “B”*/
#include <bits/stdc++.h>
using namespace std;
long long tree[1000009],n;
long long read(long long idx){
	long long sum=0;
	while(idx>0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void update(long long idx,long long val){
	while(idx<=n){
		tree[idx]+=val;
		idx += (idx & -idx);
	}	
}
int main() {
		long long u,i,l,r,val,q,x;
		char s[10];
		scanf("%lld%lld",&n,&u);
		memset(tree,0,sizeof tree);
		while(u--){
			scanf("%s",s);
			if(s[0]=='f'){
				scanf("%lld%lld",&l,&r);
				printf("%lld\n",read(r)-read(l-1));
			}
			else{
				scanf("%lld%lld",&l,&r);
				update(l,r);
			}
		}
	return 0;
}
