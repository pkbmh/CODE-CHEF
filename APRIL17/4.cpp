#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int N, K, X, M , S;
vector<pair<int,int> > arr[MAX];

long long dist[MAX];
bool vis[MAX];

void diji() {
	dist[S] = 0;
	priority_queue<pair<long long,int>, vector<pair<long long, int> >, greater<pair<long long,int> > > pq;
	pq.push({0,S});
	bool flag =  1;
	while(!pq.empty()) {
		pair<long long, int> node = pq.top(); pq.pop();
		int u = node.second;
		long long d = node.first;

		if(!vis[u]){
			vis[u] = 1;
			if(u <= K && flag) {
				for(int i = 1; i <= K; i++) {
					if(dist[i] > d+X) {
						dist[i] = d+X;
						pq.push({d+X,i});
					}
				}
				flag = 0;
			}
			for(int i = 0; i < arr[u].size(); i++) {
				int v = arr[u][i].first;
				int ed = arr[u][i].second;

				if(dist[v] > d+ed) {
					dist[v] = d+ed;
					pq.push({d+ed,v});
				}
			}
		}
	}

}

int main()
{
	int t;
	int u,v,d;
	scanf("%d", &t);
	for(int i = 0; i < MAX; i++) {dist[i] = (long long )MAX * INT_MAX; vis[i] = 0;}
	while(t--) {
		scanf("%d%d%d%d%d",&N,&K,&X,&M,&S);
		for(int i = 0; i < M; i++) {
			scanf("%d%d%d",&u,&v,&d);
			arr[u].push_back({v,d});
			arr[v].push_back({u,d});
		}
		diji();
		for(int i = 1; i <= N; i++) {
			printf("%lld ", dist[i]);
			arr[i].clear();
			vis[i] = 0;
			dist[i] = (long long)MAX * INT_MAX;
		}
		printf("\n");
	}
	return 0;
}