# include<iostream>
# include<cstring>
using namespace std;
int main()
{
	string s,base="the lady on the floor yippi :P ;P ;) :)";
	s.assign(base);
	cout<<s<<endl;
	s.assign(base,1,9);
	cout<<s<<endl;
	s.assign("ankit bansal");
	cout<<s<<endl;
	s.assign(10,'*');
	cout<<s<<endl;
	s.assign(base.begin()+16,base.end()-12);
	cout<<s<<endl;
	return 0;
}
