#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int sz = 30050;
vector < int > x[sz];
int dis[sz], vis[sz];
map < pair < int, int >, int > cost;

void dfs(int u) {
    vis[u] = 1;
    for(auto i : x[u]) {
        if(!vis[i]) {
            dis[i] = dis[u] + cost[ {u, i}];
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        cost.clear();
        memset(dis, 0, sizeof dis);
        memset(vis, 0, sizeof vis);
        for(int i = 0; i <= sz; i++)
            x[i].clear();
        n--;
        for(int i = 0; i < n; i++) {
            int u, v, cos;
            cin >> u >> v >> cos;
            x[u].pb(v);
            x[v].pb(u);
            cost[ {u, v}] = cos;
            cost[ {v, u}] = cos;
        }
        dis[0] = 0;
        dfs(0);
        int start = 0, now = dis[0];
        for(int i = 1; i <= n; i++) {
            if(dis[i] > now) {
                now = dis[i];
                start = i;
            }
        }
        memset(dis, 0, sizeof dis);
        memset(vis, 0, sizeof vis);
        dfs(start);
        int mx = 0;
        for(int i = 0; i <= n; i++)
            mx = max(mx, dis[i]);
        printf("Case %d: %d\n", casee++, mx);
    }
}
