#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n=4,ans,i,j;
	ans=1<<n;
//	cout<<ans;
for(i=1;i<ans;i++){
	cout<<i<<"    ";
	for(j=0;j<n;j++){
		if(i&(1<<j))cout<<j<<" ";
	}
	cout<<endl;
}
	return 0;
}
