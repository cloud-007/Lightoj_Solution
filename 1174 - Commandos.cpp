#include<bits/stdc++.h>
using namespace std;

const int sz = 105;
vector < int > x[sz];
int dis[sz], vis[sz], cons[sz];

void bfs( int u) {
    queue < int > q;
    q.push(u);
    vis[u] = 1;
    dis[u] = 0;
    while(!q.empty()) {
        int now = q.front();
        for(auto i : x[now]) {
            if(!vis[i]) {
                q.push(i);
                dis[i] = dis[now] + 1;
                vis[i] = 1;
            }
        }
        q.pop();
    }
}
void bfs2( int u, int v) {
    queue < int > q;
    q.push(u);
    vis[u] = 1;
    dis[u] = cons[u];
    while(!q.empty()) {
        int now = q.front();
        for(auto i : x[now]) {
            if(!vis[i]) {
                q.push(i);
                dis[i] = dis[now] + 1;
                vis[i] = 1;
            }
        }
        q.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    set < int > st;
    cin >> tc;
    while(tc--) {
        memset(cons, 0, sizeof cons);
        int n, m;
        cin >> n >> m;
        st.clear();
        for(int i = 0; i < sz; i++)
            x[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
            st.insert(u), st.insert(v);
        }
        memset(dis, 0, sizeof dis);
        memset(vis, 0, sizeof vis);

        int s, des;
        cin >> s >> des;
        bfs(s);
        int tot = dis[des];
        for(int i = 0; i < n; i++)
            cons[i] = dis[i];
        for(auto i : st) {
            memset(dis, 0, sizeof dis);
            memset(vis, 0, sizeof vis);
            bfs2(i, des);
            tot = max(tot, dis[des]);
        }
        printf("Case %d: %d\n", casee++, tot);
    }
}
