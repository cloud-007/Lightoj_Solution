#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, n, k, a[51], c[51], casee = 1, dp[51][21][1005];
const int mod = 100000007;

int rec(int id, int sum, int cnt) {
    if(id >= n)return 0;
    if(sum == k)return 1;
    int &ret = dp[id][cnt][sum];
    if(~ret)return ret;
    ret = 0;
    if(cnt < c[id] && a[id] + sum <= k) {
        ret += rec(id, a[id] + sum, cnt + 1) % mod;
    }
    ret += rec(id + 1, sum, 0) % mod;
    return ret % mod;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cloud_007;
    cin >> tc;
    while(tc--) {
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        for(int i = 0; i < n; i++)cin >> a[i];
        for(int i = 0; i < n; i++)cin >> c[i];
        cout << "Case " << casee++ << ": " << rec(0, 0, 0) << "\n";
    }
}
