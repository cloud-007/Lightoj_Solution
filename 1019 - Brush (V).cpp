#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int sz = 200;
vector < int > x[sz];
map < pair < int, int >, int > cost;
map < int, int > dis, vis;
bool fl;
int n, m;

void djk(int u) {
    for(int i = 0; i <= 101; i++)
        dis[i] = INT_MAX;
    priority_queue< pair < int, int > > y;
    y.push({0, u});
    dis[u] = 0;
    while(!y.empty()) {
        pair< int, int > t = y.top();
        u = t.second;
        if(u == n)
            fl = true;
        for(int i = 0; i < x[u].size(); i++) {
            int v = x[u][i];
            if(v == n)
                fl = true;
            if(dis[u] + cost[ {u, v}] < dis[v]) {
                dis[v] = dis[u] + cost[ {u, v}];
                y.push({-dis[v], v});
            }
        }
        y.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 0; i <= 101; i++)
            x[i].clear();
        cost.clear();
        dis.clear();
        fl = false;
        while(m--) {
            int u, v, cos;
            cin >> u >> v >> cos;
            x[u].pb(v);
            x[v].pb(u);
            if(cost[ {u, v}])
                cost[ {u, v}] = min(cos, cost[ {u, v}]);
            else
                cost[ {u, v}] = cos;
            if(cost[ {v, u}])
                cost[ {v, u}] = min(cos, cost[ {v, u}]);
            else
                cost[ {v, u}] = cos;
        }
        djk(1);
        if(fl)
            printf("Case %d: %d\n", casee++, dis[n]);
        else
            printf("Case %d: Impossible\n", casee++);
    }
}
