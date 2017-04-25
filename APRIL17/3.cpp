#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string str;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cin >> str;
		int len = str.length();
		int zcnt = 0;
		int last1 = len;
		long long ans = 0;
		int pre_sel = 0;
		for(int i = len-1; i >= 0; i--) {
			if(str[i] == '0') zcnt++;
			else {
				if(last1-(i+1) > 0) pre_sel++;
				ans = ans + pre_sel + zcnt;
				last1 = i;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}