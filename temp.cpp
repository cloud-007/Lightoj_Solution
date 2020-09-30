/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n;

bool cmp(string a, string b) {
    if(a.size() == b.size())return a < b;
    return a.size() < b.size();
}

struct node {
    bool endmark;
    node* next[26 + 1];
    node() {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

void insert(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;

    cin >> tc;

    while(tc--) {
        string s;
        root = new node();
        cin >> n;
        bool ok = true;
        vector < string > v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end(), cmp);

        for(auto i : v) {
            string word = "";
            for(auto j : i) {
                word += j;
                if(search(word, word.size())) {
                    ok = false;
                    break;
                }
            }
            insert(i,i.size());
            if(!ok)break;
        }

        if(ok)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
