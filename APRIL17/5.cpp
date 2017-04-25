#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 1e6+10;

bool vis[MAX];
int prime[78600];
int pq[78600];

int main()
{	
	register int i,j;
	int x = 0;
	for(i = 2; i < MAX; i++) if(!vis[i]) {prime[x++] = i; for(j = i+i; j < MAX; j += i) vis[j] = 1;}
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long res = 0;

	for(long long  ii = a; ii <= b; ii++) {
		i = j = 0;
		long long num = ii;
		long long div = 1;
		while((long long)prime[j] * prime[j] <= num) {
			int cnt = 0;
			while(num % prime[j] == 0) {
				cnt++;
				num /= prime[j];
			}
			j++;
			if(cnt) { pq[i++] = cnt; div *= (cnt+1);}
		}

		if(num > 1) { pq[i++] = 1; div *= 2; }
		sort(pq,pq+i);
		i--;
		long long ans = div-1;
		while(false && i >= 0) {
			int cnt = pq[i];
			if(cnt == 1) {
				div = div / 2;
				ans = ans  + div;
				i--;
			}
			else if(i == 0) {
				ans  = ans  + ((div * cnt) >> 1);
				i--;
			}
			else {
				int val = pq[i-1] - 1;
				int x = ((cnt * (cnt - 1)) >> 1) - ((val * (val+1)) >> 1);
				ans = ans  + div / (cnt+1) * (x+cnt);
				if(val) {
					int ind = upper_bound(pq,pq+i,val) - pq;
					int tmp = pq[ind];
					pq[ind] = val;
					pq[i] = tmp;
				}else i--;
				int step = cnt-val;
				div = div / (cnt+1) * (cnt-(step-1));
			}
		}
		res += ans;
	}
	printf("%lld\n", res);
	
	return 0;
}