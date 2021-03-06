/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

struct R {
    int value, cnt;
    bool operator<(R a)const {
        if(cnt == a.cnt)return value > a.value;
        return cnt < a.cnt;
    }
};
vector < R > v;
int q, n, casee = 1;

int calc(int n) {
    int ans = 0;
    if(n == 1)return 1;
    ans = 2;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ans++;
            if(n / i != i)ans++;
        }
    }
    return ans;
}

void init() {
    for(int i = 1; i <= 1000; i++) {
        v.push_back({i, calc(i)});
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    //cloud_007;
    init();
    sort(v.begin(), v.end());
    cin >> q;
    while(q--) {
        cin >> n;
        cout << "Case " << casee++ << ": " << v[n - 1].value << endl;
    }
    return 0 ;
}
