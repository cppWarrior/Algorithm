#include <bits/stdc++.h>

using namespace std;

int n;
int a[17000];

vector<int> getNeighbors(int a)
{
    vector<int> ret;
    ret.reserve(n);
    for (int i = 0; i < n; i ++) {
        ret.push_back(a ^ (1 << i));
    }

    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> n) {

        for (int i = 0; i < (1 << n); i ++) {
            cin >> a[i];
        }

        int ans = 0, temp;
        for (int i = 0; i < (1 << n); i ++) {
            temp = a[i];

            for (auto &j: getNeighbors(i)) {
                temp += a[j];
            }

            int temp2 = temp;
            for (auto &j: getNeighbors(i)) {
                for (auto &k: getNeighbors(j)) {
                    if (k != i) {
                        temp += a[k];
                    }
                }
                ans = max(ans, temp);
                temp = temp2;
            }
        }
        cout << ans << '\n';
    }
}
