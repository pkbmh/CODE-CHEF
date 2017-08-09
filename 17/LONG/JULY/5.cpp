   
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

const int MX = 1005;
const LLI MOD7 = 1e9+7, MOD9 = 1e9+9;

LLI  bell[MX][MX][2];

void bellNumber(int n)
{
  
   bell[0][0][0] = bell[0][0][1] = 1;
   for (int i=1; i<=n; i++)
   {
      // Explicitly fill for j = 0
      bell[i][0][0] = bell[i-1][i-1][0];
      bell[i][0][1] = bell[i-1][i-1][1];
      // Fill for remaining values of j
      for (int j=1; j<=i; j++){
         bell[i][j][0] = bell[i-1][j-1][0] + bell[i][j-1][0];
         bell[i][j][1] = bell[i-1][j-1][1] + bell[i][j-1][1];
         bell[i][j][0] %= MOD7;
         bell[i][j][1] %= MOD9;

      }
   }
   // for(int i= 1; i <= n; i++) {
   //    cout << bell[i][0][0] << " " << bell[i][0][1] << endl;
   // }
}
LLI pass[MX][MX][2];
// T(n, k) = T(n, k-1) + T(n-1, k-1) + T(n-1, k)
void foo(int n, int k) {
  if(pass[n][k][0] != -1) return;
  if(k > n) {
    pass[n][k][0] = pass[n][k][1] = 0;
    return;
  }
  if(k == 1 || n == 1) {
    pass[n][k][0] = pass[n][k][1] = 1;
    return;
  }
  foo(n, k-1);
  foo(n-1, k-1);
  foo(n-1, k);
  pass[n][k][0] = (pass[n][k-1][0] + pass[n-1][k-1][0] + pass[n-1][k][0])%MOD7;
  pass[n][k][1] = (pass[n][k-1][1] + pass[n-1][k-1][1] + pass[n-1][k][1])%MOD9;
}
int main() {
  SETN1(pass);
  bellNumber(1001);
  foo(1001,1001);
  int t = 1;
  SCI(t);
  LLI n;
  while(t--) {
    SCLL(n);
    n--;
    if(n == 0) {
      cout << "0 0" << endl;
      continue;
    }
    if(n <= 1001) {
      // cout << "n " << n << endl;
      LLI p7 = bell[n][0][0];
      LLI p9 = bell[n][0][1];

      LLI q7 = pass[n][n][0];
      LLI q9 = pass[n][n][1];
     
      LLI ans = (q7 * PowMod(p7,MOD7-2, MOD7)) % MOD7;
      cout << ans << " ";
      ans = (q9 * PowMod(p9,MOD9-2, MOD9)) % MOD9;
      cout << ans << endl;
    }
    else cout <<" nhi aata"<< endl;
  }
return 0;
}