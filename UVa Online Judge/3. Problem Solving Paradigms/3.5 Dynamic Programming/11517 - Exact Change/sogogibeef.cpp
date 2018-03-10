// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
// int pea = 1<<30 + ((1<<30)-1);

#include "/Users/jeongminlim/stdc++.h"

using namespace std;
// dp : 동전으로 지불하는 금액
// dp - price가 가장 작은 것으로 계산

int tc;
int price, n;
int purse[110];
int dp[40000];
//int dp2[1000000];
int ans;

//void go(int sum, int index, int cnt) { // 2 to the n (worst: 2^100), invalid
//    if (index == n) {
//        if (sum < price) {
//            return;
//        } else if (sum >= price) {
//            dp2[sum] = cnt;
//        }
//        return;
//    }
//
//    go(sum + purse[index], index + 1, cnt + 1);
//    go(sum, index + 1, cnt);
//
//}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> tc;
    while (tc--) {
        memset(purse, 0, sizeof(purse));
        ans = 1000000;


        cin >> price >> n;
        for (int i = 0; i < n; i++) {
            cin >> purse[i];
        }

        dp[0] = 0;

        for (int i = 1; i < 40000; i++) {
            dp[i] = 1000000;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 40000 - purse[i] - 1; j >= 0; j--) {
                if (dp[j] < 1000000) {
                    dp[j + purse[i]] = min(dp[j + purse[i]], dp[j] + 1);
                }
            }
        }


        for (int i = 0; i < 40000; i++) {
            if (dp[i] != 1000000 && i >= price) {
                ans = min(ans, i);
            }
        }

        cout << ans << " " << dp[ans] << "\n";

    }


    return 0;
}





