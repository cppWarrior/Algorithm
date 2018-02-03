#include <bits/stdc++.h>

using namespace std;

int N, n;
vector<vector<char>> v1, v2;

int countAns()
{
    int ret = 0;
    bool check;
    for (int i = 0; i <= N - n; i ++) {
        for (int j = 0; j <= N - n; j ++) {
            check = true;
            for (int a = 0; a < n; a ++) {
                for (int b = 0; b < n; b ++) {
                    if (v1[i + a][j + b] != v2[a][b]) check = false;
                }
            }

            if (check) ret++;
        }
    }

    return ret;
}

void rotate()
{
    vector<vector<char>> temp;
    temp.resize(n);
    for (int i = 0; i < n; i ++) {
        temp[i].resize(n);
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            temp[j][n - i - 1] = v2[i][j];
        }
    }

    v2 = temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (true) {
        cin >> N >> n;
        if (N == 0 && n == 0) break;
        v1.resize(N);
        v2.resize(n);
        for (int i = 0; i < N; i ++) {
            v1[i].resize(N);
            for (int j = 0; j < N; j ++) {
                cin >> v1[i][j];
            }
        }

        for (int i = 0; i < n; i ++) {
            v2[i].resize(n);
            for (int j = 0; j < n; j ++) {
                cin >> v2[i][j];
            }
        }

        for (int i = 0; i < 4; i ++) {
            if (i > 0) rotate();
            cout << countAns();
            if (i < 3) cout << ' ';
        }

        cout << '\n';
    }
}
