// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int p, q, r, s, t, u;
double mid;
double EPS = 1e-7;


double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection(double lo, double hi) {
    while (fabs(hi - lo) > EPS) {
        mid = (lo + hi) / 2;
        if (f(lo) * f(mid) <= 0) {
            /*
             * f(lo) 는 양수, f(hi)는 음수
             * 해는 f(x) = 0 일때의 x 값
             * f(lo) * f(mid) < 0 이면 해가 lo 와 mid 사이에 있음
             * hi = mid
             */
            hi = mid;
        } else {
            lo = mid;
        }

    }
    return (lo + hi) / 2;

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0) * f(1) > 0) {
            cout << "No solution\n";
        } else {
            cout << setprecision(4) << fixed << bisection(0, 1) << "\n";
        }

    }


    return 0;
}





