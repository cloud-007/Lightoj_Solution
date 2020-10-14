/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int tc, n, casee = 1, done = 1;
char s[51];
int ans = 0;

int mp[125];

struct node {
    bool endmark;
    node* next[4];
    int cnt = 0;
    node() {
        endmark = false;
        for (int i = 0; i < 4; i++)
            next[i] = NULL;
    }
} * root;

void insert(char* str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = mp[str[i]];
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
        //cout << str[i] << " " << curr->cnt << endl;
        ans = max(ans, (curr->cnt * (i + 1)));
    }
    curr->endmark = true;
}

bool search(string str, int len) {
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = mp[str[i]];
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur) {
    for (int i = 0; i < 4; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    //cloud_007;
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
    scanf("%d",&tc);
    while(tc--) {
        ans = 0;
        root = new node();
        scanf("%d",&n);
        while(n--) {
            scanf("%s",s);
            insert(s, strlen(s));
        }
        printf("Case %d: %d\n",casee++, ans);
        del(root);
    }

    return 0;
}
