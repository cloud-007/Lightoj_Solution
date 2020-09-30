#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz = 1e5 + 50;
struct info {
    ll sum, prop;
} tree[sz * 3];

void murobbi() {
    for(int i = 0; i <= sz * 3; i++)
        tree[i].sum = tree[i].prop = 0;
}

void update(int node, int b, int e, int i, int j, ll x) {
    if(i > e || j < b)
        return ;
    if(b >= i && e <= j) {
        tree[node].sum += (abs(b - e) + 1) * x;
        tree[node].prop += x;
        return;
    }
    int left = node << 1;
    int right = left + 1 ;
    int mid = ( b + e ) >> 1;
    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (abs(b - e) + 1);
}

ll query(int node, int b, int e, int i, int j,  ll carry = 0) {
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)
        return tree[node].sum + carry * (abs(b - e) + 1);
    int left = node << 1;
    int right = left + 1;
    int mid = ( b + e ) >> 1;
    ll p = query(left, b, mid, i, j, carry + tree[node].prop);
    ll q = query(right, mid + 1, e, i, j, carry + tree[node].prop);
    return p + q;
}

int main() {
    int tc, casee = 1;
    scanf("%d", &tc);
    while(tc--) {
        printf("Case %d:\n", casee++);
        int n, q;
        scanf("%d%d", &n, &q);
        murobbi();
        while(q--) {
            int t, x, y, v;
            scanf("%d%d%d", &t, &x, &y);
            x++, y++;
            if(t)
                printf("%lld\n", query(1, 1, n, x, y));
            else
                scanf("%d", &v), update(1, 1, n, x, y, v);
        }
    }
}
