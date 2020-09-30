#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<pair < int, int >, null_type, less<pair < int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

int tc, n, q, a, cnt, casee = 1;
char c;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // cloud_007
    ordered_set os;
    pair < int, int > t;
    scanf("%d", &tc);
    while(tc--) {
        os.clear();
        scanf("%d%d", &n, &q);
        cnt = n;
        for(int i = 0; i < n; i++) {
            cin >> a;
            os.insert({i, a});
        }
        printf("Case %d:\n", casee++);
        while(q--) {
            while(scanf("%c", &c)) {
                if(isalpha(c))
                    break;
            }
            scanf("%d", &a);
            if(c == 'a')
                os.insert({cnt, a}), cnt++;
            else {
                a--;
                if(a >= os.size()) {
                    printf("none\n");
                    continue;
                }
                t = *os.find_by_order(a);
                os.erase(t);
                printf("%d\n", t.second);
            }
        }
    }

    return 0;
}
