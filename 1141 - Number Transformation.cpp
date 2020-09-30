#include<bits/stdc++.h>
using namespace std;

const int sz = 1005;
vector < int > prime;
map < int, int > mp;
vector < int > x[sz];
int mark[sz];

void sieve() {
    int i, j, limit = 42;
    prime.push_back(2);
    mp[2] = 1;
    for(i = 3; i <= limit; i += 2)
        if(!mark[i]) {
            prime.push_back(i);
            mp[i] = 1;
            if(i <= limit) {
                for(j = i * i; j <= sz; j += i * 2)
                    mark[j] = i;
            }
        }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a >> b;
        map < int, int > dis, v;
        queue < int > q;
        dis.clear();
        v.clear();
        while(!q.empty())
            q.pop();
        q.push(a);
        dis[a] = 0;
        v[a] = 1;
        int c = INT_MAX;
        bool fl = false;
        while(!q.empty()) {
            int now = q.front();
            if(now == b) {
                c = dis[now];
                break;
            }
            int s = now;
            vector < int > pos;
            for(int i = 0; i < 13; i++) {
                int j = prime[i];
                if(s % j == 0 && now != prime[i] && now + prime[i] <= b && !v[now + prime[i]]) {
                    q.push(now + j);
                    dis[now + prime[i]] = dis[now] + 1;
                    v[now + prime[i]] = 1;
                }
                while(s % j == 0)
                    s /= j;
            }
            if(s > 1 && s != now && now + s <= b && !v[now + s]) {
                q.push(now + s);
                v[now + s] = 1;
                dis[now + s] = dis[now] + 1;
            }
            q.pop();
        }
        if(c != INT_MAX)
            printf("Case %d: %d\n", casee++, c);
        else
            printf("Case %d: -1\n", casee++);
    }
}
