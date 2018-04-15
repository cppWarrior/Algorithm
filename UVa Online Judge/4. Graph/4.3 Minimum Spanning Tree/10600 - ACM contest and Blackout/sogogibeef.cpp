// Jeong-Min Lim (limjeongmin@wustl.edu)

#include <bits/stdc++.h>

using namespace std;
int t, n, m, a, b, c, x, y, w;
vector<tuple<int, int, int>> graph;
vector<int> mst_edges;
int p[110];

int find(int n) {
    if (p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        p[b] = a;
    }
}


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
        graph.clear();
        memset(p, -1, sizeof(p));
        mst_edges.clear();


        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph.emplace_back(c, a, b);
        }

        sort(graph.begin(), graph.end());

        int mst = 0;

        for (int i = 0; i < graph.size(); i++) {
            x = get<1>(graph[i]);
            y = get<2>(graph[i]);
            w = get<0>(graph[i]);

            if (find(x) == find(y)) {
                continue;
            }
            merge(x, y);
            mst += w;
            mst_edges.push_back(i);

        }


        int second_best = 300 * 100 + 1;
        for (int i = 0; i < mst_edges.size(); i++) {
            memset(p, -1, sizeof(p));

            int mst2 = 0;
            int connected = 0;


            for (int j = 0; j < graph.size(); j++) {
                if (j == mst_edges[i]) {
                    continue;
                }

                x = get<1>(graph[j]);
                y = get<2>(graph[j]);
                w = get<0>(graph[j]);


                if (find(x) == find(y)) {
                    continue;
                }

                merge(x, y);
                mst2 += w;
                connected++;


            }
            if (connected == n - 1) second_best = min(mst2, second_best);

        }


        cout << mst << " " << second_best << '\n';


    }


    return 0;
}





