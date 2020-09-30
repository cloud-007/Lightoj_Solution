#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int sz = 1e8 + 50;
int main() {
    vector < int > a, b;
    int tc, casee = 1;
    scanf("%d", &tc);
    while(tc--) {
        a.clear(), b.clear();
        int q, n, l, r;
        scanf("%d%d", &q, &n);
        while(q--) {
            scanf("%d%d", &l, &r);
            if(r < l)
                swap(l, r);
            a.push_back(l);
            b.push_back(r);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        printf("Case %d:\n", casee++);
        for(int i = 0; i < n; i++) {
            scanf("%d", &l);
            int x = upper_bound(a.begin(), a.end(), l) - a.begin();
            int y = lower_bound(b.begin(), b.end(), l) - b.begin();
            printf("%d\n", abs(x - y));
        }
    }
}
