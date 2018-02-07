#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (true) {
        cin >> n;
        if (n == 0) break;

        bool check = true;
        while (check) {
            for (int i = 0; i < n; i ++) {
                cin >> a[i];
                if (a[i] == 0) {
                    check = false;
                    break;
                }
            }

            if (check) {
                int now = 1;
                stack<int> s;
                bool ans = true;

                for (int i = 0; i < n; i++) {
                    if (now == a[i]) now ++;
                    else if (!s.empty() && s.top() == a[i]) s.pop();
                    else {
                        while (now != a[i] && now <= n) {
                            s.push(now);
                            now ++;
                        }
                        if (now == a[i]) now ++;
                    }
                }

                if (s.empty()) cout << "Yes\n";
                else cout << "No\n";
            }
        }
        cout << '\n';
    }
}
