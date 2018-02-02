#include <bits/stdc++.h>

using namespace std;

int a[3001];
bool check[3001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    bool ans;

    while (cin >> n) {
        memset(check, false, sizeof(check));
        ans = true;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i < n; i++) {
            int diff = abs(a[i] - a[i - 1]);
            check[diff] = true;
        }

        for (int i = 1; i < n; i++) {
            if(!check[i]) ans = false;
        }

        if (ans) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
}
