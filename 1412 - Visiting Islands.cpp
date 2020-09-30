#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second

const int sz = 1e5 + 5;
int tc, casee = 1, n, m, u, v, vis[sz], tree[sz * 3], q, k, cnt, mx_pos, now, start;
vector < int > x[sz], total;
vector < pair<int, int>> vp;

void clr() {
    vp.clear(), total.clear();
    memset(tree, 0, sizeof tree);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < sz; i++) {
        x[i].clear();
    }
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = vp[b].S;
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)return tree[node];
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    int p = query(left, b, mid, i, j);
    int q = query(right, mid + 1, e, i, j);
    return max(p, q);
}

void dfs(int u, int distant, int time) {
    cnt++;
    vis[u]++;
    if(distant > now)now = distant, start = u;
    for(auto i : x[u]) {
        if(vis[i] == time) {
            dfs(i, distant + 1, time);
        }
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    scanf("%d", &tc);
    while(tc--) {
        mx_pos = 0;
        clr();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            x[u].push_back(v);
            x[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) { ///This part for finding max_depth for a componant
                now = 1, start = i;
                dfs(i, 1, 0);
                now = 1;
                cnt = 0;
                dfs(start, 1, 1);
                mx_pos = max(mx_pos, cnt);
                vp.push_back({cnt, now});
                total.push_back(cnt);
            }
        }
        vp.push_back({0, 0});
        total.push_back(0);
        sort(vp.begin(), vp.end());
        sort(total.begin(), total.end());
        int range = vp.size() - 1;
        build(1, 1, range);
        scanf("%d", &q);
        printf("Case %d:\n", casee++);
        while(q--) {
            scanf("%d", &k);
            if(k > mx_pos)printf("impossible\n");
            else {
                int id = lower_bound(total.begin(), total.end(), k) - total.begin(); ///All greater element than k;
                int mx = query(1, 1, range, id, range); ///searched maximum possible depth within this range;
                if(k <= mx)printf("%d\n", k - 1);
                else printf("%d\n", mx + ((k - mx) * 2) - 1);
            }
        }
    }

    return 0;
}
