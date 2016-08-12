//for descending use upper_bound instead of lower_bound
#include <iostream>
# include<algorithm>
# include<vector>
using namespace std;
int main() {
    vector<int> d;
int ans, n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        vector<int>::iterator it = lower_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    cout<<d.size()<<endl;
    return 0;
}



//OROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROROR
/*


#include<iostream>
#include<set>
#include<vector>
using namespace std;
 
int LIS(int a[],int n)
{
    int i;
    set<int> s;
    set<int>::iterator k;
    for (i=0;i<n;i++)
    {
        if (s.insert(a[i]).second)
        {
           k = s.find(a[i]);
           k++;
           if (k!=s.end())
              s.erase(k);
        }
    }
    return s.size();
}
int main()
{
	int n;
	cin>>n;
	int i,a[n];
	for(i=0;i<n;i++) cin>>a[i];
	cout<<LIS(a,n);
}


*/

