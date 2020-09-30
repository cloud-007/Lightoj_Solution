#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define val first
#define id second

int tc, casee = 1, n;
const int sz = 30005;
int a[sz], pos[sz], revpos[sz];

int main() {
    //freopen("in.txt","r",stdin);
    cloud_007;
    cin >> tc;
    while(tc--) {
        stack < pair < int, int >> st;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(st.size() && st.top().val > a[i]) {
                int now = st.top().id;
                while(st.size() && st.top().val > a[i]) {
                    pos[st.top().id] = now;
                    st.pop();
                }
            }
            st.push({a[i], i});
        }
        if(st.size()) {
            int now = st.top().id;
            while(st.size()) {
                pos[st.top().id] = now;
                st.pop();
            }
        }
        for(int i = n; i >= 1; i--) {
            if(st.size() && st.top().val > a[i]) {
                int now = st.top().id;
                while(st.size() && st.top().val > a[i]) {
                    revpos[st.top().id] = now;
                    st.pop();
                }
            }
            st.push({a[i], i});
        }
        if(st.size()) {
            int now = st.top().id;
            while(st.size()) {
                revpos[st.top().id] = now;
                st.pop();
            }
        }
        ll mx = 0;
        for(int i = 1; i <= n; i++) {
            ll ans = (ll)a[i] * (ll)((pos[i] - i + 1) + (i - revpos[i]));
            mx = max(mx, ans);
        }
        cout << "Case " << casee++ << ": " << mx << endl;
    }
}
