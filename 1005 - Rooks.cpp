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
ll tc, casee = 1, n, k, a[sz];

ll rec(ll r, ll c, ll k) {
    if(k > r || k > c)return 0;
    else if(k == 0)return 1;
    else if(r == 1)return c;
    else return c * rec(r - 1, c - 1, k - 1) + rec(r - 1, c, k);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n >> k;
        cout << "Case " << casee++ << ": " << rec(n, n, k) << endl;
    }


    return 0;
}
