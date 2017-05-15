#include <bits/stdc++.h>
using namespace std;

int arr[100006],next[100006];
bool vis[100006],res[100006];
void print1(int n) {
    int cnt = 0;
    int i = 1;
    while(i <= n) {
        int x = 0;
        int j = i;
        if(!vis[j]){
            while(!vis[j]) {
                vis[j] = true;
                if(res[j]) goto xxxx;
                j = next[j];
            }
            if(!res[j]){
                int tmp = j;
                res[j] = true;
                int hh = 100;
                while(next[j] != tmp){
                    x++;
                    j = next[j];
                    if(res[j]) goto xxxx;
                    res[j] = true;
                }
                x++;
                cnt += x;
            }
        }
        xxxx:
        i++;
    }
    printf("%d\n", cnt);
}
int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            next[i] = (i+arr[i])%n+1;
            vis[i] = false;
            res[i] = false;
        }
        print1(n);
    }
return 0;
}