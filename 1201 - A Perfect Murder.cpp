#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, n, m, u, v, casee = 1, ans, dp[1005][2];
vector < int > x[1005];
bool done[1005];

int rec(int node, int pre, int par) {
    done[node] = true;
    int &ret = dp[node][pre];
    if(~ret) {
        return ret;
    }
    ret = pre;
    for(auto i : x[node]) {
        if(i != par) {
            if(pre == 0) {
                int one = rec(i, 1, node);
                int two = rec(i, 0, node);
                ret += max(one, two);
            } else {
                ret += rec(i, 0, node);
            }
        }
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cloud_007;
    cin >> tc;
    while(tc--) {
        memset(done, false, sizeof done);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i <= 1000; i++)x[i].clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!done[i]) {
                ans += max( rec(i, 0, -1), rec(i, 1, -1));
            }
        }
        cout << "Case " << casee++ << ": " << ans << endl;
    }
}
