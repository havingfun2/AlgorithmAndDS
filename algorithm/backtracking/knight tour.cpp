# include<iostream>
# define n 8
using namespace std;
int q(int x,int y,int a[n][n])
{
	if(x>=0 && x<n && y>=0 && y<n &&a[x][y]==-1)
	return 1;
	return 0;
}
int solve(int x,int y,int movei,int a[n][n],int xMove[n],int yMove[n])
{
	int i,next_x,next_y;
	if(movei==n*n)
	return 1;
	for(i=0;i<n;++i)
	{
		next_x=x+xMove[i];
		next_y=y+yMove[i];
		if(q(next_x,next_y,a))
		{
			a[next_x][next_y]=movei;
			if(solve(next_x,next_y,movei+1,a,xMove,yMove)==1)
			return 1;
			else
			a[next_x][next_y]=-1;
		}
	}
	return 0;
}
int main()
{
	int a[n][n],i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	a[i][j]=-1;
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    a[0][0]=0;
    if(solve(0,0,1,a,xMove,yMove)==0)
    cout<<"Solution doesnt exist\n";
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
