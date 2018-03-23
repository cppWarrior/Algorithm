// Jeong-Min Lim (limjeongmin@wustl.edu)

#include <bits/stdc++.h>

using namespace std;
int n; // number of rungs 1<= n <=10 <= 100000
int k; // strength factor k
int t;
int cases;
int r; // height of rung from ground
int maxDiff;
vector<int> ladder;
vector<int> diffs;



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here


    cin >> t;
    while (t--) {
        ladder.clear();
        diffs.clear();
        cases++;

        cin >> n;
        ladder.push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> r;
            ladder.push_back(r);
        }


        maxDiff = -1;
        for (int i = 0; i < n; i++) {
            diffs.push_back(ladder[i + 1] - ladder[i]);
            maxDiff = max(maxDiff, diffs[i]);
        }


        k = maxDiff;
        for (auto &i:diffs) {
            if (i == maxDiff) {
                maxDiff--;
            } else if (i > maxDiff) {
                k++;
                break;
            }
        }


        cout << "Case " << cases << ": " << k << "\n";
    }


    return 0;
}





