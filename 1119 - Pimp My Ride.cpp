/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 14;
int tc, n, casee = 1,  a[sz][sz], dp[(1 << sz) + 5];

int rec(int mask) {
    if(mask == (1 << n) - 1)return 0;
    if(~dp[mask])return dp[mask];
    int sum = 0, ret = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        sum = 0;
        for(int j = 0; j < n; j++) {
            if(mask & (1 << j))sum += a[i][j];
        }
        //sum += rec(mask);
        sum += a[i][i] + rec(mask | (1 << i));
        ret = min(ret, sum);
    }
    return dp[mask] = ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp, -1, sizeof dp);

        cout << "Case " << casee++ << ": " << rec(0) << endl;

    }


    return 0;
}
