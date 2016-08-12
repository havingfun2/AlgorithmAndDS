/*
Consider the below problems statement.

There 100 different types of caps each having a unique id from 1 to 100. Also, there ‘n’ persons each having a collection of variable number of caps. One day all of these persons decide to go in a party wearing a cap but to look unique they decided that none them will wear the same type of cap. So, count the total number of arrangements or ways such that none of them is wearing same type of cap.

Constraints: 1 <= n <= 10 Example:

First line contains value of n, next n lines contain collections 
of all the n persons.
Input: 
3
5 100 1     // Collection of first person.
2           // Collection of second person.
5 100       // Collection of second person.

Output:
4
Explanation: All valid possible ways are (5, 2, 100),  (100, 2, 5),
            (1, 2, 5) and  (1, 2, 100)


*/
# include<bits/stdc++.h>
using namespace std;
# define mo 1000000007
int dp[1025][101];
vector<int> v[101];
long long tot;
long long func(int mask,int i){
	if(mask==tot)return 1;
	if(i>100) return 0;
	if(dp[mask][i]!=-1)return dp[mask][i];
	long long ans=func(mask,i+1);
	for(int j=0;j<v[i].size();j++){
		if(mask&(1<<v[i][j]))continue;
		ans+=func(mask|(1<<v[i][j]),i+1);
		ans%=mo;
	}
	return dp[mask][i]=ans;
}
int main(){
	int n,x,i,j;
	cin>>n;
	string str,temp;
	getline(cin,str);
	for(int i=0;i<n;i++){
		getline(cin,str);
		stringstream ss(str);
		while(ss>>temp){
			stringstream s;
			s<<temp;
			s>>x;
	//		cout<<s<<" "<<ss<<" "<<temp<<" "<<x<<endl;
			v[x].push_back(i);
		}
	}
	for(i=0;i<1025;i++){
		for(j=0;j<101;j++)
		dp[i][j]=-1;
	}
	tot=(1<<n)-1;
	cout<<func(0,1)<<endl;
}
