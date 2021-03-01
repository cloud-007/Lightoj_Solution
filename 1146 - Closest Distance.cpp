/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, casee = 1;
double ax, bx, ay, by, cx, dx, cy, dy;
double unit_ax, unit_ay, unit_bx, unit_by;

double po(double x, double x1) {
    return ((x1 - x) * (x1 - x));
}

double f(double x, double y, double x1, double y1) {
    return sqrt(po(x, x1) + po(y, y1));
}

double ternary_search(double l, double r) {
    double eps = 1e-7;
    while(r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(ax + m1 * unit_ax, ay + m1 * unit_ay, cx + m1 * unit_bx, cy + m1 * unit_by);
        double f2 = f(ax + m2 * unit_ax, ay + m2 * unit_ay, cx + m2 * unit_bx, cy + m2 * unit_by);
        if(f1 > f2)
            l = m1;
        else
            r = m2;
    }
    double ret = min(f(ax + r * unit_ax, ay + r * unit_ay, cx + r * unit_bx, cy + r * unit_by),
                     f(ax + l * unit_ax, ay + l * unit_ay, cx + l * unit_bx, cy + l * unit_by));
    return ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cout << fixed << setprecision(6);
    cin >> tc;
    while(tc--) {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        double len = f(ax, ay, bx, by);
        unit_ax = (bx - ax) / len, unit_ay = (by - ay) / len;
        unit_bx = (dx - cx) / len, unit_by = (dy - cy) / len;
        double ans = ternary_search(0, len);
        cout << "Case " << casee++ << ": " << ans << endl;
    }


    return 0;
}
