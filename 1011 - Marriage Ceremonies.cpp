/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 16;
int tc, n, casee = 1,  a[sz][sz], dp[sz][(1 << sz) + 5];

int rec(int idx, int mask) {
    if(mask == (1 << n) - 1 || idx >= n)return 0;
    if(~dp[idx][mask])return dp[idx][mask];

    int sum = rec(idx + 1, mask);

    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        sum = max(sum, a[idx][i] + rec(idx + 1, mask | (1 << i)));
    }
    return dp[idx][mask] = sum;
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

        cout << "Case " << casee++ << ": " << rec(0, 0) << endl;

    }


    return 0;
}
