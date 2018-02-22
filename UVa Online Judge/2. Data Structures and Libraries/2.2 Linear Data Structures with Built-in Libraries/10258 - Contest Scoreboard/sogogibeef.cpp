// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
string line;
int n;
char L;
int a, b, c;
bool contestants[101];
tuple<int, int, int> q;
vector<tuple<int, int, int>> judge;
bool solved[101][10];
bool tried[101][10];

int times[101];
int attempt[101][10];
int corrects[101];
int count;


int sumArray(int k[]) {
    int sum = 0;
    for (int i = 0; i < sizeof(k); i++) {
        sum += k[i];
    }
    return sum;
}


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
        memset(times, 0, sizeof(times));
        memset(solved, 0, sizeof(solved));
        memset(tried, 0, sizeof(tried));
        memset(attempt, 0, sizeof(attempt));
        memset(corrects, 0, sizeof(corrects));
        judge.clear();


        while (true) {
            if (!getline(cin, line) || line == "") {
                break;
            }

            istringstream iss(line);

            iss >> a >> b >> c >> L;

            if (L == 'R' || L == 'U' || L == 'E') {
                continue;
            }


            contestants[a] = true;

            if (L == 'C') {
                solved[a][b] = true;
                tried[a][b] = true;
                times[a] += c;
                corrects[a]++;
            } else if (L == 'I') {
                attempt[a][b] += 20;
                tried[a][b] = true;
            }

        }

        for (int i = 0; i < 100; i++) {
            if (contestants[i] && tried[i]) { // WIP
                q = make_tuple(corrects[i], -(times[i] + sumArray(attempt[i])), i);
                judge.push_back(q);
            }
        }

        if(!judge.empty()){
            sort(judge.begin(), judge.end());

            for (int i = judge.size() - 1; i >= 0; i--) {
                cout << get<2>(judge[i]) << " " << get<0>(judge[i]) << " " << -get<1>(judge[i]) << "\n";
            }
        }

        cout << "\n";

    }

    return 0;

}





