#include <bits/stdc++.h>
using namespace std;

int main()
{

        int t;
        cin >> t;
        while(t--) {
            int n,m,c;
            long long int ans = 0;
            cin >> n >> m >> c;
            for(int i = 1; i <= c; i++) {
                if(c%i == 0) {
                    if(i <= n && c/i <= m) {ans++;}
                    if(c/i <= n && i <= m) {ans++;}
                }
            }
            ans = ans / 2;
            cout << ans << endl;
        }
return 0;
}