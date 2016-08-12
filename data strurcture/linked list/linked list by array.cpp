# include<iostream>
# include<algorithm>
using namespace std;
struct node
{
	int data,next;
}l[5];
int main()
{
	int i=0;
	cin>>l[0].data;
	cin>>l[0].next;
	while(l[i].next!=-1)
	{
		i=l[i].next;
		cin>>l[i].data;
		cin>>l[i].next;
	}i=0;
	while(l[i].next!=-1)
	{
		cout<<l[i].data<<endl;
		i=l[i].next;
	
	}
	cout<<l[i].data<<endl;
}
