// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>


#include "/Users/jeongminlim/stdc++.h"

using namespace std;

int n;
vector<string> F;
string patch;
vector<pair<int, int>> ones, threes;
pair<int, int> pos;
vector<int> minimums;
int minDist, temp, ans;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
/*
 * Get minimum of minimum distances from 1 to 3 for each 1
 * Get maximum value of minimum of minimum distances from 1 to 3 for all 1
 * Can deal with any 1.
 */

    while (cin >> n) {
        ones.clear();
        threes.clear();
        minimums.clear();
        F.clear();
        minDist = (1 << 30) + ((1 << 30) - 1);
        temp = 0;
        ans = -1;


        for (int i = 0; i < n; i++) {
            cin >> patch;
            F.push_back(patch);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (F[i][j] == '1') {
                    pos = make_pair(i, j);
                    ones.push_back(pos);
                } else if (F[i][j] == '3') {
                    pos = make_pair(i, j);
                    threes.push_back(pos);
                }
            }
        }


        for (int i = 0; i < ones.size(); i++) {
            minDist = (1 << 30) + ((1 << 30) - 1);

            for (int j = 0; j < threes.size(); j++) {
                temp = abs(threes[j].first - ones[i].first) + abs(threes[j].second - ones[i].second);

                if (temp < minDist) {
                    minDist = temp;
                }
            }

            minimums.push_back(minDist);

        }


        for (auto &i:minimums) {
            if (ans < i) {
                ans = i;
            }
        }


        cout << ans << "\n";

    }


    return 0;
}





