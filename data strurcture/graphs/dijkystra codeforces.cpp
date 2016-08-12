#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<iostream>
#include<algorithm>
#include<cstring>
# include<list>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include <ctime>
#include <functional>
#include <iomanip>
#include<sstream>
#define gc getchar//_unlocked

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n) 					scanf("%c",&n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(long long i=a;i<b;i++)
#define RFOR(i,init,n)          for(long long i=n;i>=init;i--)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define AREA(x1,y1,x2,y2,x3,y3) abS(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(a)                  (a)*(a)
#define DIST(x1,y1,x2,y2)       (sqr(x1-x2) + sqr(y1-y2) )
#define SP                      system("pause");

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<float> VF;
typedef pair<int,VF> PIVF;
typedef pair<int,VI> PIVI;
typedef vector<PIVF> VIPIVF;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;
typedef vector<string> VS;
typedef pair< PII, pair< string, VII > > POS;
typedef priority_queue<int> PQI;
typedef priority_queue<pair<int,int> > PQII;
typedef priority_queue<pair<int, pair<int,string> > > PQIIS;
typedef long long int int64;

char *opos, OutFile[65536], DIP[20];
FILE *pfile;
inline void InitFASTIO() 
{
    //freopen("c:/input.txt","r",stdin);
    //pfile = fopen("c:/output.txt","a");
    opos = OutFile;
}
inline void FlushFASTIO() 
{   
    //fwrite(OutFile,opos-OutFile,1,pfile);	
    fwrite(OutFile,opos-OutFile,1,stdout);	
}

inline void fps(int &x){register int c = gc();x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}}
inline void fs(int &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 || c>57) && c != '-');c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void fl(long long int &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 || c>57) && c != '-');c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void pi(int x,int flag = 1){int y,dig=0;if(x<0) { *opos++ = '-';  x=-x;};if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}while (dig--){*opos++=DIP[dig];if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}*opos++= flag ? '\n' : ' ';if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}
inline void pll(long long int x,int flag = 1) {long long int y,dig=0;if(x<0) { *opos++ = '-';  x=-x;};if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}while (dig--){ *opos++=DIP[dig];if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}*opos++= flag ? '\n' : ' ';if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}
inline void ps(char * str,int flag = 1) {int len=strlen(str);for(int i=0;i<len;i++){*opos++=str[i];if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}*opos++= flag ? '\n' : ' ';if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}
inline void pws(int flag = 1) {*opos++= flag ? '\n' : ' ';if(opos-OutFile==(sizeof(OutFile)-1)){FlushFASTIO();InitFASTIO();}}

LL gcd(LL x, LL y) {return y == 0 ? x : gcd(y, x % y);}
LL extGcd(LL a, LL b, LL& x, LL& y){if(a==0){x=0;y=1;return(b);}LL a1, b1, c, x1, y1, rst;a1=b%a; b1=a; c=b/a;rst=extGcd(a1, b1, x1, y1);x=y1-c*x1; y=x1;return(rst);}
void sieve(vector<int>& prime,int size){prime.resize(size+1);prime[0]=1;prime[1]=1;for(long long i=2;i<=size;i++){if(!prime[i]){prime[i]=i;for(long long j=i;j*i<=size;j++){if(!prime[j*i])prime[j*i]=i;}}}}
void primColl(vector<int>& primes,int size){vector<int> prime(size);prime[0]=1;prime[1]=1;for(long long i=2;i<=size;i++){if(!prime[i]){prime[i]=i;primes.pb(i);for(long long j=i;j*i<=size;j++){if(!prime[j*i])prime[j*i]=i;}}}}
void fastSieve(vector<int>& primes,LL size){vector<bool> b((size>>1)+100);for(LL i=3;i<=LL(sqrt(size));i+=2)if(!b[(i-3)>>1])for(LL j=i*i;j<size;j+=i)if(j&1)b[(j-3)>>1]=1;primes.pb(2);for(LL i=0;2*i<size;i++)if(!b[i] && i<((size/2)-1))primes.pb(2*i+3);}
int toInt(char xx){return xx - '0';}
char toChar(int xx) {return xx + '0';}
bool isDigit(char xx) {return ('0' <= xx && xx <= '9');}
bool isCharacter(char xx) {return (('a' <= xx && xx <= 'z') || ('A' <= xx && xx <= 'Z'));}
bool isUpper(char xx){return ('A' <= xx && xx <= 'Z');}
bool isLower(char xx){return ('a' <= xx && xx <= 'z');}
bool isPalin(string x) {int len = x.length();REP(i,len/2) {if (x[i] != x[len - 1 - i])return false;}return true;}
void swapInt(int &x, int &y) {x = x ^ y;y = x ^ y;x = x ^ y;}
string tolowerStr(string x){string ret = "";REP(i,x.length()) {ret.pb(tolower(x[i]));}return ret;}
string toupperStr(string x) {string ret = "";REP(i,x.length()) {ret.pb(toupper(x[i]));}return ret;}
void toCharArray(char * dest,string source){strcpy(dest,source.c_str());}
void split(vector<string>&s,string g,char c){REP(i,g.length())if(g[i]==c)g[i] = ' ';stringstream in(g);for(string t;in>>t;)s.pb(t);}

#define MAXN 10001
LL d[1000000];//Distance function

list<pair<int,int> > *graph;

void dijkstra(int root) {

set<pair<int,int> > pq;
/* A set helps insertion and extraction operations in logarithmic time. This set maintains (distance,vertex number) pair sorted on basis of distance*/

set<pair<int,int> > ::iterator it;

int u,v,wt;

list<pair<int,int> > :: iterator i;




d[root]=0;

pq.insert(pair<int,int>(0,root));

while(pq.size()!=0)
{
    it=pq.begin();

    u=it->second;

    pq.erase(it);

    for(i=graph[u].begin(); i!=graph[u].end(); i++)
    {
        v=i->first;
        wt=i->second;
        //Relax u-v edge with weight wt below:
        if(d[v]>d[u]+wt)
        {
            if(d[v]!=1e8)
            {
                pq.erase(pq.find(pair<int,int>(d[v],v)));
            }
            d[v]=d[u]+wt;
            pq.insert(pair<int,int>(d[v],v));
        }
//Relax ends

}

}
}

void addedge(int src,int des,int wt) { pair<int,int> x;

x.first=des;
x.second=wt;

graph[src].push_front(x);
//here we are consering directed graph so. /* include in case of undirected graph

x.first=src;

x.second=wt;

graph[des].push_front(x);
//This algorithm works in same way for undirected graph }

}
int main() {

int i;

int t;

cin>>t;

while(t--){

int v,e,src,des,wt;

cin>>v>>e;

//Initialise all d[v] to a large number
for(i=0; i<=v; i++)
{
    d[i]=1e8;
/*Do not use INF because mathematical operations performed on it will cause overflow
in some cases you may need higher values like 1e18 etc. as per constraints
*/

}

graph=new list<pair<int,int> >[v+1];

for(i=0; i<e; i++)
{
    cin>>src>>des>>wt;
    addedge(src,des,wt);
}
int x,y;

cin>>x>>y;

dijkstra(x);

if(d[y]!=1e8)
cout<<d[y]<<endl;
else
    cout<<"NO"<<endl;
}
return 0;
}
