# include<iostream>
# include<cstdio>
# include<cstdlib>
using namespace std;
int c=0;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;
struct node *insert(int x, struct node *p);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
int main()
{
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
				root=insert(y,root);
				cout<<"\nElement Inserted";
				break;
			case '2':
				preorder(root);
				break;
			case '3':
				inorder(root);
				break;
			case '4':
				postorder(root);
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
struct node *insert(int x, struct node* p)
{
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
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
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<endl;
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<endl;
	}
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<endl;
		inorder(p->right);
	}
}
