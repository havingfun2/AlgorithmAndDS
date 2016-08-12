/*INPUT TYPE 
	4 
	1 2 3 4
	
	Here matrix are 1x2 and 2x3 and 3x4


*/ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    while(cin>>n){
        int m[n+10][n+10],a[n],i,j,k,l;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                m[i][j]=0;
        }
        for(l=2;l<n;l++){
            for(i=0;i<n-l;i++){
                j=i+l;
                m[i][j]=m[i][i+1]+m[i+1][j]+a[i]*a[j]*a[i+1];
                for(k=i+1;k<j;k++){
                    if(m[i][j]>m[i][k]+m[k][j]+a[i]*a[k]*a[j]){
                        m[i][j]=m[i][k]+m[k][j]+a[i]*a[k]*a[j];
                    }
                }
            }
        }
        cout<<m[0][n-1]<<endl;
    }
} 
