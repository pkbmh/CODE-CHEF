#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;
vector<int>arr[MAX];
pair<int,int> szi[MAX];

int main()
{
	int t,pi,n,k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n,&k);
		for(int i = 0; i < n; i++) {
			scanf("%d", &pi);
			szi[i] = {pi,i};
			arr[i].clear();
			arr[i].resize(pi);
			for(int j = 0; j < pi; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		sort(szi,szi+n);
		set<int>collect;
		int skip = 0;
		for(int i = n-1; i >= 0; i--) {
			int j = szi[i].second;
			int f = 0;
			for(int k = 0; k < szi[i].first; k++) {
				if(collect.find(arr[j][k]) == collect.end()) {
					f = 1;
					collect.insert(arr[j][k]);
				}
			}
			if(f == 0) {skip = 1; break;}
		}
		if(skip && collect.size() == k) cout << "some" << endl;
		else if(collect.size() == k) {cout << "all" << endl;}
		else cout << "sad" << endl;
	}
	return 0;
}