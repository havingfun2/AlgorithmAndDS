// ASSIGNMENT (3) PROBLEM 2: Implement minimum spanning tree by Kruskal algorithm 
//******DONE USING MIN HEAP OR PRIORITY QUEUE METHOD
#include<bits/stdc++.h>
using namespace std;
#define SIZE 10  
#define NULL1 -1    
struct edge              
{
	int u;
	int v;
	int weight;
	struct edge *next;
}*front=NULL;

void create_graph();
void kruskal(struct edge tree[]);
void insert(int ,int ,int );
struct edge *del_min();
int is_empty();
int n;                  
int main()
{
	int i;
	struct edge tr[SIZE];     
	int wt_tr=0;   
	create_graph();    
	kruskal(tr);   
	cout<<"Edges to be included in minimum spanning tree are :\n";
	for(i=1; i<=n-1; i++)
	{
		cout<<tr[i].u<<"->";
		cout<<tr[i].v<<"->";
		wt_tr += tr[i].weight;
	}
	cout<<"Weight of this minimum spanning tree is : "<<wt_tr<<"\n";
return 0;
}

void kruskal(struct edge tr[])
{
	struct edge *tmp;
	int a,b,root1,root2;
	int parent[SIZE];      
	int i,count = 0;      
	for(i=0; i<n; i++)
		parent[i]=NULL1;
	while(!is_empty() && count<n-1) 
	{
		tmp=del_min();
		a=tmp->u;
		b=tmp->v;
		while(a!=NULL1)
		{
			root1=a;
			a=parent[a];
		}
		while(b!=NULL1)
		{
			root2=b;
			b=parent[b];
		}
		if(root1!=root2)                 
 		{
		    count++;
			tr[count].u=tmp->u;
			tr[count].v=tmp->v;
			tr[count].weight=tmp->weight;
			parent[root2]=root1;
		}
	}

}
void insert(int i,int j,int wt)
{
	struct edge *tmp1,*q;

	tmp1 = new edge();
	tmp1->u=i;
	tmp1->v=j;
	tmp1->weight=wt;

	if( front==NULL || tmp1->weight<front->weight )
	{
		tmp1->next=front;
		front=tmp1;
	}
	else
	{
		q=front;
		while( q->next != NULL && q->next->weight <= tmp1->weight )
			q=q->next;
		tmp1->next=q->next;
		q->next=tmp1;
		if(q->next==NULL)	
			tmp1->next=NULL;
	}
}
int is_empty()
{
	if ( front==NULL )
		return 1;
	else
		return 0;
}
struct edge *del_min()
{
	struct edge *tmp;
	tmp=front;
	front=front->next;
	return tmp;
}
void create_graph()
{
	int mxedges,initial,final;

    cout<<"Enter number of vertices : ";
	cin>>n;
	mxedges=n*(n-1)/2;

	for(int i=1;i<=mxedges;i++)
	{
		int wt;
		cout<<"Enter edge "<<i;
		cin>>initial>>final;
		cout<<"Enter weight for this edge : ";
		cin>>wt;
		insert(initial,final,wt); 
	}
}

