#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz = 1e5 + 50;
int a[sz];
int tree[sz * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int i, int newvalue) {
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        if(newvalue == 0)
            tree[node] = 0;
        else
            tree[node] += newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j) {
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j) {
        return tree[node];
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, min(j, mid));
    int p2 = query(Right, mid + 1, e, max(i, mid + 1), j);
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        printf("Case %d:\n", casee++);
        while(m--) {
            int x;
            cin >> x;
            if(x == 1) {
                int c;
                cin >> c;
                c++;
                printf("%d\n", query(1, 1, n, c, c));
                update(1, 1, n, c, 0);
            } else if(x == 2) {
                int u, v;
                cin >> u >> v;
                u++;
                update(1, 1, n, u, v);
            } else {
                int u, v;
                cin >> u >> v;
                u++, v++;
                printf("%d\n", query(1, 1, n, u, v));
            }
        }
    }
}
