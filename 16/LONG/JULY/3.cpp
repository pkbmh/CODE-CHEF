  
#include <bits/stdc++.h>
using namespace std;

// i/o
#define SCI(a) scanf("%d", &a)
#define SCLL(a) scanf("%lld", &a)
#define PRI(a) printf("%d\n", a)
#define PRLL(a) printf("%lld\n", a)
#define gc getchar_unlocked
inline void scanint(int &a){
    char c = 0;a = 0;
    while(c<33) c = fgetc(stdin);
    while(c>33){a = a*10 + c - '0';c = fgetc(stdin);}
}

// stl function
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define TR(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define LB(v , a) lower_bound (v.begin(), v.end(), a)
#define UP(v , a) upper_bound (v.begin(), v.end(), a)
#define ALL(a) a.begin() , a.end()
#define RALL(a) a.rbegin(), a.rend()

// data type
#define LLI long long int
#define LLU long long unsigned
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double double>
#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VLLI vector<LLI>
#define VPII vector<PII>
#define PSI pair<string,int>
#define PSS pair<string,string>
#define VS vector<string>
#define VVI vector<vector<int> > 

// Initialization 
#define SET0(a) memset(a , 0 , sizeof(a))
#define COPY(d , s) memcpy(d , s , sizeof(s))
#define SET1(a) memset(a , 1 , sizeof(a))
#define SETN1(a) memset(a , -1 , sizeof(a))

#define FOR(i ,s, e) for(int i = s; i <= e; i++)
#define RFOR(i,s, e) for(int i = s; i >= e; i--)


template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}

const int MAX = 1e4+5;
int a[MAX],b[MAX];
bool vis[MAX];
int n,ans;

void foo(int ind, int val, int cnt) {
  if(ind == n && cnt == n){ans = max(ans,val); return ;}
  if(ind == n) return ;
  int tval;
  if(a[ind] == val || val == -1) {
    tval = a[ind];
    foo(ind+1, tval,cnt);
  }
  if(ind-1 >= 0 && !vis[ind-1] && (a[ind]+b[ind-1] == val || val == -1))  {
    vis[ind-1] = true;
    tval = a[ind]+b[ind-1];
    foo(ind+1,tval,cnt+1);
    vis[ind-1] = false;
  }
  //cout << "ind bf3 " << ind << " "<< vis[ind] << " " << val << endl;
  if(!vis[ind] && (a[ind]+b[ind] == val || val == -1)) {
    //cout << ":::3 "<< ind  << endl;
    vis[ind] = true;
    tval = a[ind]+b[ind];
    foo(ind+1,tval,cnt+1);
    vis[ind] = false;
  }
  if(ind+1 < n && !vis[ind+1] && (a[ind]+b[ind+1] == val|| val == -1)) {
    //cout << "::4"<< ind  << endl;
    vis[ind+1] = true;
    tval = a[ind]+b[ind+1];
    foo(ind+1,tval,cnt+1);
    vis[ind+1] = false;
  }
  if(ind-1>= 0 && !vis[ind] && !vis[ind-1] && (a[ind]+b[ind]+b[ind-1] == val || val == -1)) {
    vis[ind] = vis[ind-1] = true;
    tval = a[ind]+b[ind]+b[ind-1];
    foo(ind+1,tval,cnt+2);
    vis[ind] = vis[ind-1] = false;
  }
  if(ind+1 < n && !vis[ind] && !vis[ind+1] && (a[ind]+b[ind]+b[ind+1] == val || val == -1)) {
    vis[ind] = vis[ind+1] = true;
    tval = a[ind]+b[ind]+b[ind+1];
    foo(ind+1,tval,cnt+2);
    vis[ind] = vis[ind+1] = false;
  }
  if(ind-1>=0 && ind+1<n && !vis[ind-1] && !vis[ind+1] && (a[ind]+b[ind-1]+b[ind+1] == val || val == -1)) {
    vis[ind-1] = vis[ind+1] = true;
    tval = a[ind]+b[ind-1]+b[ind+1];
    foo(ind+1,tval, cnt+2);
    vis[ind-1] = vis[ind+1] = false;
  }
  if(ind-1>=0 && ind+1 < n && !vis[ind] && !vis[ind-1] && !vis[ind+1] && (a[ind]+b[ind]+b[ind-1]+b[ind+1] == val || val == -1)) {
    vis[ind] = vis[ind-1] = vis[ind+1] = true;
    tval = a[ind]+b[ind]+b[ind-1]+b[ind+1];
    foo(ind+1,tval,cnt+3);
    vis[ind] = vis[ind-1] = vis[ind+1] = false;
  }
  //exit(0);
//cout << "out " << ind << endl;
}
// int foo() {
//   // if(n == 1) return a[0]+b[0];
//   // int ans = -1;
//   // SET0(vis);
//   // if(foo(1,a[0])) ans = a[0];
//   // SET0(vis);
//   // vis[0] = 1;
//   // if(foo(1,a[0]+b[0])) ans = max(ans,a[0]+b[0]);
//   // SET0(vis);
//   // vis[1] = 1;
//   // if(foo(1,a[0]+b[1])) ans = max(ans,a[0]+b[1]);
//   foo(0,-1,0);
//   return ans;
// }
int main() {
  int t = 1;
  SCI(t);
  while(t--) {
    SCI(n);
    for(int i = 0; i < n; i++) SCI(b[i]);
    for(int i = 0; i < n; i++) SCI(a[i]);
    a[n] = b[n] = 0;
    ans = -1;
    SET0(vis);
    foo(0,-1,0);
    PRI(ans);
  }
return 0;
}