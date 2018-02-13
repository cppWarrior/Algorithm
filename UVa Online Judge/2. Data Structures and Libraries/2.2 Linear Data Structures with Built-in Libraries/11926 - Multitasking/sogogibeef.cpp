// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int n, m, s, e, r;
bitset<1000050> calendar;
bool conflict = false;

void overlap(int begin, int end) {
    for (int i = begin; i < end; i++) {
        if (calendar[i] == true) {
            conflict = true;
            return;
        }
        calendar.set(i, true);
    }
    conflict = false;
    return;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n >> m;
    while (!(n == 0 && m == 0)) {
        calendar.reset();
        conflict = false;
        for (int i = 0; i < n; i++) {
            cin >> s >> e;
            overlap(s, e);
        }

        for (int i = 0; i < m; i++) {
            cin >> s >> e >> r;
            while (s < 1000000 && !conflict) {
                overlap(s, e);
                s += r;
                e = min(e + r, 1000000);
            }
        }

        if (conflict) cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";
        cin >> n >> m;


    }


    return 0;
}





