#include<bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 50;
int k, ans[sz], a[sz];
int mp[sz], cnt;

struct query {
    int index, l, r;
    bool operator< (const query &other)const {
        int block_own = l / k;
        int block_other = other.l / k;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} q[sz];

void add(int idx) {
    if(!mp[a[idx]])
        cnt++;
    mp[a[idx]]++;
}

void remove(int idx) {
    mp[a[idx]]--;
    if(!mp[a[idx]])
        cnt--;
}

int main() {
    int tc, casee = 1;
    scanf("%d", &tc);
    while(tc--) {

        int n, m;
        scanf("%d%d", &n, &m);
        k = sqrt(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].l--, q[i].r--;
            q[i].index = i;
        }
        sort(q, q + m);
        int l = 0, r = -1;
        memset(mp, 0, sizeof mp);
        memset(ans, 0, sizeof ans);
        cnt = 0;
        for(int i = 0; i < m; i++) {
            while(r < q[i].r)
                add(++r);
            while(l < q[i].l)
                remove(l++);
            while(r > q[i].r)
                remove(r--);
            while(l > q[i].l)
                add(--l);
            ans[q[i].index] = cnt;
        }
        printf("Case %d:\n", casee++);
        for(int i = 0; i < m; i++)
            printf("%d\n", ans[i]);
    }
}
