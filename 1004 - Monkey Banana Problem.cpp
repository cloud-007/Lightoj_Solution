#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tc, casee = 1;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        int a[n * 2 + 50][n * 2 + 50], k = 0, i;
        memset(a, 0, sizeof a);
        for(i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                cin >> a[i][j];
                if(i > 0 && j == 0) {
                    a[i][j] += a[i - 1][j];
                } else if(i > 0 && j == k) {
                    a[i][j] += a[i - 1][j - 1];
                } else if(i > 0)
                    a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
            }
            k++;
        }
        int c = n - 1;
        for(i = n; i < n * 2 - 1; i++) {
            for(int j = 0; j < c; j++) {
                cin >> a[i][j];
                a[i][j] += max(a[i - 1][j], a[i - 1][j + 1]);
            }
            c--;
        }
        printf("Case %d: %d\n", casee++, a[n * 2 - 2][0]);
    }
}
