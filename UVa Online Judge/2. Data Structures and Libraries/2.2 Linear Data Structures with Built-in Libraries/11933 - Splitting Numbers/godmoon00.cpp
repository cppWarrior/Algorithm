#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> n) {
        if (n == 0) break;
        int a = 0, b = 0;

        while (n > 0) {
            a |= (n & (-n));
            n &= ~ (n & (-n));
            b |= (n & (-n));
            n &= ~ (n & (-n));
        }
        cout << a << ' ' << b << '\n';
    }
}
