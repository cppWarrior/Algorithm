#include <bits/stdc++.h>

using namespace std;

int s, b;
int LEFT[100002];
int RIGHT[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (true) {
        cin >> s >> b;
        if (s == 0 && b == 0) break;

        for (int i = 1; i <= s; i++) {
            LEFT[i] = i - 1;
            RIGHT[i] = i + 1;
        }

        while (b--) {
            int l, r, lm, rm;
            cin >> l >> r;

            if (LEFT[l] == 0) cout << "* ";
            else cout << LEFT[l] << ' ';
            if (RIGHT[r] == s + 1) cout << "*\n";
            else cout << RIGHT[r] << '\n';

            LEFT[RIGHT[r]] = LEFT[l];
            RIGHT[LEFT[l]] = RIGHT[r];
        }
        cout << "-\n";

    }
}
