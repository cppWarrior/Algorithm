#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> n) {
        set<int> s;
        for (int i = 0; i < n; i ++) {
            int temp;
            cin >> temp;
            s.insert(temp);
        }

        cin >> m;

        int a1 = 0, a2 = 10000000;
        for (auto it = s.begin(); it != s.end(); it ++) {
            if (s.find(m - *it) != s.end() && *it <= m - *it) {
                a1 = max(a1, *it);
                a2 = min(a2, m - *it);
            }
        }
        cout << "Peter should buy books whose prices are " << a1 << " and " << a2 << ".\n\n";
    }
}
