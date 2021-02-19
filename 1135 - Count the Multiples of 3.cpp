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
int tc, n, q, casee = 1;

struct R {
    int prop, val[3];
} tree[sz * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].val[0] = 1;
        tree[node].val[1] = tree[node].val[2] = tree[node].prop = 0;
        return;
    }
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    for(int i = 0; i < 3; i++)tree[node].val[i] = tree[left].val[i] + tree[right].val[i];
    tree[node].prop = 0;
}

void propagate(int node, int b, int e) {
    if(!tree[node].prop)return;
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    if(tree[node].prop == 1) {
        tree[node].val[2] = tree[node].val[1];
        tree[node].val[1] = tree[node].val[0];
        tree[node].val[0] = (e - b + 1) - (tree[node].val[1] + tree[node].val[2]);
    } else {
        tree[node].val[1] = tree[node].val[2];
        tree[node].val[2] = tree[node].val[0];
        tree[node].val[0] = (e - b + 1) - (tree[node].val[1] + tree[node].val[2]);
    }
    if(b != e) {
        tree[left].prop += tree[node].prop;
        tree[right].prop += tree[node].prop;
        tree[left].prop %= 3;
        tree[right].prop %= 3;
    }
    tree[node].prop = 0;
}

void update(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if(b > j || e < i)return;
    if(b >= i && e <= j) {
        tree[node].prop++;
        propagate(node, b, e);
        return;
    }
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);
    for(int i = 0; i < 3; i++)tree[node].val[i] = tree[left].val[i] + tree[right].val[i];
}

int query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if(b > j || e < i)return 0;
    if(b >= i && e <= j)return tree[node].val[0];
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    int p = query(left, b, mid, i, j);
    int q = query(right, mid + 1, e, i, j);
    return p + q;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n >> q;
        build(1, 1, n);
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int ty, u, v;
            cin >> ty >> u >> v;
            if(!ty)update(1, 1, n, ++u, ++v);
            else cout << query(1, 1, n, ++u, ++v) << endl;
        }
    }


    return 0;
}
