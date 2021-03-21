/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1005;
int tc, casee = 1, n, a[sz], dp[sz][2], mp[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];

        memset(dp, 0, sizeof dp);

        int Ans = 0;

        for(int i = n; i > 1; i--) {
            dp[i][1] = max(dp[i][1], dp[i][0] + a[i]);
            dp[i - 1][0] = max(dp[i - 1][0], dp[i][0]);
            dp[i - 2][0] = max(dp[i][1], dp[i - 2][0]);
        }

        for(int i = 1; i <= n; i++) {
            Ans = max({Ans, dp[i][1], dp[i][0]});
        }

        memset(dp, 0, sizeof dp);

        for(int i = n - 1; i >= 1; i--) {
            dp[i][1] = max(dp[i][1], dp[i][0] + a[i]);
            dp[i - 1][0] = max(dp[i - 1][0], dp[i][0]);
            dp[i - 2][0] = max(dp[i][1], dp[i - 2][0]);
        }

        for(int i = 1; i <= n; i++) {
            Ans = max({Ans, dp[i][1], dp[i][0]});
        }

        cout << "Case " << casee++ << ": " << Ans << Endl;
    }


    return 0;
}
