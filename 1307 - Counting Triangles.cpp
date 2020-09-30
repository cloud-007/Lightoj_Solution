#include<bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 50;
int n, cnt = 0;
vector < int > v;


int solve(vector < int > a, int n) {
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int k = n - 1;
            while (k > j && a[k] >= a[i] + a[j]) {
                k--;
            }
            ans += max(k - j, 0);
        }
    }

    return ans;
}


int main() {
    int tc, casee = 1;
    scanf("%d", &tc);
    while(tc--) {
        v.clear();
        scanf("%d", &n);
        int a;
        cnt = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &a), v.push_back(a);
        printf("Case %d: %d\n", casee++, solve(v, n));
    }
}
