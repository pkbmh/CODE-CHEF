  
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

int arr[110][110],ans;
int r[2][110][110];
bool vis[110][110];
int n,m;

int foo(int f,int x,int y,int k, int step) {

  queue<PII>qu;
  qu.push({x,y});
  r[f][x][y] = 0;
  vis[x][y] = true;
  while(!qu.empty()) {
    PII tmp = qu.front();
    qu.pop();
    x = tmp.F;
    y = tmp.S;
    step = r[f][x][y];
    
    for(int i = max(x-k,1); i <= min(n,x+k); i++)
      for(int j = max(y-k,1);  j <= min(m,y+k); j++)
        if(abs(x-i) + abs(y-j) <= k && !vis[i][j] && arr[i][j] == 0){
           r[f][i][j] = step+1;
           vis[i][j] = true;
           qu.push({i,j});
         }
  }
  // if(!vis[x][y]) {
  //   vis[x][y] = true;
  //   r[f][x][y] = step;
  //   // for(int i = max(x-k,1); i <= min(n,x+k); i++)
  //   //   for(int j = max(y-k,1);  j <= min(m,y+k); j++)
  //   for(int i = 1; i <= n; i++) 
  //     for(int j = 1; j <= m; j++) 
  //       if(abs(x-i) + abs(y-j) <= k && !vis[i][j] && arr[i][j] == 0)
  //         foo(f,i,j,k,step+1);   
  // }
}
int main() {
  int t = 1,k1,k2;
  SCI(t);
  while(t--) {
    SET0(arr);

    SCI(n);SCI(m);SCI(k1);SCI(k2);
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        SCI(arr[i][j]);
        r[0][i][j] = -1;
        r[1][i][j] = -1;
      }
    }
    ans = INT_MAX;
    SET0(vis);
    foo(0,1,1,k1,0);
    SET0(vis);
    foo(1,1,m,k2,0);

    // for(int i = 1; i <= n; i++) {
    //   for(int j = 1; j <= m; j++) {
    //     cout << "("<<r[0][i][j]<<","<< r[1][i][j] << ") ";
    //   }
    //   cout << endl;
    // }cout << "-----------------" << endl;

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) 
        if(r[0][i][j] != -1 && r[1][i][j] != -1)
            ans = min(ans,max(r[0][i][j],r[1][i][j]));
    if(ans == INT_MAX) ans = -1;
    PRI(ans);
  }
return 0;
}