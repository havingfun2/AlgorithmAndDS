#include <cstdio>
#include <algorithm>
#include <cstring>
# include<iostream>
using namespace std;
# define mx 1<<21
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

	string s;
	int N, gap;
	int sa[mx], pos[mx], tmp[mx], lcp[mx];

	bool comp(int i, int j)
	{
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}

	void bld_suff_arr()
	{
		
	//	N = s.size();
		REP(i, N) sa[i] = i, pos[i] = s[i];
		gap=1;
		while(1)
		{
			sort(sa, sa + N, comp);
			REP(i, N - 1) tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
			REP(i, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
			gap*=2;
		}
	}

	void long_com_pref()
	{
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
			++k;
			lcp[pos[i]] = k;
			if (k)--k;
		}
	}
	
	int main()
	{
		int t;
		cin>>t;
		while(t--){
			cin>>N;
		cin>>s;
		bld_suff_arr();
		long_com_pref();
		
		REP(i, N) cout<<sa[i]+1<<" ";
		cout<<endl;
		REP(i, N) cout<<lcp[i]+1<<" ";
		cout<<endl;
	
	}
