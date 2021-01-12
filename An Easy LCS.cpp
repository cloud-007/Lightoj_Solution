/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 105;
int tc, dp[sz][sz], casee = 1, n, m;
string a, b, ans[sz][sz];

string rec(int i, int j) {
    if(i >= n || j >= m)return "";
    if(~dp[i][j])return ans[i][j];
    dp[i][j] = 1;
    if(a[i] == b[j]) {
        ans[i][j] = a[i] + rec(i + 1, j + 1);
    } else {
        string ret1 = rec(i + 1, j);
        string ret2 = rec(i, j + 1);
        if(ret1.size() > ret2.size())ans[i][j] = ret1;
        else if(ret1.size() < ret2.size())ans[i][j] = ret2;
        else ans[i][j] = min(ret2, ret1);
    }
    return ans[i][j];
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        n = a.size(), m = b.size();
        string fin = rec(0, 0);
        if(fin.empty())fin = ":(";
        cout << "Case " << casee++ << ": " << fin << endl;
    }


    return 0;
}
