// Jeong-Min Lim (limjeongmin@wustl.edu)

#include <bits/stdc++.h>

using namespace std;
int n, s, p, x, y;
vector<pair<int, int>> coord;
vector<tuple<double, int, int>> graph;

// Union Find Disjoint Set

vector<int> parent;

int find(int n) {
    if (parent[n] < 0) return n;
    parent[n] = find(parent[n]);
    return parent[n];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;
    while (n--) {
        cin >> s >> p;
        coord.clear();
        graph.clear();
        parent.clear();


        for (int i = 0; i < p; i++) {
            cin >> x >> y;
            coord.emplace_back(x, y);
            parent.push_back(-1);
        }

        sort(coord.begin(), coord.end());


        // O ( N C 2 )

        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                int a = coord[i].first - coord[j].first;
                int b = coord[i].second - coord[j].second;
                double d = sqrt(a * a + b * b);
                graph.emplace_back(d, i, j);
            }
        }

        sort(graph.begin(), graph.end());

        double mst = 0;
        int cnt = 0;

        for (int i = 0; i < graph.size(); i++) {
            int x = get<1>(graph[i]);
            int y = get<2>(graph[i]);

            if (find(x) == find(y)) continue;
            
            else {
                merge(x, y);
                mst = max(mst, get<0>(graph[i]));
                cnt++;
                if (cnt == p - s) break;
            }

        }

        cout << setprecision(2) << fixed << mst << "\n";


    }


    return 0;
}





