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



int mat[405][405];
int foo(set<int>&r, set<int>&c) {
    set<int>::iterator itr = r.begin(), itc = c.begin();
    while(itr != r.end() && itc != c.end() && *itr != *itc) {
        if(*itr < *itc) itr++;
        else itc++;
    }
    return *itc;
}
 int main()
 {

 	int t;
 	SCI(t); while(t--) {
        int n;

        cin >> n;
        for(int i = 1; i <= n; i++) {
            int st = i;
            for(int j = 1; j <= n; j++) {
                mat[j][i] = st++;
                if(st > n) st = 1;
            }
        }
        int r = (n+1) / 2;
        int c = n;
        int x = mat[(n+1)/2][n];
        while(r <= n && c >= 1) {
            mat[r][c] = 1;

            r++;
            c--;
        }
        r = x;
        c = 1;
        while(r >= 1 && c <= n) {
            mat[r][c] = 1;
            r--;
            c++;
        }
        mat[1][1] = x;
        r = n;
        c = 2;
        while(r >= 2 && c <= n) {
            mat[r][c] = x;
            r--;
            c++;
        }

        for(int i = 1; i  <= n; i++) {
            for(int j = 1; j <= n; j++) printf("%d ", mat[i][j]);
            printf("\n");
        }
 	}
 return 0;
 }