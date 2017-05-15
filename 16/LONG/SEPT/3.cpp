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

	int main()
	{
		int t;
		SCI(t);

		while(t--) {
			int n;
			SCI(n);
			int id = -1;
			int msc = INT_MIN;
			for(int cid = 0; cid < n; cid++) {
				int m,x;
				SCI(m);
				int camp[7];
				for(int i = 0; i < 7; i++) camp[i] = 0;
				for(int j= 0; j < m; j++) {
					SCI(x);
					camp[x]++;
				}
				sort(camp, camp+7);

				int len = 1;
				while(len < 7 && camp[len] == 0) len++;
				int sc = m;

				for(int i = len; i < 7; i++) {
					int dif = 7 - i;
					if(dif == 6) sc = sc + 4 * camp[i];
					else if(dif == 5) sc = sc + 2 * camp[i];
					else if(dif == 4) sc = sc + 1 * camp[i];
					for(int j = i+1; j < 7; j++) camp[j] = camp[j] - camp[i];
                    camp[i] = 0;
				}
				if(msc < sc) {
					msc = sc;
					id = cid+1;
				}
				else if(msc == sc && id != -1) {
                    id = -1;
				}


			}

			if(id == 1) printf("chef\n");
            else if(id == -1) printf("tie\n");
            else printf("%d\n", id);
		}
	return 0;
	}