// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>

#include "/Users/jeongminlim/stdc++.h"

using namespace std;

int m, n;
int p[110], f[110];
int d1[10500]; // m의 값이 사실상 10200까지인데 10100까지만 잡아서 에러가 났었음
int refunded;

void pay(int M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = M; j >= p[i]; j--) {
            if (d1[j - p[i]] > 0 || j == p[i]) {
                d1[j] = max(f[i] + d1[j - p[i]], d1[j]);
            }
        }
    }
    return;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    while (cin >> m >> n) {

        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        memset(d1, 0, sizeof(d1));


        if (m > 1800) {
            m += 200;
        }


        for (int i = 0; i < n; i++) {
            cin >> p[i] >> f[i];
        }


        pay(m, n);


        int ans = 0;
        refunded = m - 200;
        if (1800 < refunded && refunded <= 2000) {
            for (int i = 0; i < refunded; i++) {
                ans = max(ans, d1[i]);
            }
            for (int i = 2001; i <= m; i++) {
                ans = max(ans, d1[i]);
            }
        } else {
            for (int i = 0; i <= m; i++) {
                ans = max(ans, d1[i]);
            }
        }

        cout << ans << "\n";


    }


    return 0;
}






