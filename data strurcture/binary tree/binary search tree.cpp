# include<iostream>
# include<stdlib.h>
# include<cstdio>
using namespace std;
struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
};
struct node *search(struct node *p, int x);
struct node *ins(struct node *p, int x);
//struct node *del(struct node *p ,int x);
struct node *min(struct node *p);
struct node *max(struct node *p);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
int height(struct node *p);
int main()
{
	struct node *root=NULL,*p;
	int c,k;
	do
	{
		cout<<"\n1. Search\n";
		cout<<"\n2. Insert\n";
	//	cout<<"\n3. Delete\n";
		cout<<"\n4. Preorder\n";
		cout<<"\n5. Postorder\n";
		cout<<"\n6. Inorder\n";
		cout<<"\n7. Height\n";
		cout<<"\n8. Minimun\n";
		cout<<"\n9. Maximum\n";
		cout<<"\n10. Exit\n";
		cout<<"\nEnter Yur Choice\n";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"\nElement to Be Searched\n";
				cin>>k;
				search(root,k);
				if(p==NULL)
				cout<<"\nKey Not Present\n";
				else
				cout<<"\nKey Present\n";
				break;
			case 2:
				cout<<"\nKey To Insert\n";
				cin>>k;
				root=ins(root,k);
				break;
		/*	case 3:
				cout<<"\nElement To Delete\n";
				cin>>k;
				root=del(root,k);
				break;*/
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				inorder(root);
				break;
			case 7:
				cout<<"Height of tree : "<<height(root)<<endl;
				break;
			case 8:
				p=min(root);
				if(p!=NULL)
				cout<<"Minimum Key is: "<<p->data<<endl;
				break;
			case 9:
				p=max(root);
				if(p!=NULL)
				cout<<"Maximum Key is: "<<p->data<<endl;
				break;
			case 10:
				break;
			default:
				cout<<"\n Enter Correct Choice\n";
				break;
		}
	}while(c!=10);
}
struct node *search(struct node *p,int x)
{
	if(p==NULL)
	{
		cout<<"\nKey Not Found\n";
		return NULL;
	}
	else if(x<p->data)
	return search(p->lchild,x);
	else if(x>p->data)
	return search(p->rchild,x);
	else 
	return p;
}
struct node *min(struct node *p)
{
	if(p==NULL)
	return NULL;
	else if(p->lchild==NULL)
	return p;
	else
	return min(p->lchild);
}
struct node *max(struct node *p)
{
	if(p==NULL)
	return NULL;
	else if(p->rchild==NULL)
	return p;
	else
	return max(p->rchild);
}
struct node *ins(struct node *p,int x)
{
	if(p==NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=x;
		p->lchild=NULL;
		p->rchild=NULL;
	}
	if(x<p->data)
	p->lchild=ins(p->lchild,x);
	else if(x>p->data)
	p->rchild=ins(p->rchild,x);
	else
	cout<<"\nDuplicate Entry\n";
	return p;
}
/*struct node *del(struct node *p,int x)
{
	struct node *tmp,*s;
	if(p==NULL)
	{
		cout<<"\nKey Not Found\n";
		return p;
	}
	else if(x<p->data)
	p->lchild=del(p->lchild,x);
	else if(x>p->data)
	p->rchild=del(p->rchild,x);
	else
	{
		if(p->lchild!=NULL&&p->rchild!=NULL)
		{
			s=p->rchild;
			while(s->lchild)
			s=s->lchild;
			p->data=s->data;
			p->rchild=del(p->rchild,s->data);
		}
		else
		{
			tmp=p;
			if(p->lchild!=NULL)
			p=p->lchild;
			else if(p->rchild!=NULL)
			p=p->rchild;
			else
			p=NULL;
			free(tmp);
		}
	}
}*/
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<endl;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<endl;
	}
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->lchild);
		cout<<p->data<<endl;
		inorder(p->rchild);
	}
}
int height(struct node *p)
{
	int h_left,h_right;
	if(p==NULL)
	return 0;
	h_left=height(p->lchild);
	h_right=height(p->rchild);
	if(h_left>h_right)
	return 1+h_left;
	else
	return 1+h_right;
}
