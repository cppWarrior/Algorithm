// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int a, b, n, cnt, temp;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;

    while (n != 0) {
        temp = n;
        cnt = 0;
        a = 0;

        /* for every other division by 2 with remainder 1, set bit to 1.
         * 6 >> 3  = 3 cnt = 0
         * 3 / 2  = 1 cnt = 1 >> flip 2
         * 1  = 1/2 cnt = 1
         * ...10
         *
         * 7 >> 1 = 3...1 , cnt = 1, flip 1
         * 3 >> 1 = 1...1, cnt = 2
         * 1 >> 1 = 0...1 cnt = 3, flip 1
         * ...101
         *
         * 13 >> 1 = 6...1, cnt = 1, flip 1
         * 6 >> 1 = 3
         * 3 >> 1 = 1...1 cnt = 2
         * 1 >> 1 = 0...1 cnt = 3, flip 1
         * 1101 > 0101 > 0010 >> 0001
         * ...1001
         *
         */

        for (int i = 0; temp > 0; i++) {
            if (temp % 2 == 1) {
                cnt++;
                if (cnt % 2 == 1) {
                    a |= 1 << i;
                }
            }
            temp >>= 1;
        }

        b = n - a;
        cout << a << " " << b << "\n";

        cin >> n;
    }


    return 0;
}





