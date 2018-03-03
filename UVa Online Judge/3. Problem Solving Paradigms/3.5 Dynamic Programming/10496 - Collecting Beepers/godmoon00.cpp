#include <bits/stdc++.h>

using namespace std;

int x, y, sx, sy;
vector<pair<int, int>> v;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        cin >> x >> y >> sx >> sy;
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++)
        {
            int a, b;
            cin >> a >> b;
            v.emplace_back(a, b);
        }

        sort(v.begin(), v.end());

        int nowx = sx, nowy = sy;
        int ans = 10000000;
        do
        {
            int temp = 0;
            for (auto& i: v)
            {
                temp += abs(nowx - i.first) + abs(nowy - i.second);
                nowx = i.first;
                nowy = i.second;
            }
            temp += abs(sx - nowx) + abs(sy - nowy);
            nowx = sx;
            nowy = sy;
            ans = min(ans, temp);
        }
        while (next_permutation(v.begin(), v.end()));

        cout << "The shortest path has length " << ans << '\n';
    }
}
