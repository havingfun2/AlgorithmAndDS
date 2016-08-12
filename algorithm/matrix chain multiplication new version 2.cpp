/*INPUT TYPE 
	3
	1 2
	2 3
	3 4
	
	1 2 is the size of matrix


*/ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    while(cin>>n){
        int m[n+10][n+10],a[n],i,j,k,l,b[n];
        for(i=0;i<n;i++)cin>>a[i]>>b[i];
        for(i=0;i<n;i++){
                m[i][i]=0;
        }
        for(l=1;l<n;l++){
            for(i=0;i<n-l;i++){
                j=i+l;
                m[i][j]=m[i][i]+m[i+1][j]+a[i]*b[j]*b[i];
                for(k=i+1;k<j;k++){
                    if(m[i][j]>m[i][k]+m[k+1][j]+a[i]*b[k]*b[j]){
                        m[i][j]=m[i][k]+m[k+1][j]+a[i]*b[k]*b[j];
                    }
                }
            }
        }
        cout<<m[0][n-1]<<endl;
    }
} 
