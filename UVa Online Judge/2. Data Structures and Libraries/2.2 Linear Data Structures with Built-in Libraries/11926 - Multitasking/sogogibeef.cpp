
// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int n, m;
int oB, oE;
int rB, rE, rI;
bitset<1000050> calendar;
bool conflicting = false;

void overlap(int begin, int end) {
    for (int i = begin; i < end; i++) {
        if (calendar[i] == true) {
            conflicting = true;
            return;
        }
        calendar.set(i, true);
    }
    conflicting = false;
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

    while (n != 0 || m != 0) {
        calendar.reset();
        conflicting = false;

        for (int o = 0; o < n; o++) {
            cin >> oB >> oE;
            overlap(oB, oE);
        }


        for (int r = 0; r < m; r++) {
            cin >> rB >> rE >> rI;
            while (rB < 1000000 && !conflicting) {
                overlap(rB, rE);
                rB += rI;
                rE += rI;
                if (rE > 1000000) {
                    rE = 1000000;
                }
            }
        }


        if (conflicting) {
            cout << "CONFLICT\n";
        } else {
            cout << "NO CONFLICT\n";
        }

        cin >> n >> m;

    }


    return 0;
}







