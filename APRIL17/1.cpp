#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin >> n;
	set<string> a;
	string str;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {cin >> str; a.insert(str);}
		int cnt = 0;
		for(int j = 0; j < 4; j++) {
			cin >> str;
			if(a.find(str) != a.end()) {cnt++;}
		}
		if(cnt >= 2) cout << "similar" << endl;
		else cout << "dissimilar" << endl;
		a.clear();

	}
	return 0;
}