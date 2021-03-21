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
ll tc, casee = 1,  n, dp[70][70];
string s;

ll rec(int i, int j) {
    if(i > j)return 0;
    if(i == j)return 1;
    ll &ret = dp[i][j];
    if(~ret)return ret;
    ret = 0;
    if(s[i] == s[j])ret = 1;
    else ret -= rec(i + 1, j - 1);
    ret += rec(i + 1, j) + rec(i, j - 1);
    return ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> s;
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(0, s.size() - 1) << Endl;
    }


    return 0;
}
