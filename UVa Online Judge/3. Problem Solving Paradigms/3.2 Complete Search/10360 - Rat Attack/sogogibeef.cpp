// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>


#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int tc;
int killed[1050][1050];
int d;
int n, p;
int x, y, s;
int ansx, ansy, cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> tc;
    while (tc--) {
        memset(killed, 0, sizeof(killed));
        cnt = -1;
        ansx = 0;
        ansy = 0;

        cin >> d >> n;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> s;
            for (int i = max(0, x - d); i <= min(x + d, 1024); i++) {
                for (int j = max(0, y - d); j <= min(y + d, 1024); j++) {
                    killed[i][j] += s;
                }
            }

        }

        for (int i = 0; i <= 1024; i++) {
            for (int j = 0; j <= 1024; j++) {
                if (killed[i][j] > cnt) {
                    cnt = killed[i][j];
                    ansx = i;
                    ansy = j;
                }
            }

        }

        cout << ansx << " " << ansy << " " << cnt << "\n";
    }


    return 0;
}





