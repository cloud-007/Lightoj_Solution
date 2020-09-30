#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, n, casee = 1, r, g, b;
struct R {
    int r, g, b;
};
vector < R > v;
int dp[55][3];
/// r=0, g=1, b=2;
int rec(char pre, int i, int ty) {
    if(i == n)return 0;
    int &ans = dp[i][ty];
    if(~ans)return ans;
    ans = 0;
    if(pre == 'R') {
        ans += v[i].r + min(rec('G', i + 1, 1), rec('B', i + 1, 2));
    } else if(pre == 'G') {
        ans += v[i].g + min(rec('R', i + 1, 0), rec('B', i + 1, 2));
    } else {
        ans += v[i].b + min(rec('G', i + 1, 1), rec('R', i + 1, 0));
    }
    return ans;
}

int main() {
    cloud_007;
    cin >> tc;
    while(tc--) {
        v.clear();
        memset(dp, -1, sizeof dp);
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> r >> g >> b;
            v.push_back({r, g, b});
        }
        cout << "Case " << casee++ << ": " << min({rec('R', 0, 0), rec('G', 0, 1), rec('B', 0, 2)}) << endl;
    }
    return 0;
}
