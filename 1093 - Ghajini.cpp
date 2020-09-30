#include<bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 50;
int a[sz], tree1[sz * 3], tree2[sz * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree1[node] = a[b];
        tree2[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2 ;
    build( left, b, mid );
    build( right, mid + 1, e );
    tree1[node] = max(tree1[left], tree1[right]);
    tree2[node] = min(tree2[left], tree2[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)
        return tree1[node];
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2 ;
    int p = query(left, b, mid, i, j);
    int q = query(right, mid + 1, e, i, j);
    return max(p, q);
}
int query1(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return INT_MAX;
    if(b >= i && e <= j)
        return tree2[node];
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2 ;
    int p1 = query1(left, b, mid, i, j);
    int p2 = query1(right, mid + 1, e, i, j);
    return min(p1, p2);
}

int main() {
    int tc, casee = 1;
    scanf("%d", &tc);
    while(tc--) {
        memset(tree1, 0, sizeof tree1);
        memset(tree2, 0, sizeof tree2);
        int n, d;
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        build(1, 1, n);
        --d;
        int ans = 0;
        for(int i = 1; i + d <= n; i++) {
            int mx = query(1, 1, n, i, i + d);
            int mn = query1(1, 1, n, i, i + d);
            //printf("%d %d\n",mx,mn);
            ans = max(ans, abs(mx - mn));
        }
        printf("Case %d: %d\n", casee++, ans);
    }
}
