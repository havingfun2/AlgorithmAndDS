// Gauss’ algorithm for solving n linear equations with n unknowns.
# include<iostream>
using namespace std;
int n;
double a[10][11];
void forwardSubstitution() {
    int i, j, k, max;
    float t;
    for (i = 0; i < n; ++i) {
        max = i;
        for (j = i + 1; j < n; ++j)
            if (a[j][i] > a[max][i])
                max = j;
         
        for (j = 0; j < n + 1; ++j) {
            t = a[max][j];
            a[max][j] = a[i][j];
            a[i][j] = t;
        }
         
        for (j = n; j >= i; --j)
            for (k = i + 1; k < n; ++k)
                a[k][j] -= a[k][i]/a[i][i] * a[i][j];
 
    }
}
 
void reverseElimination() {
    int i, j;
    for (i = n - 1; i >= 0; --i) {
        a[i][n] = a[i][n] / a[i][i];
        a[i][i] = 1;
        for (j = i - 1; j >= 0; --j) {
            a[j][n] -= a[j][i] * a[i][n];
            a[j][i] = 0;
        }
    }
}
void gauss() {
    int i, j;
 
    forwardSubstitution();
    reverseElimination();
     
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n + 1; ++j)
            cout<<a[i][j]<<" ";
        printf("\n");
    }
}
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			cin>>a[i][j];
		}
	}
	gauss();
}
