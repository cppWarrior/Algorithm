#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];
int dist[1000][1000];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t, n, m;
    cin >> t;
    while (t--) {
        memset(dist, 1, sizeof(dist));
        cin >> n >> m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                cin >> a[i][j];
            }
        }

        dist[0][0] = a[0][0];
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.emplace(a[0][0], make_pair(0, 0));

        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            int d = -front.first;
            auto u = front.second;

            if (d > dist[u.first][u.second]) continue;

            for (int i = 0; i < 4; i ++) {
                int nx = u.first + dx[i];
                int ny = u.second + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] > dist[u.first][u.second] + a[nx][ny]) {
                    dist[nx][ny] = dist[u.first][u.second] + a[nx][ny];
                    pq.emplace(-dist[nx][ny], make_pair(nx, ny));
                }
            }
        }

        cout << dist[n - 1][m - 1] << '\n';
    }
}
