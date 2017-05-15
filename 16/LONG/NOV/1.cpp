#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        long long ans = arr[0] / __gcd(arr[0],arr[1]) * arr[1];
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++){
                ans = min(ans,arr[i] / __gcd(arr[i],arr[j])*arr[j]);
            }
        }
        cout << ans << endl;
    }
}