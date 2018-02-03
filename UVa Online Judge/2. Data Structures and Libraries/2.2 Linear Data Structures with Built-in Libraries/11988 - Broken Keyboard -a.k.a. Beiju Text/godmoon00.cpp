#include <bits/stdc++.h>

using namespace std;

list<char> li;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string s;
    while (getline(cin, s)) {
        li.clear();

        auto it = li.begin();
        for (auto &c: s) {
            if (c == '[') {
                it = li.begin();
            }
            else if (c == ']') {
                it = li.end();
            }
            else {
                it = li.insert(it, c);
                it++;
            }
        }

        for (auto&c : li) {
            cout << c;
        }
        cout << '\n';
    }
}
