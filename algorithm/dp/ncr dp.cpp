#include <iostream>
using namespace std;
int n , m , nCr[4444][4444] , dp2[2222][2222],i,j;
 
void pre(){
    for(int i=0;i<=4000;i++)
        nCr[i][0] = 1 ;
    for(int i=1;i<=4000;i++)
        for(int j=1;j<=i;j++)
            nCr[i][j] = ( nCr[i-1][j-1] + nCr[i-1][j] );
}
int main() {
	// your code goes here
	pre();
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)cout<<nCr[i][j]<<" ";cout<<endl;
	}
	return 0;
}
