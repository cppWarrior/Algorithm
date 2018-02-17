// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int board[20][2];
bool used[20]; // maximum : 14 dominoes
int n, m, i1, i2, d1, d2;
bool match;

void go(int cnt, int compare) {
    if (cnt == n) {
        if (compare == d1) {
            match = true;
            return;
        }
        return;
    }

    for (int i = 0; i < m; i++) {
        if (used[i]) {
            continue;
        }
        if (board[i][0] == compare || board[i][1] == compare) {
            used[i] = 1;
            if (board[i][0] == compare) {
                go(cnt + 1, board[i][1]);
            } else {
                go(cnt + 1, board[i][0]);
            }

            used[i] = 0; // as in PICNIC, do not forget to change used back to false...
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;
    while (n != 0) {
        memset(board, 0, sizeof(board));
        memset(used, 0, sizeof(used));
        match = false;


        cin >> m >> i1 >> i2 >> d1 >> d2;

        for (int i = 0; i < m; i++) {
            cin >> board[i][0] >> board[i][1];
        }

        go(0, i2);

        if (match) cout << "YES\n";
        else cout << "NO\n";

        cin >> n;


    }


    return 0;
}





