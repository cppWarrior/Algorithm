#include <bits/stdc++.h>

using namespace std;

vector<string> v;
multimap<string, string> m;
map<string, int> dist;
map<string, bool> check;

void init() {
    for (int i = 0; i < v.size(); i ++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].length() != v[j].length()) continue;
            int diff = 0;
            for (int k = 0; v[i][k]; k ++) {
                if (v[i][k] != v[j][k]) diff++;
            }
            if (diff == 1) {
                m.insert({v[i], v[j]});
                m.insert({v[j], v[i]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        if (z > 0) cout << '\n';
        v.clear();
        m.clear();

        string s;
        while (cin >> s) {
            if (s == "*") break;
            v.push_back(s);
        }
        cin.ignore();
        init();

        bool first = true;
        while (getline(cin, s)) {
            dist.clear();
            check.clear();

            queue<string> q;

            if (s == "") break;
            string s1, s2;

            int i = 0;
            for (i; s[i]; i++) {
                if (s[i] == ' ') break;
                s1 += s[i];
            }

            i++;
            for (i; s[i]; i++) s2 += s[i];

            q.push(s1);
            dist[s1] = 0;
            check[s1] = true;

            while (!q.empty()) {
                auto now = q.front();
                int nowDist = dist[now];
                q.pop();

                for (auto it = m.lower_bound(now); it != m.upper_bound(now); it++) {
                    if (!check[it -> second]) {
                        q.push(it->second);
                        dist[it->second] = nowDist+1;
                        check[it->second] = true;
                    }
                }
            }
            // if (z != 0 || !first) cout << '\n';
            first = false;
            cout << s1 << ' ' << s2 << ' ' << dist[s2] << '\n';
        }
    }
}
