# include<iostream>
# include<conio.h>
# include<stdlib.h>
using namespace std;
void insert(int x);
void traverse();
void rev();
struct node
{
	int data;
	struct node *next;
};
struct node *root=NULL;
int main()
{
	int x,n=0;
	do{
		system("cls");
		cout<<"\n        ----------------LINK LIST------------------\n";
		cout<<"\n                    1. Insert at beginning \n";
		cout<<"\n                    2. Traverse\n";
		cout<<"\n                    3. Exit\n\n\n";
		cout<<"\n                    4. REVERSE\n\n\n";
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"\nEnter the number to be inserted : ";
				cin>>n;
				system("cls");
				insert(n);
				break;
			case 2:
				system("cls");
				traverse();
				break;
			case 3:
				break;
			case 4:
				system("cls");
				rev();
				break;
		}
	}
	while(x!=3);
	return 0;
}
void insert(int x)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=root;
	root=p;
}
void traverse()
{
	
	if(root==NULL)
	{
		cout<<"\n\nLINKTED LIST EMPTY\n";
		getch();
		return;
	}
	struct node *p=root;
	cout<<"The LINKED LIST is : \n";
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
	getch();
}
void rev()
{
	int n=0;
	struct node *prev,*temp=root,*curr=NULL;
	while(temp!=NULL)
	{
		prev=temp->next;
		temp->next=curr;
		curr=temp;
		temp=prev;
	}
	root=curr;
	cout<<"THE LINKED LIST REVERSED\n";
	getch();
}
