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
int tc, n, casee = 1, m, a[sz], dp[12][12];

int rec(int idx, int pre) {
    if(idx > n)return 1;
    if(~dp[idx][pre])return dp[idx][pre];
    int &ret = dp[idx][pre];
    ret = 0;
    for(int i = 1; i <= m; i++) {
        if(pre == 0 || abs(a[i] - pre) <= 2) {
            ret += rec(idx + 1, a[i]);
        }
    }
    return ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> m >> n;
        for(int i = 1; i <= m; i++)cin >> a[i];
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(1, 0) << endl;
    }


    return 0;
}
