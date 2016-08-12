# include<iostream>
# include<vector>
using namespace std;
int main()
{
	vector<int> vet[10];
	int j,i,n,o,des;
	cout<<"Enter No. Of Edges \n";
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>o>>des;
		vet[o].push_back(des);
	}
	for(i=0;i<n;++i)
	for(j=0;j<vet[i].size();++j)
	{
		o=i;
		des=vet[i][j];
		cout<<o<<"\t"<<des<<"\n";
	}
}
