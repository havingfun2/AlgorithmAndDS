# include<iostream>
using namespace std;
# include<cstdio>
int main()
{int t;
cin>>t;
while(t--)
{

	int a[100][100],n,edg,i,j,o,des,type;
	cout<<"\n 1 for undirected \n 2 for directed \n";
	cin>>type;
	printf("Vertices\n");
	cin>>n;
	if(type==1)
	edg=n*(n-1)/2;
	else
	edg=n*(n-1);
	for(i=1;i<=edg;i++)
	{
		printf("Enter edge %d(-1 -1 to quit) : ",i);
		cin>>o>>des;
		if(o==-1&&des==-1)
		break;
		if(o>=n||des>=n||o<0||des<0)
		printf("Not Valid\n");
		else
		{
			a[o][des]=1;
			if(type==1)
			a[des][0]=1;
		}
	}
	for(i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	cout<<a[i][j]<<"\t";
	cout<<endl;
}
}}
