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

const int MAX = 1e5+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;

VI arr[3003];
bool vis[3003], air[3003];
int dis_t[3003], min_t[3003],parent[3003];

int time_tt = 0;
void articulation_point(int u, int p) {
	vis[u] = true;
	dis_t[u] = min_t[u] = time_tt++;
	parent[u] = p;
	int child = 0;
	for(int i = 0; i < arr[u].size(); i++) {
		int v = arr[u][i];
		if(!vis[v]) {
			child++;
			articulation_point(v,u);
			min_t[u] = min(min_t[u],min_t[v]);
			if(p == -1 && child > 1) air[u] = true;
			if(p != -1 && min_t[v] >= dis_t[u]) air[u] = true;
		}else if(v != parent[u]) min_t[u] = min(min_t[u], dis_t[v]);
	}
}	
int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    SCI(t);
    while(t--){
		int n,m,k,u,v;
		SCI(n); SCI(m); SCI(k);
		time_tt = 0;
		for(int i = 0; i < m; i++) {
			SCI(u);
			SCI(v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		articulation_point(0,-1);
		int cnt = 0;
		for(int i = 0; i < n; i++) if(air[i]) {cnt++;}
		printf("%d\n", k*cnt);

		for(int i = 0.; i <= n; i++) {
			arr[i].clear();
			vis[i] =  air[i] = 0;
			dis_t[i] = min_t[i] = parent[i] = 0;
		}
	}
    return 0;
}