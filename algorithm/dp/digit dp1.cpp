/*Any number is LUCIFER NUMBER  if the Difference between Sum of digits at even location and Sum of digits at odd location is prime number .. For eg... for 20314210 is lucifer number

digits at odd location 0,2,1,0

digits at even location 1,4,3,2

diff = (1+4+3+2)-(0+2+1+0)=10-3  = 7 ..... a prime number.
*/



#include <iostream>
# include<cstdio>
# include<cstring>
using namespace std;
bool m[100][100][100];
long long d[100][100][100];
int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};
bool isPrime(long long x)
{
	if(x<0)
		return 0;
	for(int i=0;i<29;i++)
		if(prms[i]==x)
			return 1;
	return 0;
}
long long F(int j,int od,int ev,int f){
	if(!j)return (long long)(isPrime(ev-od));
	if(m[j][od][ev])return d[j][od][ev];
	m[j][od][ev]=1;
	long long r=0;
	for(int i=0;i<10;i++){
		if(f)
			r+=F(j-1,od,ev+i,1-f);
		else
			r+=F(j-1,od+i,ev,1-f);
	}
	d[j][od][ev]=r;
	return r;
}
long long solve(long long x){
	long long ans=0,ev=0,od=0;
	char b[50];
	sprintf(b,"%lld",x);
	int l=strlen(b),j=l,i,k;
	for(i=0;i<l;i++){
		j--;
		int d=b[i]-'0';
		for(k=0;k<d;k++){
			if((l-i)&1)ans+=(F(j,od+k,ev,1));
			else ans+=(F(j,od,ev+k,0));
		}
		if((l-i)&1)od+=d;
		else ev+=d;
	}
	return ans;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		cout<<solve(b+1)-solve(a)<<endl;
	}
	return 0;
}
