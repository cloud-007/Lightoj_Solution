#include<bits/stdc++.h>
using namespace std;

const int sz = 2000;
vector < int > x[sz];
int vis[sz], cnt = 0, a[sz], sum = 0;

void dfs(int u) {
    vis[u] = 1;
    sum += a[u - 1];
    for(auto i : x[u]) {
        if(!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        for(int i = 1; i <= sz; i++)x[i].clear();
        memset(vis, 0, sizeof vis);
        int node, edge;
        cin >> node >> edge;
        for(int i = 0; i < node; i++)cin >> a[i];
        while(edge--) {
            int u, v;
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        set < int > st;
        bool fl = true;
        for(int i = 1; i <= node; i++) {
            cnt = 1, sum = 0;
            if(!vis[i]) {
                dfs(i);
                if(sum % cnt == 0) {
                    st.insert(sum / cnt);
                } else {
                    fl = false;
                    break;
                }
            }
        }
        if(fl && st.size() == 1)
            printf("Case %d: Yes\n", casee++);
        else
            printf("Case %d: No\n", casee++);
    }
}
