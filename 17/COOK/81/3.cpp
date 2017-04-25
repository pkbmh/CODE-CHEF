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

PII arr[50];
double dist[50][50];
int vis[50][1<<13];
double  dp[50][1<<13];
string str[50];
int k,n;
int check[50];
int tc = 0;
int ind_mask[50];

double foo(int ind, int mask) {
	if(mask == (1<<k)-1) {
		return dist[ind][0];
	}
	if(vis[ind][mask] == tc) {return dp[ind][mask];}
	vis[ind][mask] = tc;
	double ans = INT_MAX;
	for(int i = 1; i <= n; i++) {
		if((mask|ind_mask[i]) > mask) {
			ans = min(ans, foo(i, (mask|ind_mask[i]))+dist[i][ind]);
		}
	}
	return dp[ind][mask] = ans;
}
int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
	str[0] = "0000000000000000000000000000000000000000000000";
	int t;
	SCI(t);
	arr[0] = {0,0};
	while(t--) {
		tc++;
		memset(check,0,sizeof(check));
		memset(ind_mask,0,sizeof(ind_mask));
		SCI(n);
		SCI(k);
		for(int i = 1; i <= n; i++) {
			SCI(arr[i].first);
			SCI(arr[i].second);
			for(int j = 0; j < i; j++) {
				dist[j][i] = dist[i][j] = sqrt((arr[j].first-arr[i].first)*(arr[j].first-arr[i].first)+(arr[j].second-arr[i].second)*(arr[j].second-arr[i].second));
			}
		}
		for(int i = 1; i <= n; i++) {
			cin >> str[i];
			for(int j = 0; j < k; j++) {
				if(str[i][j] == '1'){
					check[j] = 1;
					ind_mask[i] = ind_mask[i] | (1<<j);
				}	
			}
		}
		int f = 1;
		for(int i = 0; i < k; i++) {
			if(check[i] == 0) {cout << "-1" << endl; f = 0; break;}
		}
		if(f)
		printf("%.16lf\n", foo(0,0));
	}



    
    return 0;
}