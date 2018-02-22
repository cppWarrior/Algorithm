// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;

string line;
char L;
bool contestants[110];
bool solved[110][15];

int n, a, b, c;
int t[110];
int attempt[110][15];
int corrects[110];

tuple<int, int, int> q;
vector<tuple<int, int, int>> judge;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;
    cin.ignore();
    cin.ignore();

    while (n--) {
        memset(contestants, 0, sizeof(contestants));
        memset(t, 0, sizeof(t));
        memset(solved, 0, sizeof(solved));
        memset(attempt, 0, sizeof(attempt));
        memset(corrects, 0, sizeof(corrects));
        judge.clear();


        while (true) {
            if (!getline(cin, line) || line == "") {
                break;
            }

            istringstream iss(line);

            iss >> a >> b >> c >> L;
            contestants[a] = true;

            if (L == 'R' || L == 'E' || L == 'U') {
                continue;

            } else if (L == 'C') {
                if (solved[a][b]) {
                    continue;
                } else {
                    solved[a][b] = true;
                    t[a] = t[a] + c + attempt[a][b];
                    corrects[a]++;
                }

            } else if (L == 'I') {
                attempt[a][b] += 20;
            }


        }


        for (int i = 1; i <= 100; i++) {
            if (contestants[i]) {
                q = make_tuple(-corrects[i], (t[i]), i);
                judge.push_back(q);
            }
        }

        sort(judge.begin(), judge.end());


        for (int i = 0; i < judge.size(); i++) {
            cout << get<2>(judge[i]) << " "
                 << -get<0>(judge[i]) << " "
                 << get<1>(judge[i]) << "\n";
        }

        if (n > 0) cout << "\n";
    }
    return 0;

}




