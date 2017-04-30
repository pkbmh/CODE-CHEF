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
int n,x,y,m;
const int mxz = 305;
char str[mxz];

unordered_map<LLI,LLI> dp[mxz][mxz];

LLI foo(LLI gd, int ind, int sp) {
	// cout << gd << " "<< ind << " "<< sp << endl;
	if(ind >= n) {
		if(sp >= x+1 && sp <= y+1) return gd;
		return 0;
	}
	if(sp > y) return 0;
	if(gd == 1) return gd;
	if(dp[ind][sp].count(gd)) return dp[ind][sp][gd];
	LLI ans = 0;
	int sz = min(n,ind+m);
	LLI num = 0;
	LLI gcd = 0;
	LLI ngd;
	for(int i = ind; i < sz; i++) {
		num = num * 10 + (str[i]-'0');
		if(gd == -1) ngd = num;
		else ngd = GCD(num,gd);
		gcd = max(gcd, foo(ngd, i+1, sp+1));
	}
	return dp[ind][sp][gd] = gcd;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
	int t;
	SCI(t);
	while(t--) {
		//memset(dp,-1,sizeof(dp));
		for(int i = 0; i < mxz; i++) for(int j = 0; j < mxz; j++) dp[i][j].clear();
		
		SCI(n);
		scanf("%s", str);
		SCI(m); SCI(x); SCI(y);
		PRLL(foo(-1,0,0));
	}
    
    return 0;
}