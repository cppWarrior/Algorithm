// Jeong-Min Lim (limjeongmin@wustl.edu)

#include <bits/stdc++.h>

//#include "/Users/jeongminlim/stdc++.h"

using namespace std;

int n, temp, ans;
int streak[10500];
vector<int> wins;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here

    cin >> n;
    while (n != 0) {
        memset(streak, 0, sizeof(streak));
        temp = 0;
        ans = -1;
        wins.clear();

        for (int i = 0; i < n; i++) {
            cin >> streak[i];
            if (streak[i] < 0 && streak[i]+temp <0){
                temp = 0;
                continue;
            }

            temp += streak[i];
            wins.push_back(temp);

        }


        sort(wins.begin(), wins.end());
        for (auto &i:wins) {
            if (ans < i) {
                ans = i;
            }

        }
        if (ans > 0) {
            cout << "The maximum winning streak is " << ans << ".\n";
        } else {
            cout << "Losing streak.\n";
        }


        cin >> n;
    }


    return 0;
}





