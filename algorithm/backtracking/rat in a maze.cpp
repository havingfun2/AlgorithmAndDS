# include<iostream>
# define n 4
using namespace std;
int q(int x,int y,int a[n][n])
{
	if(x>=0 && x<n && y>=0 && y<n && a[x][y]==1)
	return 1;
	return 0;
}
int solve(int maze[n][n], int x, int y, int a[n][n])
{
	if(x==n-1 && y==n-1)
	{
		a[x][y]=1;
		return 1;
	}
	if(q(x,y,maze)==1)
	{
		a[x][y]=1;
		if(solve(maze,x+1,y,a)==1)
		return 1;
		if(solve(maze,x,y+1,a)==1)
		return 1;
		a[x][y]=0;
		return 0;
	}
	return 0;
}
int main()
{
	int a[n][n],i,j;
	 int maze[n][n]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
	for(i=0;i<n;++i)
	for(j=0;j<n;++j)
	a[i][j]=0;
	if(solve(maze,0,0,a)==0)
	cout<<"solution doesnt exist\n";
	else
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			cout<<a[i][j]<<"\t";
			cout<<endl;	
		}
	}
}
