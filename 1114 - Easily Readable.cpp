/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, casee = 1, n, m, ans;
string s, x, y;

unordered_map < string, int > mp;

void work(string str) {
    stringstream s(str);
    string word, y = "";

    int count = 0;
    while(s >> word) {
        if(word.size() > 2)sort(word.begin() + 1, word.begin() + (word.size() - 1));
        ans *= mp[word];
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    //cloud_007;
    cin >> tc;
    while(tc--) {
        mp.clear();
        cin >> n;
        while(n--) {
            cin >> s;
            if(s.size() > 2) {
                sort(s.begin() + 1, s.begin() + (s.size() - 1));
            }
            mp[s]++;
        }
        cin >> m;
        cout << "Case " << casee++ << ":" << endl;
        cin.ignore();
        while(m--) {
            getline(cin, s);
            ans = 1;
            work(s);
            cout << ans << endl;
        }
    }

    return 0;
}
