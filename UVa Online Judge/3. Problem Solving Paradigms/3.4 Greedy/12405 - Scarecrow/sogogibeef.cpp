// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int t;
int n;
int c;
int r;
int ans;
bool field[110];
char a;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> t;
    while (t--) {
        c++;
        ans = 0;
        memset(field, 0, sizeof(field));
        r = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a == '.') {
                field[i] = true;
            } else {
                field[i] = false;
            }
        }

        while (r < n) {
            if (!field[r]) {
                r++;
            } else if (field[r] && !field[r + 1] && !field[r + 2]) {
                ans++;
                r += 2;
            } else if ((field[r] && field[r + 1] && field[r + 2]) ||
                       (field[r] && field[r + 1] && !field[r + 2]) ||
                       (field[r] && !field[r + 1] && field[r + 2])) {
                ans++;
                r += 3;
            }

        }


        cout << "Case " << c << ": " << ans << "\n";

    }


    return 0;
}





