#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
double c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    string name;

    cin >> t;
    cin.ignore();
    for (int i = 0; i <= t; i ++) {
        c = 0;
        m.clear();

        while (true) {
            if (!getline(cin, name) || name == "") break;
            c++;
            m[name]++;
        }

        for (auto it = m.begin(); it != m.end(); it ++) {
            cout << it -> first << ' ' << setprecision(4) << fixed << it -> second / c * 100 << '\n';
        }

        if (i > 0 && i < t) cout << '\n';
    }
}
