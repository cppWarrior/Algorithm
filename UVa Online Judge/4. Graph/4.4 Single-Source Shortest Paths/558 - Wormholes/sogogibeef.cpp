// Jeong-Min Lim (limjeongmin@wustl.edu)
// UVA - 558 Wormholes
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[1010];
int dist[1010];
int a, b, c;
int t, n, m;
bool minusExist;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> t;
    while (t--) {
        cin >> n >> m;
        minusExist = false;
        for (int i = 0; i < 1010; i++) {
            dist[i] = 100000000;
            graph[i].clear();
        }
        dist[0] = 0;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b, c));
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (auto &v:graph[j]) {
                    int next = v.first;
                    int d = v.second;
                    if (dist[j] != 100000000 && dist[next] > dist[j] + d) {
                        dist[next] = dist[j] + d;
                        if (i == n - 1) {
                            minusExist = true;
                        }
                    }
                }
            }
        }


        if (minusExist) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }

    }

    return 0;
}


