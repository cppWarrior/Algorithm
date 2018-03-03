#include <bits/stdc++.h>

using namespace std;

int n;
int a[10002];
int d[10002];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> n) {
        if (n == 0)
        {
            break;
        }

        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i];
        }

        int ans = -1;
        for (int i = 1; i <= n; i ++)
        {
            d[i] = max(d[i - 1] + a[i], a[i]);
            ans = max(ans, d[i]);
        }

        if (ans <= 0) cout << "Losing streak.\n";
        else cout << "The maximum winning streak is " << ans << ".\n";
    }
}
