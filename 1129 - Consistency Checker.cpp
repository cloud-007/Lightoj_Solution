/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, casee = 1;

struct node {
    bool endmark;
    node* next[10];
    node() {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} * root;

bool insert(string str, int len) {
    bool ok = true;
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node(), ok = false;
        curr = curr->next[id];
    }
    curr->endmark = true;
    return ok;
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
    for (int i = 0; i < 10; i++)
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
        for(int i = 0; i < n; i++) {
            cin >> s;
            string word = "";
            for(auto j : s) {
                word += j;
                if(search(word, word.size())) {
                    ok = false;
                }
            }
            if(insert(s, s.size()))ok = false;
        }
        cout << "Case " << casee++ << ": ";
        if(ok)cout << "YES" << endl;
        else cout << "NO" << endl;
        del(root);
    }

    return 0;
}
