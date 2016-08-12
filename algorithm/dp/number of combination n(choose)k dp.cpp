long long dp[70][70];
long long q(long long n,long long r)
{
	long long &j=dp[n][r];
	if(j!=-1) ;
	else if(n==r) j=1;
	else if(n<r) j=0;
	else if(r==1) j=n;
	else if(!r) j=1;
	else j=q(n-1,r)+q(n-1,r-1);
	return j;
}
