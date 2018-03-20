// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>

#include "/Users/jeongminlim/stdc++.h"

using namespace std;

int b, s;
int bs[10100], ss[10100];
int c;
int rem, num;
bool remains;
int bi, si;
int diff;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> b >> s;
    while (!(b == 0 && s == 0)) {
        memset(bs, 0, sizeof(bs));
        memset(ss, 0, sizeof(ss));
        c++;
        rem = 80;
        num = 0;
        remains = false;
        bi = 0;
        si = 0;
        diff = 80;

        for (int i = 0; i < b; i++) {
            cin >> bs[i];
        }
        for (int i = 0; i < s; i++) {
            cin >> ss[i];
        }

        sort(bs, bs + b);
        sort(ss, ss + s);
        reverse(bs, bs + b);
        reverse(ss, ss + s);

        if (b <= s) {
            remains = true; // Greedy selection, 독신남성은 반드시 짝을 맺어야 함
        } else {
            // 남자와 여자의 최대 수가 10000이기 때문에 O(n * n)으로도 풀 수 있다.
            for (int i = 0; i < b; i++) {
                diff = 80;
                for (int j = 0; j < s; j++) {
                    if (ss[j] == 0) {
                        continue;
                    }
                    if (abs(bs[i] - ss[j]) <= diff) {
                        bi = i;
                        si = j;
                    }
                }
                bs[bi] = 0;
                ss[si] = 0;

            }


            for (int i = 0; i < b; i++) {
                if (bs[i] != 0) {
                    num++;
                    rem = min(rem, bs[i]);
                }
            }

        }


        if (remains) {
            cout << "Case " << c << ": " << 0 << "\n";
        } else {
            cout << "Case " << c << ": " << num << " " << rem << "\n";
        }


        cin >> b >> s;


    }


    return 0;
}






