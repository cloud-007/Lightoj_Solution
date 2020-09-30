#include<bits/stdc++.h>
using namespace std;
const int sz = 1050;
char a[sz][sz];
int fin[sz][sz];
int c = 0, row, col, q;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
map < pair < int, int >, int > vis;
vector < pair < int, int > > vp;

void bfs(int sx, int sy) {
    vis[ {sx, sy}] = 1;
    queue< pair < int, int > > q;
    q.push({sx, sy});
    vp.push_back({sx, sy});
    while(!q.empty()) {
        for(int i = 0; i < 4; i++) {
            int tx = q.front().first, ty = q.front().second;
            tx += fx[i], ty += fy[i];
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && a[tx][ty] != '#' && !vis[ {tx, ty}]) {
                vis[ {tx, ty}] = 1;
                vp.push_back({tx, ty});
                if(a[tx][ty] == 'C')
                    c++;
                q.push({tx, ty});
            }
        }
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        memset(fin, 0, sizeof fin);
        vis.clear();
        int cnt = 0;
        cin >> row >> col >> q;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                cin >> a[i][j];
                if(a[i][j] == 'C')
                    cnt++;
            }
        printf("Case %d:\n", casee++);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if(a[i][j] == '.' && !vis[ {i, j}]) {
                    c = 0;
                    vp.clear();
                    bfs(i, j);
                    for(auto k : vp) {
                        fin[k.first][k.second] = c;
                    }
                }
            }
        while(q--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            printf("%d\n", fin[u][v]);
        }
    }
}
