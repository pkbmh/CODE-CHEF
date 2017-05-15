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


VLLI arr,arr1,arr2,part1_set,part2_set;
int n;
LLI k;


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    SCI(n); SCLL(k);
    LLI tmp;
    for(int i = 0; i < n; i++) {
        SCLL(tmp);
        arr.push_back(tmp);
    }
    n = arr.size();
    int part1 = n / 2;
    int part2 = n - part1;
    for(int i = 0; i < part1; i++)arr1.PB(arr[i]);
    for(int i = part1; i < n; i++)arr2.PB(arr[i]);
    int lp = (1<<(part1));
    for(int i = 1; i < lp; i++) {
        long double mul = 1;
        for(int j = 0; j < part1; j++) {
            if((i&(1<<j))) {
                mul = mul * arr1[j];
            }
            if(mul > k || mul < 0) break;
        }
        if(mul <= k) part1_set.PB((LLI)mul);
    }
    lp = (1<<(part2));  
    for(int i = 1; i < lp; i++) {
        long double mul = 1;
        for(int j = 0; j < part2; j++) {
            if((i&(1<<j))) {
                mul = mul * arr2[j];
            }
            if(mul > k || mul < 0) break;
        }
        if(mul <= k) part2_set.PB((LLI)mul);
    }

    sort(part2_set.begin(), part2_set.end());
    sort(part1_set.begin(), part1_set.end());
    LLI ans = part1_set.size() + part2_set.size();

    int i = 0, sz1 = part1_set.size();
    int j = 0, sz2 = part2_set.size();
    

    for(int i = 0; i < sz1; i++) {
        LLI a = part1_set[i];
        LLI ind = upper_bound(part2_set.begin(), part2_set.end(), k/a)-part2_set.begin();
        ans = ans + ind;
    }
    PRLL(ans);


    return 0;
}