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
int tc, n, m, t, casee = 1, par[sz];
ll dis[sz];
vector < pair < int, int >> x[sz];

void djk(int u) {
    priority_queue < pair < int, int >> pq;
    pq.push({0, u});
    dis[u] = 0;
    while(!pq.empty()) {
        u = pq.top().S;
        int val = -pq.top().F; pq.pop();
        if(val > dis[u])continue;
        for(auto i : x[u]) {
            int now = max(val, i.S);
            if(now < dis[i.F]) {
                dis[i.F] = now;
                pq.push({-now, i.F});
            }
        }
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++)x[i].clear(), dis[i] = 1e18, par[i] = i;
        while(m--) {
            int u, v, w; cin >> u >> v >> w;
            x[u].push_back({v, w});
            x[v].push_back({u, w});
        }
        cin >> t;
        djk(t);
        cout << "Case " << casee++ << ":" << endl;
        for(int i = 0; i < n; i++) {
            if(dis[i] == 1e18)cout << "Impossible" << endl;
            else cout << dis[i] << endl;
        }
    }


    return 0;
}
