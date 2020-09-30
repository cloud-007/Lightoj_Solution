#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

int tc, casee = 1, n, dp[55][5][10];
string s;

bool check(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')return true;
    return false;
}

int rec(int id, int v, int c) {
    if(v >= 3 || c >= 5)return 2;
    if(id == n)return 1;
    int &ret = dp[id][v][c];
    if(~ret)return ret;
    ret = 0;
    if(check(s[id])) {
        ret = rec(id + 1, v + 1, 0);
    } else if(s[id] == '?') {
        ret = rec(id + 1, v + 1, 0) | rec(id + 1, 0, c + 1);
    } else {
        ret = rec(id + 1, 0, c + 1);
    }
    return ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    cloud_007;
    cin >> tc;
    while(tc--) {
        memset(dp, -1, sizeof dp);
        cin >> s;
        n = s.size();
        int ans = rec(0, 0, 0);
        string res;
        if(ans == 2)res = "BAD";
        else if(ans == 1)res = "GOOD";
        else res = "MIXED";
        cout << "Case " << casee++ << ": " << res << endl;
    }
}
