#include <bits/stdc++.h>

using namespace std;

int n, k;
bool colored[101];
vector<int> ans;
vector<int> v[101];

void go(int now, vector<int>& temp)
{
    if (now > n) {
        if (temp.size() > ans.size()) {
            ans = temp;
        }
        return;
    }

    bool canColor = true;
    for (auto& j: v[now]) {
        if (colored[j]) {
            canColor = false;
            break;
        }
    }

    if (canColor) {
        temp.push_back(now);
        colored[now] = true;
        go(now + 1, temp);
        temp.pop_back();
        colored[now] = false;
    }

    go(now + 1, temp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int m;
    cin >> m;
    while (m--) {
        ans.clear();
        memset(colored, false, sizeof(colored));
        memset(check, false, sizeof(check));
        for (int i = 1; i <= 100; i++) v[i].clear();

        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        vector<int> temp;
        go(1, temp);

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i ++) {
            if (i > 0) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';

    }
}
