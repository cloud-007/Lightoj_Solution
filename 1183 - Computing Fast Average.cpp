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
int tc, n, m, ty, u, v, val, casee = 1;

struct R {
    int prop, sum;
} tree[sz * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].sum = tree[node].prop = 0;
        return;
    }
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].prop = tree[node].sum = 0;
}

void propagate(int node, int b, int e) {
    if(tree[node].prop == -1)return;
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    tree[node].sum = (e - b + 1) * tree[node].prop;
    if(b != e) {
        if(left < sz * 3)tree[left].prop = tree[node].prop;
        if(right < sz * 3)tree[right].prop = tree[node].prop;
    }
    tree[node].prop = -1;
}

void update(int node, int b, int e, int i, int j, int val) {
    propagate(node, b, e);
    if(b > j || e < i)return;
    if(b >= i && e <= j) {
        tree[node].prop = val;
        propagate(node, b, e);
        return;
    }
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if(b > j || e < i)return 0;
    if(b >= i && e <= j)return tree[node].sum;
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
        cin >> n >> m;
        build(1, 1, n);
        cout << "Case " << casee++ << ":" << endl;
        while(m--) {
            cin >> ty >> u >> v;
            if(ty == 1) {
                cin >> val;
                update(1, 1, n, ++u, ++v, val);
            } else {
                int sum = query(1, 1, n, ++u, ++v);
                int tot = v - u + 1;
                int gcd = __gcd(sum, tot);
                sum /= gcd, tot /= gcd;
                if(sum % tot == 0)cout << sum / tot << endl;
                else cout << sum << "/" << tot << endl;
            }
        }
    }


    return 0;
}
