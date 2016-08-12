# include<iostream>
#include <cstdio>
using namespace std;

const int MAX = 1000001;
const int LMT = 1000;
int cnt[MAX];

void sieve() {
	int i, j;
	cnt[2] = 1;
	for(i = 4; i < MAX; i+=2) cnt[i]++;
	for(i = 3; i < MAX; i+=2) {
		if(!cnt[i]) {
			cnt[i] = 1;
			for(j = i<<1; j < MAX; j+=i) cnt[j]++;
		}
	}//cout<<cnt[18];
}

int main() {
	int t;
	sieve();
	scanf("%d", &t);
	while(t--) {
	
	}
	return 0;
}
