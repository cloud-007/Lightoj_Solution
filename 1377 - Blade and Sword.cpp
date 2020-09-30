#include<bits/stdc++.h>
using namespace std;

const int sz = 250;
char c[sz][sz];
int vis[sz][sz], dis[sz][sz], ans = 0, row, col, ptod = 0;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int l, r, dl, dr, ptos = 0, dtos = 0, star = 0, tot;
map < pair < int, int >, int > mp;

bool valid(int tx, int ty) {
    if(tx >= 0 && ty >= 0 && tx < row && ty < col && !vis[tx][ty] && (c[tx][ty] == 'D' || c[tx][ty] == '.'))
        return 1;
    return 0;
}
bool valid1(int tx, int ty) {
    if(tx >= 0 && ty >= 0 && tx < row && ty < col && !vis[tx][ty] && (c[tx][ty] == '*' || c[tx][ty] == '.'))
        return 1;
    return 0;
}
int cnt, cnt1;
void bfs(int sx, int sy, int op, int oo) {
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;
    bool ok = false;
    int des = INT_MAX;
    queue < pair < int, int >> q;
    q.push({sx, sy});
    int res = INT_MAX, res2 = INT_MAX;
    ptos = INT_MAX;
    int p = INT_MAX, qq = INT_MAX;
    while(!q.empty()) {
        sx = q.front().first, sy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i], ty = sy + fy[i];
            if(op) {
                if(valid(tx, ty)) {
                    vis[tx][ty] = 1;
                    q.push({tx, ty});
                    dis[tx][ty] = dis[sx][sy] + 1;
                    if(c[tx][ty] == 'D') {
                        ptod = dis[tx][ty];
                        return ;
                    }
                }
            } else {
                if(valid1(tx, ty)) {
                    vis[tx][ty] = 1;
                    if(c[tx][ty] != '*')
                        q.push({tx, ty});
                    dis[tx][ty] = dis[sx][sy] + 1;
                    if(c[tx][ty] == '*') {
                        if(oo) {
                            if(mp[ {tx, ty}]) {
                                p = min(p, dis[tx][ty] + 1);
                            } else {
                                qq = min(qq, dis[tx][ty]);
                            }
                        } else {
                            if(res == INT_MAX) {
                                cnt++;
                                dtos = dis[tx][ty];
                                res = dis[tx][ty];
                                mp[ {tx, ty}] = 1;
                            } else if(dis[tx][ty] == res) {
                                cnt++;
                                mp[ {tx, ty}] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    if(oo) {
        if(p != INT_MAX && qq != INT_MAX && p >= qq) {
            ptos = qq;
        } else if(p != INT_MAX && qq != INT_MAX && p < qq) {
            if(cnt > 1)
                ptos = p;
            else
                ptos = p + 1;
        } else if(p == INT_MAX && qq != INT_MAX) {
            ptos = qq;
        } else if(p != INT_MAX && qq == INT_MAX) {
            if(cnt > 1)
                ptos = p - 1;
            else
                ptos = p;
        } else
            ptos = 0;
    }
    return;
}


int main() {
    int tc, casee = 1;
    scanf("%d", &tc);
    while(tc--) {
        star = 0;
        mp.clear();
        ptos = 0, dtos = 0, ptod = 0;
        scanf("%d%d", &row, &col);
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        for(int i = 0; i < row; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < s.size(); j++) {
                c[i][j] = s[j];
                if(c[i][j] == 'P') {
                    l = i, r = j;
                } else if(c[i][j] == 'D')
                    dl = i, dr = j;
                else if(c[i][j] == '*')
                    star++, vis[i][j] = 1;
            }
        }
        bfs(l, r, 1, 0);
        if(star > 1) {
            memset(vis, 0, sizeof vis);
            memset(dis, 0, sizeof dis);
            cnt = 0;
            //cout<<dl<<" "<<dr<<endl;
            bfs(dl, dr, 0, 0);
            memset(vis, 0,  sizeof vis);
            memset(dis, 0,  sizeof dis);
            bfs(l, r, 0, 1);
        }
        printf("Case %d: ", casee++);
        tot = 0;
        if(ptos && dtos)
            tot = ptos + dtos + 1;
        if(tot && ptod)
            printf("%d\n", min(tot, ptod));
        else if(tot)
            printf("%d\n", tot);
        else if(ptod)
            printf("%d\n", ptod);
        else
            printf("impossible\n");
    }
}
