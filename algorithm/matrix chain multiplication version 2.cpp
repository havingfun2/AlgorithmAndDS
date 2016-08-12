#include <iostream>
using namespace std;
# include<vector>
# include<limits.h>
vector<char>sg;
vector<int>num;
int mn[1005][1005],mx[1005][1005]; 
string s;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		s.clear();
		sg.clear();
		num.clear();
		cin>>s;
		int i,l=s.size(),j,k,m,min1,max1;
		for(i=0;i<l;i++)
		{
			if(i%2)
			sg.push_back(s[i]);
			else
			num.push_back(s[i]-48);
		}
		for(i=0;i<=num.size();i++)
		for(j=0;j<=num.size();j++)
		{
			mn[i][j]=INT_MAX;
			mx[i][j]=0;
		}
		for(i=0;i<num.size();i++)
			mx[i][i]=mn[i][i]=num[i];
		for(m=2;m<num.size()+1;m++)
		{
			for(i=0;i<num.size()-m+1;i++)
			{
				j=i+m-1;
				for(k=i;k<j;k++)
				{
					min1=max1=0;
					if(sg[k]=='+')
					{
						min1=mn[i][k]+mn[k+1][j];
						max1=mx[i][k]+mx[k+1][j];
					}
					else
					{
						min1=mn[i][k]*mn[k+1][j];
						max1=mx[i][k]*mx[k+1][j];
					}
					if(min1<mn[i][j])
					mn[i][j]=min1;
					if(max1>mx[i][j])
					mx[i][j]=max1;
				}
			}
		}
		cout<<mx[0][num.size()-1]<<" "<<mn[0][num.size()-1]<<endl;
	}
	return 0;
}

