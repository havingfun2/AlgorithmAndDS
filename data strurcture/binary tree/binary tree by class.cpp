# include<iostream>
using namespace std;
class node
{
	int data;
	node *left;
	node *right;
	public:
		node *insert(int x, node *p);
		void preorder(node *p);
		void postorder(node *p);
		void inorder(node *p);
};
node *root=NULL;
int c=0;
node *node :: insert(int x,node *p)
{
	if(p==NULL)
	{
		node *p =new node;
		p->data=x;
		p->left=NULL;
		p->right=NULL;
		c++;
	}
	else
	{
		if(c%2==0)
		p->right=insert(x,p->right);
		else
		p->left=insert(x,p->left);
	}
	return p;
}
void node :: preorder(node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<endl;
		preorder(p->left);
		preorder(p->right);
	}
}
void node :: postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<endl;
	}
}
void node :: inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<endl;
		inorder(p->right);
	}
}
int main()
{
	node z;
	int y;
	char ch;
	do
	{
		cout<<"\n1. Insert\n";
		cout<<"\n2. Preorder Traversal\n";
		cout<<"\n3. Inorder Traversal\n";
		cout<<"\n4. Postorder Traversal\n";
		cout<<"\n5. Exit\n";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cin>>y;
				root=z.insert(y,root);
				cout<<"\nElement Inserted";
				break;
			case '2':
				z.preorder(root);
				break;
			case '3':
				z.inorder(root);
				break;
			case '4':
				z.postorder(root);
				break;
			case '5':
				break;
			default :
				cout<<"\nEnter Correct Choice";
				break;	
		}
	}while(ch!='5');
	return 0;
}
