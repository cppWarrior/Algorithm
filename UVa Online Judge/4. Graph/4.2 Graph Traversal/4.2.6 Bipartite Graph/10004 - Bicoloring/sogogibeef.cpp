// Jeong-Min Lim (limjeongmin@wustl.edu)

#include <bits/stdc++.h>

using namespace std;
int n, l;
int color[220];
queue<int> q;
bool isBipartite;
int a, b, s;
vector<vector<int>> AdjList;
vector<int> temp;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;
    while (n != 0) {
        AdjList.clear();

        cin >> l;

        for (int i = 0; i < 220; i++) {
            color[i] = 1000000;
        }

        for (int i = 0; i < n; i++) {
            temp.clear();
            AdjList.push_back(temp);
        }


        for (int i = 0; i < l; i++) {
            cin >> a >> b;
            if (i == 0) {
                s = a;
            }
            AdjList[a].push_back(b);
        }

        q.push(s);
        color[s] = 0;
        isBipartite = true;


        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                int v = AdjList[u][j];

                if (color[v] == 1000000) {
                    color[v] = 1000000 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartite = false;
                    break;
                }
            }
        }

        if (isBipartite) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }

        cin >> n;
    }


    return 0;
}





