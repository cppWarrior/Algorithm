#include <bits/stdc++.h>

using namespace std;

int p, q, r, s, t, u;

double fx(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> p >> q >> r >> s >> t >> u) {
        double low = 0, high = 1, mid;

        if (fx(0) * fx(1) > 0) {
            cout << "No solution\n";
        }

        else {
            for (int i = 0; i < 50; i++) {
                mid = (low + high) / 2;
                double result = fx(mid);

                if (result < 1e-9 && result > -1e-9) {
                    cout << fixed << setprecision(4) << mid << '\n';
                    break;
                }
                else if (result > 0) {
                    low = mid;
                }
                else {
                    high = mid;
                }
            }
        }
    }
}
