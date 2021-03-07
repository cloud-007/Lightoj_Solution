/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 201;
int tc, casee = 1, n, m, d, q, a[sz];
ll dp[sz][sz][4];

ll rec(int idx, int cnt, ll sum) {
    if(cnt == m)return sum == 0;
    if(idx > n)return 0;
    ll &ret = dp[idx][cnt][sum];
    if(~ret)return ret;
    ret = 0;
    ret += rec(idx + 1, cnt + 1, (sum + a[idx]) % d);
    ret += rec(idx + 1, cnt, sum % d);
    return ret;
}

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
            cin >> d >> m;
            memset(dp, -1, sizeof dp);
            cout << rec(1, 0, 0) << endl;
        }
    }


    return 0;
}
