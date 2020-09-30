#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

deque < char > v;
char a[20][20];
map < pair < int, int >, int > dis, vis, mp;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int row, col;
int running;

int bfs(int sx, int sy, int dx, int dy) {
    vis[ {sx, sy}] = 1;
    queue<pii>q;
    q.push(pii(sx, sy));
    dis[ {sx, sy}] = 0;
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(tx >= 0 and tx<row and ty >= 0 and ty < col and mp[ {tx, ty}] != -1 and vis[ {tx, ty}] == 0) {
                int fc = a[tx][ty];
                if(fc > running)
                    continue;
                vis[ {tx, ty}] = 1;
                dis[ {tx, ty}] = dis[ {top.first, top.second}] + 1;
                q.push(pii(tx, ty));
                if(tx == dx && ty == dy)
                    return dis[ {tx, ty}];
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, casee = 1;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        row = x, col = x;
        v.clear();
        int c, d, z = 0;
        mp.clear();
        deque < pair < int, pair < int, int >>> vp;
        for(int i = 0; i < x; i++)
            for(int j = 0; j < x; j++) {
                cin >> a[i][j];
                if(isalpha(a[i][j])) {
                    vp.push_back({a[i][j], {i, j}});
                }
                if(a[i][j] == '#')
                    mp[ {i, j}] = -1;
                else
                    mp[ {i, j}] = 1;
            }
        sort(vp.begin(), vp.end());
        int prevx = vp.front().second.first, prevy = vp.front().second.second;
        vp.pop_front();
        bool fl = true;
        int nnn, tot = 0;
        while(!vp.empty()) {
            dis.clear();
            vis.clear();
            int nowx = vp.front().second.first, nowy = vp.front().second.second;
            running = vp.front().first;
            nnn = bfs(prevx, prevy, nowx, nowy);
            if(nnn == -1) {
                cout << "Case " << casee++ << ": Impossible" << endl;
                fl = false;
                break;
            }
            tot += nnn;
            prevx = vp.front().second.first, prevy = vp.front().second.second;
            vp.pop_front();
        }
        if(fl)
            cout << "Case " << casee++ << ": " << tot << endl;
    }
}
