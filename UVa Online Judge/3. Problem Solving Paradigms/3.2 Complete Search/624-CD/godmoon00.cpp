#include <bits/stdc++.h>

using namespace std;

int d, n, ans;
vector<int> v, temp;
int a[21];

void go(int i, int sum)
{

    if (sum > d) return;

    if (i == n) {

        if (ans < sum) {

            ans = sum;
            v = temp;

        }
        return;

    }

    temp.push_back(a[i]);
    go(i + 1, sum + a[i]);

    temp.pop_back();
    go(i + 1, sum);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> d >> n)
    {

        for (int i = 0; i < n; i++) {

            cin >> a[i];

        }

        v.clear();
        temp.clear();
        ans = 0;

        go(0, 0);

        for (auto &i: v) {

            cout << i << ' ';

        }

        cout << "sum:" << ans << '\n';

    }
}
