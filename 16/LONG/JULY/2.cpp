  
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

LLI arr[100005];
int n;
void foo(int i, int j, LLI &sum) {
  LLI a,b,pi,pj;
    while(i < j){
        a = b = INT_MAX;
        pi = i-1;
        pj = j-1;
        if(pi >= 0) a = arr[i] - arr[pi];
        if(j < n) b = arr[j] - arr[pj];
        
        if(a < b) {
          sum = sum + a;
          i++;
        }else {
          sum = sum + b;
          j--;
        }
    }
}
int main() {
  int t = 1;
  int i,j,pj,pi;
  LLI sum,a,b;
  string str;
  SCI(t);
  while(t--) {
    SCI(n);
    cin >> str;
    //cout << str << " str " << endl;
    for(i = 0; i < n; i++) SCLL(arr[i]);
    sum = i = j = 0;
    while(i < n && str[i] == '1') i++;
    j = i;
    while(j < n && str[j] == '0') j++;

    while(j <= n && i < j) {
      foo(i,j,sum);
      i = j;
      while(i < n && str[i] == '1') i++;
      j = i;
      while(j < n && str[j] == '0') j++;
    }
    PRLL(sum);
  }
return 0;
}