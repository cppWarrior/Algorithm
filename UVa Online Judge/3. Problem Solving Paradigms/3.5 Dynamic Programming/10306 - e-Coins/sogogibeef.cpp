// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>

#include "/Users/jeongminlim/stdc++.h"

using namespace std;
// sqrt(x * x + y * y)
// find amount of ecoin to get given emodulus.

int n, m, s;
int x, y, ans;
int dp[350][350];


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;
    while (n--) {
        cin >> m >> s;
        memset(dp, 0, sizeof(dp));
        x = 0;
        y = 0;
        ans = 1 << 24;


        for (int i = 0; i < s + 1; i++) {
            for (int j = 0; j < s + 1; j++) {
                dp[i][j] = 1 << 24;
            }
        }

        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            for (int j = x; j < s + 1; j++) {
                for (int k = y; k < s + 1; k++) {
                    dp[j][k] = min(dp[j][k], dp[j - x][k - y] + 1);
                }
            }
        }


        for (int i = 0; i < s + 1; i++) {
            for (int j = 0; j < s + 1; j++) {
                if (i * i + j * j == s * s) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }

        if (ans >= 1 << 24) {
            cout << "not possible\n";
        } else {
            cout << ans << "\n";
        }


    }


    return 0;
}





