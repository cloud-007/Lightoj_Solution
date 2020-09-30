#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz = 1e5 + 50;
int a[sz], tree[sz * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return 1e7; ///outside;
    if(b >= i && e <= j)
        return tree[node];///relevant ;
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return min(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        printf("Case %d:\n", casee++);
        while(q--) {
            int u, v;
            cin >> u >> v;
            printf("%d\n", query(1, 1, n, u, v));
        }
    }
}
