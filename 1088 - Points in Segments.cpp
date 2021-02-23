/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, q, casee = 1, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n >> q;
        for(int i = 1; i <= n; i++)cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int u, v; cin >> u >> v;
            auto Left = lower_bound(a + 1, a + n + 1, u);
            auto Right = upper_bound(a + 1, a + n + 1, v);
            cout << Right - Left << endl;
        }
    }


    return 0;
}
