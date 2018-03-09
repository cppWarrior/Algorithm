// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
// int pea = 1<<30 + ((1<<30)-1);

#include "/Users/jeongminlim/stdc++.h"

using namespace std;

vector<int> arr;
vector<int> lis[100000];
int n, dp[100000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    while (cin >> n) {
        arr.push_back(n);
    }


    for (int i = 0; i < arr.size(); i++) {
        if (dp[i] == 0) dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    lis[i].push_back(arr[j]);
                }
            }
        }
        lis[i].push_back(arr[i]);

    }

    int ans = -1;
    int ansI = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (ans < dp[i]) {
            ans = dp[i];
            ansI = i;
        }
    }

    cout << ans << "\n" << '-' << "\n";
    for (int i = 0; i < ans; i++) {
        cout << lis[ansI][i] << "\n";
    }


    return 0;
}




