#include<bits/stdc++.h>
using namespace std;

const int sz = 300;
int row, col;
map < pair < int, int >, int > visf, visj, dis;
int a[sz][sz];
queue < pair < int, int > > fire, jane ;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int bfs() {
    if(jane.front().first == 0 || jane.front().first == row - 1 || jane.front().second == 0 || jane.front().second == col - 1)
        return 1;
    queue < pair < int, int > > tj, tf;
    while(!jane.empty()) {
        while(!fire.empty()) {
            pair < int, int > top = fire.front();
            fire.pop();
            for(int i = 0; i < 4; i++) {
                int tx = top.first + fx[i];
                int ty = top.second + fy[i];
                if(tx >= 0 && tx < row && ty >= 0 && ty < col && a[tx][ty] != -1 && !visf[ {tx, ty}] ) {
                    visf[ {tx, ty}] = 1;
                    tf.push({tx, ty});
                }
            }
        }
        while(!tf.empty()) {
            fire.push({tf.front().first, tf.front().second});
            tf.pop();
        }
        while(!jane.empty()) {
            pair < int, int > top = jane.front();
            jane.pop();
            for(int i = 0; i < 4; i++) {
                int tx = top.first + fx[i];
                int ty = top.second + fy[i];
                if(tx >= 0 && tx < row && ty >= 0 && ty < col && a[tx][ty] != -1 && !visf[ {tx, ty}] && !visj[ {tx, ty}]) {
                    visj[ {tx, ty}] = 1;
                    dis[ {tx, ty}] = dis[ {top.first, top.second}] + 1;
                    if(tx == 0 || tx == row - 1 || ty == 0 || ty == col - 1)
                        return dis[ {tx, ty}];
                    tj.push({tx, ty});
                }
            }
        }
        while(!tj.empty()) {
            jane.push({tj.front().first, tj.front().second});
            tj.pop();
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        dis.clear();
        visf.clear();
        visj.clear();
        while(!fire.empty())
            fire.pop();
        while(!jane.empty())
            jane.pop();
        cin >> row >> col;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                char c;
                cin >> c;
                if(c == 'F') {
                    fire.push({i, j});
                    a[i][j] = 1;
                    visf[ {i, j}] = 1;
                } else if(c == 'J') {
                    jane.push({i, j});
                    visj[ {i, j}] = 1;
                    a[i][j] = 1;
                    dis[ {i, j}] = 1;
                } else if(c == '.')
                    a[i][j] = 1;
                else
                    a[i][j] = -1;
            }
        }
        int ans = bfs();
        if(ans) {
            printf("Case %d: %d\n", casee++, ans);
        } else
            printf("Case %d: IMPOSSIBLE\n", casee++);
    }
}
