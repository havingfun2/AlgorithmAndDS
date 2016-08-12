#include <bits/stdc++.h>
using namespace std;
int main() {
 long long n,m,q,ans=1;
    cin>>n>>m;
    q=n^m;
    while(q){
        q>>=1;
        ans<<=1;
    }
    cout<<ans-1<<endl;
	return 0;
}
