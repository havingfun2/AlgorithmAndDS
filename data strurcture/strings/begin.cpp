#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
  string str ("adjbkdacb");
  for(string::iterator i=str.begin();i!=str.end();++i)
	cout<<*i;
  return 0;
}
