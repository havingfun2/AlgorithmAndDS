# include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
		void ins_beg(int x);
		void ins_end(int x);
		void ins_pos(int x, int pos);
		void del_beg();
		void del_end();
		void del_pos(int pos);
		void traverse();
};
node *root=NULL;
int main()
{
	node n;
	int x,y,p;
	do
	{
		cout<<"\n1. INSERT AT BEGINNING\n";
		cout<<"\n2. INSERT AT END\n";
		cout<<"\n3. INSERT AT POSITION\n";
		cout<<"\n4. DELETE AT BEGINNING\n";
		cout<<"\n5. DELETE AT END\n";
		cout<<"\n6. DELETE AT POSITION\n";
		cout<<"\n7. TRAVERSE\n";
		cout<<"\n8. EXIT\n";
		cin>>x;
		switch(x)
		{
			case 1:
				cin>>y;
				n.ins_beg(y);
				break;
			case 2:
				cin>>y;
				n.ins_end(y);
				break;
			case 3:
				cin>>y>>p;
				n.ins_pos(y,p);
				break;
			case 4:
				n.del_beg();
				break;
			case 5:
				n.del_end();
				break;
			case 6:
				cin>>p;
				n.del_pos(p);
				break;
			case 7:
				n.traverse();
				break;
			case 8:
				break;
			default: 
				cout<<"\n Enter Correct Choice\n";
				break;
		}
	}while(x!=8);
	return 0;
}
