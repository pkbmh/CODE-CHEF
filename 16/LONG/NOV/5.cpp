#include <bits/stdc++.h>
using namespace std;
 
// i/o
#define SCI(a) scanf("%d", &a)
#define SCLL(a) scanf("%lld", &a)
#define PRI(a) printf("%d\n", a)
#define PRLL(a) printf("%lld\n", a)
#define gc getchar_unlocked
 
/*void fastRead_int(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}*/
 
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
 
const int MAX = 50005;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;
 
LLI ans;
bool pre[MAX];
int parent[MAX],n,m;
vector<PII> arr[MAX];
int vis;
 
 
void dfs(int s) {
 
    if(pre[s])vis++;
    vector<int>tmp;
    int pv = vis;
    for(int i = 0; i < arr[s].size(); i++) if(arr[s][i].F != parent[s]){
        parent[arr[s][i].F] = s;
        dfs(arr[s][i].F);
        int cnt = vis-pv;
        ans = ans + (m-cnt)*cnt * 2LL * arr[s][i].S;
        pv = vis;
    }
}
 int main()
 {
 
 	int t;
 	int u,v,l;
 	SCI(t); while(t--) {
 	    for(int i = 0; i < MAX; i++) {
            pre[i] = false;
            parent[i] = -1;
            arr[i].clear();
 	    }
 
        SCI(n); SCI(m);
        for(int i = 0; i < n-1; i++) {
            SCI(u); SCI(v);SCI(l);
            arr[u].push_back({v,l});
            arr[v].push_back({u,l});
        }
        int s;
        for(int i = 0; i < m; i++) {
            SCI(u);
            pre[u] = 1;
            if(arr[u].size() == 1)s = u;
        }
        parent[arr[s][0].F] = s;
        ans = arr[s][0].S * 2LL * (m-1);
        vis = 1;
        dfs(arr[s][0].F);
        LLI x = m * (LLI)m;
        LLI gd = GCD(x,ans);
        printf("%lld %lld\n", ans / gd, x / gd);
 	}
 return 0;
 }
 