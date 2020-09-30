#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc, casee = 1;
    scanf("%d", &tc);
    vector < pair < int, int >> vp;
    map < int, int > mp, go;
    set < int > st;
    while(tc--) {
        vp.clear();
        mp.clear();
        go.clear();
        st.clear();
        int q;
        scanf("%d", &q);
        int n = q;
        while(q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            vp.push_back({l, r});
        }
        reverse(vp.begin(), vp.end());
        int x = n;
        for(auto i : vp) {
            int l = i.first, r = i.second;
            while(l <= r) {
                if(go[l]) {
                    l = go[l];
                } else
                    mp[l] = x, go[l] = r;
                l++;
            }
            x--;
        }
        for(int i = 1; i <= n * 2; i++) {
            if(mp[i])
                st.insert(mp[i]);
        }
        printf("Case %d: %d\n", casee++, st.size());
    }
}
