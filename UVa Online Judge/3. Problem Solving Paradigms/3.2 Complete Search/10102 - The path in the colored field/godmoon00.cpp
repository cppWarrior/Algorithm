#include <bits/stdc++.h>

using namespace std;

int m;
char a[1001][1001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> m) {
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                cin >> a[i][j];
            }
        }

        int maxDist = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i][j] == '1') {
                    int minDist = 10000;
                    for (int k = 0; k < m; k ++) {
                        for (int l = 0; l < m; l ++) {
                            if (a[k][l] == '3') {
                                int dist = abs(i - k) + abs(j - l);
                                minDist = min(minDist, dist);
                            }
                        }
                    }
                    maxDist = max(minDist, maxDist);
                }
            }
        }

        cout << maxDist << '\n';
    }
}
