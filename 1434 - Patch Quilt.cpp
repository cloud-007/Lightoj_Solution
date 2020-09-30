#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second

const int sz = 32;
int tc, casee = 1, row, col, vis[sz][sz], q, done;
char a[sz][sz];
map < char, vector < pair < int, int>>> mp;
map < pair < int, int >, string > change;
vector < pair < int, int >> vp;
string name, temp;

void clr() {
    mp.clear(), change.clear();
    change[ {0, 1}] = ", R";
    change[ {0, -1}] = ", L";
    change[ {1, 0}] = ", D";
    change[ {-1, 0}] = ", U";
    change[ {1, 1}] = ", DR";
    change[ {1, -1}] = ", DL";
    change[ {-1, 1}] = ", UR";
    change[ {-1, -1}] = ", UL";
    change[ {0, 0}] = ", *";
}

int fx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int tx, int ty) {
    if(tx >= 1 && ty >= 1 && tx <= row && ty <= col)return true;
    return false;
}

void dfs(int sx, int sy, int cnt, int req) {
    if(done)return;
    if((int)vp.size() == req) {
        done = 1;
        return;
    }
    int ok = 1;
    if(a[sx][sy] == name[cnt]) {
        vp.push_back({sx, sy});
        dfs(sx, sy, cnt + 1, req);
        if(!done)
            vp.pop_back();
    }
    for(int i = 0; i < 8; i++) {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(!done && valid(tx, ty) && a[tx][ty] == name[cnt]) {
            ok = 0;
            vp.push_back({tx, ty});
            dfs(tx, ty, cnt + 1, req);
            if(!done)
                vp.pop_back();
        }
    }
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        clr();
        cin >> row >> col;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> a[i][j];
                mp[a[i][j]].push_back({i, j});
            }
        }
        cin >> q;
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            string ans = "";
            cin >> name;
            bool ok = true;
            for(auto i : name) {
                if(!mp[i].size()) {
                    ok = false;
                    break;
                }
            }
            if(!ok) {
                cout << name << " not found" << endl;
                continue;
            }
            for(auto i : mp[name[0]]) {
                //cout<<i.F<<" "<<i.S<<endl;
                vp.clear();
                done = 0;
                temp = "";
                vp.push_back({i.F, i.S});
                dfs(i.F, i.S, 1, (int)name.size());
                //cout<<"PRINTING"<<endl;
                //for(auto i : vp)
                //    cout<<i.F<<" "<<i.S<<endl;
                if(done) {
                    ans += "(";
                    ans += to_string(i.F);
                    ans += ",";
                    ans += to_string(i.S);
                    ans += ")";
                    for(int i = 0; i < vp.size() - 1; i++) {
                        int x = vp[i + 1].F - vp[i].F, y = vp[i + 1].S - vp[i].S;
                        temp += change[ {x, y}];
                    }
                    ans += temp;
                    cout << name << " found: " << ans << endl;
                    break;
                }
            }
            if(!done)cout << name << " not found" << endl;
        }
    }

    return 0;
}
