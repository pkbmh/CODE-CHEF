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

const int MAX = 1e6+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;
char str[MAX];
int n,K;

bool check(int sz) {
	// cout << " sz = " << sz << endl;
	int k = K;
	int c = str[0];
	int ind = 1;
	int st = 0;
	int bsz;
	while(ind < n) {
		if(str[ind] != c) {
			bsz = ind-st;
			k -= (bsz-sz) / (sz+1);
			k -= ((bsz-sz) % (sz+1) > 0);
			st = ind;
			c = str[ind];
		}
		ind++;
		if(k < 0){return 0; }
	}
	bsz = ind-st;
	k -= (bsz-sz) / (sz+1);
	k -= ((bsz-sz) % (sz+1) > 0);
	// cout << k << " kr " << st << endl;
	if(k < 0) return 0;
	return 1;
}
int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    SCI(t);
    while(t--) {
    	SCI(n); SCI(K);
    	scanf("%s", str);
    	int cnt1 = 0,cnt2 = 0;
    	for(int i = 0; i < n; i++) {
    		if((i&1) && str[i] == '0') cnt1++;
    		if((i&1) == 0 && str[i] == '1') cnt1++;

    		if((i&1) && str[i] == '1') cnt2++;
    		if((i&1) == 0 && str[i] == '0') cnt2++;
    	}
    	// cout << cnt1 << " "<< cnt2 << endl;
    	if(min(cnt1 , cnt2) <= K) {

    		printf("1\n");
    	}else{
    	int l = 2; 
    	int h  = n;

    	while(l < h) {
    		int mid = (l+h) / 2;

	   		if(check(mid)) h = mid;
	   		else l = mid + 1;
    	}

    	PRI(l);
    	}
    }
    return 0;
}