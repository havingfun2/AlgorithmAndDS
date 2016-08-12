//1based index conversion
/*After each update, you add the 'val' to all elements from index l to r. After 'u' updates are over, 
there will be q queries each containing an index for which you have to print the element at that index.*/
#include <bits/stdc++.h>
using namespace std;
long long tree[1000009],n;

/*inline void fps (long long *a)
{
    char c = 0;
    while(c<33)
    c = fgetc(stdin);
    *a = 0;
    while(c>33)
    {
               *a = *a*10 + c - '0';
               c = fgetc(stdin);
    }
}*/
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
	// your code goes here
	long long t;
	scanf("%lld",&t);
	while(t--){
		long long u,i,l,r,val,q,x;
		scanf("%lld%lld",&n,&u);
		memset(tree,0,sizeof tree);
		while(u--){
			scanf("%lld%lld%lld",&l,&r),&val;
			l++;
			r++;
			update(l,val);
			update(r+1,-val);
		}
		scanf("%lld",&q);
		while(q--){
			scanf("%lld",&x);
			x++;
			cout<<read(x)<<endl;
		}
	}
	return 0;
}
