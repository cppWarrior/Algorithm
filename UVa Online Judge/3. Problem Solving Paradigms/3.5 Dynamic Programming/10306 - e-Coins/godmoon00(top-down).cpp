#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int dp[301][301];
bool check[301][301];
vector<pair<int, int>> v[301];
vector<pair<int, int>> coins;
int m, s;

void initVector()
{
    int x, y;
    for (int i = 1; i <= 300; i ++)
    {
        for (int j = 0; j <= i; j ++)
        {
            x = j * j;
            for (int k = 0; k <= i; k ++) {
                y = k * k;

                if (x + y == i * i) {
                    v[i].emplace_back(j, k);
                }
            }
        }
    }
}

int go(int x, int y)
{
    if (x == 0 && y == 0) return 0;
    if (check[x][y]) return dp[x][y];

    int& ret = dp[x][y];
    for (auto& i: coins)
    {
        if (x - i.first >= 0 && y - i.second >= 0) {
            ret = min(go(x - i.first, y - i.second) + 1, ret);
        }
    }
    check[x][y] = true;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    initVector();

    int n;
    cin >> n;
    while (n--)
    {
        coins.clear();
        fill_n(*dp, 301 * 301, INF);
        memset(check, false, sizeof(check));

        cin >> m >> s;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            coins.emplace_back(x, y);
        }

        int ans = INF;
        for (auto& i: v[s])
        {
            ans = min(ans, go(i.first, i.second));
        }

        if (ans == INF) {
            cout << "not possible\n";
        }
        else {
            cout << ans << '\n';
        }
    }
}
