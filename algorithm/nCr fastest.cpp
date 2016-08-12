#include <iostream>
using namespace std;
# define m 1000000007
long long dp[350][350];
long long q(long long n,long long r)
{
	long long &j=dp[n][r];
	if(j!=-1) ;
	else if(n==r) j=1;
	else if(n<r) j=0;
	else if(r==1) j=n%m;
	else if(!r) j=1;
	else (j=q(n-1,r)+q(n-1,r-1))%m;
	return j%m;
}
int main() {
	// your code goes here
	int i,j;
	for(i=0;i<350;i++)
	for(j=0;j<350;j++)
	dp[i][j]=-1;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++)
		cout<<q(i,j)<<" ";
		cout<<endl;
	}
}
