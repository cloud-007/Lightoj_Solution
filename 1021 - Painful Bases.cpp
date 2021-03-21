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
int tc, n, casee = 1, len, a[20], base, k;
ll dp[(1 << 16) + 5][25];
string s;

ll rec(int mask, int mod) {
    if(mask == (1 << len) - 1)return mod == 0;
    ll &ret = dp[mask][mod];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < len; i++) {
        if(mask & 1 << i)continue;
        ret += rec(mask | (1 << i), (mod * base + a[i]) % k);
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
        cin >> base >> k >> s;
        len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] >= '0' && s[i] <= '9')a[i] = s[i] - '0';
            else a[i] = s[i] - 'A' + 10;
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(0, 0) << endl;
    }


    return 0;
}
