#include <bits/stdc++.h>

using namespace std;

int a[5001];
int b[5001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i ++)
        {
            cin >> a[i];
        }

        for (int i = 1; i < m; i ++)
        {
            int cnt = 0;
            for (int j = 0; j < i; j ++)
            {
                if (a[i] >= a[j]) cnt ++;
            }
            b[i] = cnt;
        }

        int ans = 0;
        for (int i = 1; i < m; i ++)
        {
            ans += b[i];
        }

        cout << ans << '\n';
    }
}
