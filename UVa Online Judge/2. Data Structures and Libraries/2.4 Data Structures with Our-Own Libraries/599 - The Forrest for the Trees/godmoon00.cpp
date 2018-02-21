#include <bits/stdc++.h>

using namespace std;

bool isVertex[26];
int parent[26];
int numChildren[26];

int findRoot(int a)
{
    if (parent[a] == a) return a;
    return findRoot(parent[a]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;

        memset(numChildren, 0, sizeof(numChildren));
        memset(isVertex, false, sizeof(isVertex));
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        while (true) {
            getline(cin, s);
            if (s[0] == '*') break;

            int from = max(s[1], s[3]) - 'A';
            int to = min(s[1], s[3]) - 'A';
            parent[findRoot(from)] = findRoot(to);
        }

        getline(cin, s);

        for (int i = 0; s[i]; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                isVertex[s[i]- 'A'] = true;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (isVertex[i]) numChildren[findRoot(i)]++;
        }

        int numTrees = 0, numAcorns = 0;
        for (int i = 0; i < 26; i++) {
            if (isVertex[i]) {
                if (numChildren[i] > 1) numTrees++;
                else if (numChildren[i] == 1) numAcorns++;
            }
        }

        cout << "There are " << numTrees << " tree(s) and " << numAcorns << " acorn(s).\n";
    }
}
