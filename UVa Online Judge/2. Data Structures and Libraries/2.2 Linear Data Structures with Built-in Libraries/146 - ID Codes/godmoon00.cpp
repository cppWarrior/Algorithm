#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string s;

    while (true) {
        cin >> s;
        if (s == "#") break;

        if (next_permutation(s.begin(), s.end())) {
            cout << s << '\n';
        }
        else {
            cout << "No Successor\n";
        }
    }
}
