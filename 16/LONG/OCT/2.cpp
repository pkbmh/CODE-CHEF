#include <bits/stdc++.h>
using namespace std;

int main()
{

        int t;
        cin >> t;
        const double cs  = 0.5000;
        while(t--) {

            double s,v,a;
           scanf("%lf%lf", &s,&v);
           a = s/(v+v*cs);
           printf("%0.7lf\n", a);
        }
return 0;
}