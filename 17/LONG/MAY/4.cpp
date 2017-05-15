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


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
	int n,k,q,c;
	SCI(n); SCI(k); SCI(q);
	deque<int> str ;
	string qstr;
	int tot1 = 0;
	for(int i = 0; i < n; i++){
		SCI(c);
		str.push_back(c);
		if(c == 1) tot1++;
	}
	cin >> qstr;
    if(k >= n) {
    	for(int i = 0; i < qstr.length(); i++) if(qstr[i] == '?') printf("%d\n", tot1);
    	return 0;
    }
    priority_queue<pair<int,int> >pq;
    int i = n-1;
    int cnt = 0;

    while(i >= 0 && i >= n-k){ 
    	cnt = cnt + str[i];
   		i--; 
    }
    int x = 0;
    pq.push({cnt,x++});
    while(i >= 0) {
    	cnt = cnt + str[i] - '0';
    	cnt = cnt - str[i+k] + '0';
    	pq.push({cnt,x++});
    	i--;
    }
    int qlen = qstr.length();
    int qcnt = 0;
    // cout << str << endl;
    // cout << str << " " << pq.top().first << " "<< pq.top().second << endl; 
    for(int i = 0; i < qlen; i++) {
    	if(qstr[i] == '?') {
    		while(pq.top().second < qcnt) pq.pop();
    		PRI(pq.top().first);
    	}else {

    		str.push_front(str[n-1]);
    		str.pop_back();
    		// cout << str << " -> "<< n-1-qcnt << endl;
    		cnt = cnt + str[0] - '0';
    		cnt = cnt - str[k] + '0';
    		pq.push({cnt,x++});
    		qcnt++;
    	}
    }
    return 0;
}