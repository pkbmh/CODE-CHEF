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

char str[MAX];
#define CHARS 26

int flag;
typedef struct trie_node {
    bool isend;
    char c;
    struct trie_node *child[CHARS];
}trie_node;

trie_node *create_newnode(char c) {
    trie_node *tmp = new trie_node;
    tmp->c = c;
    tmp->isend = false;

    for(int i = 0; i < CHARS; i++)
        tmp->child[i] = NULL;

    return tmp;
}
void insert_in_trie(trie_node **root , const char *str) {
    if(*root == NULL)
        (*root) = create_newnode(*str);

    if((*root)->c == (*str)) {
        if(*(str+1) != '\0')
            insert_in_trie(&(*root)->child[*(str+1)-'a'] , str+1);
        else
            (*root)->isend = true;
    }
    else
        insert_in_trie(&(*root)->child[(*str)-'a'] , str);
}
void traversal_trie(trie_node *root , string str) {
    if(root == NULL)
        return;
    if(root->c != '#')
        str += root->c;

    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            traversal_trie(root->child[i] , str);

    if(root->isend)
        cout << str << endl;
}
bool is_leaf(trie_node *root) {
    for(int i = 0; i < CHARS; i++)
        if(root->child[i] != NULL)
            return false;
    return true;
}

void create_prefix(trie_node *root, string str,int ind, set<string>&ans_prefix) {
	if(root == NULL) {
		ans_prefix.insert(str.substr(0,ind));
		return;
	}
	if(ind == str.length()){
		flag = 0;
		return;
	}
	create_prefix(root->child[str[ind]-'a'], str, ind+1, ans_prefix);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
	int n;
	char c;
	string str;
	SCI(n);
	trie_node *root = create_newnode('#');
	vector<string> blocked_site;
	set<string> unblocked_site;
    for(int i = 0; i < n; i++) {
    	cin >> c >> tmp;
   		if(c == '+') {
   			insert_in_trie(&root , tmp.c_str());
   			unblocked_site.insert(tmp);
   		}
    	else blocked_site.push_back(tmp);

    }
   	// traversal_trie(root , "");
   	set<string>ans_prefix;
   	flag = 1;
   	for(int i = 0; i < blocked_site.size() && flag; i++) {
   		if(unblocked_site.find(blocked_site[i]) != unblocked_site.end()) flag = 0;
   		create_prefix(root,blocked_site[i],0, ans_prefix);
   	}
   	if(flag == 0) {
   		cout << "-1" << endl;
   		return 0;
   	}
   	cout << ans_prefix.size() << endl;
   	for(auto a : ans_prefix) {
   		cout << a << endl;
   	}
    return 0;
}