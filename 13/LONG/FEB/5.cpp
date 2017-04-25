
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
 
typedef long long LL;
typedef pair<int,int> pii;
 
const int maxn = 500011;
pii lastr[maxn],lastc[maxn];
int rto1[maxn],rto0[maxn],cto1[maxn],cto0[maxn];
char str[11];
 
inline int lowbit(int x)
{
	return x & (-x);
}
 
inline void insert(int a[],int x,int val)
{
	if (!x) return;
	for (;x < maxn;x += lowbit(x))
		a[x] += val;
}
 
inline int query(int a[],int x)
{
	if (x <= 0) return 0;
	int ret = 0;
	for (;x;x -= lowbit(x))
		ret += a[x];
	return ret;
}
 
 
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= q;++i)
	{
		scanf(" %s",str);
		if (str[3] == 'S')
		{
			int no,val;
			scanf("%d%d",&no,&val);
			if (str[0] == 'R')
			{
				if (lastr[no].second) insert(rto1,lastr[no].first,-1);
				else insert(rto0,lastr[no].first,-1);
				if (val) insert(rto1,i,1);
				else insert(rto0,i,1);
				lastr[no] = make_pair(i,val);
			}
			else
			{
				if (lastc[no].second) insert(cto1,lastc[no].first,-1);
				else insert(cto0,lastc[no].first,-1);
				if (val) insert(cto1,i,1);
				else insert(cto0,i,1);
				lastc[no] = make_pair(i,val);
			}
		}
		else
		{
			int no,ans=0;
			scanf("%d",&no);
			if (str[0] == 'R')
			{
				if (lastr[no].second) ans = query(cto0,i) - query(cto0,lastr[no].first);
				else ans = n - query(cto1,i) + query(cto1,lastr[no].first);
			}
			else 
			{
				if (lastc[no].second) ans = query(rto0,i) - query(rto0,lastc[no].first);
				else ans = n - query(rto1,i) + query(rto1,lastc[no].first);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}