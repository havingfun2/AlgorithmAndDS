#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int i,a[n];
	for(i=0;i<n;i++)cin>>a[i];
	std::deque<int> dq;
	for(i=0;i<k;i++){
	    while(!dq.empty()&&a[i]>=a[dq.back()]) dq.pop_back();
	    dq.push_back(i);
	}
	for(;i<n;i++){
	    cout<<a[dq.front()]<<endl;
	    while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
	    while(!dq.empty()&&a[i]>=a[dq.back()]) dq.pop_back();
	    dq.push_back(i);
	}
	cout<<a[dq.front()]<<endl;
	return 0;
}

