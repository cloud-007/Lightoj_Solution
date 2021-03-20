/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 11;
int tc, n, casee = 1, d, mp[sz], fact[sz], dp[(1 << 10) + 5][1010], len, a[sz];
string s;

int rec(int mask, int mod) {
    if(mask == (1 << len) - 1)return mod ? 0 : 1;
    int &ret = dp[mask][mod];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < len; i++) {
        if(mask & (1 << i))continue;
        ret += rec(mask | (1 << i), ((mod * 10) + a[i]) % d);
    }
    return ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    fact[0] = 1;
    for(int i = 1; i <= 10; i++)fact[i] = fact[i - 1] * i;
    cin >> tc;
    while(tc--) {
        cin >>  s >> d;
        len = s.size();
        memset(dp, -1, sizeof dp);
        memset(mp, 0, sizeof mp);
        for(int i = 0; i < len; i++) {
            a[i] = s[i] - '0';
            mp[a[i]]++;
        }
        ll Ans = rec(0, 0);

        for(int i = 0; i < 10; i++)Ans /= fact[mp[i]];

        cout << "Case " << casee++ << ": " << Ans << endl;
    }

    return 0;
}
