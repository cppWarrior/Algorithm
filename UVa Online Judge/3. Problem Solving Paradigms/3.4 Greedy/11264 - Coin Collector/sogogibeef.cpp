// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int T;
int n, c;
vector<int> coins;
int types;

void withdraw(int index, int balance) {
    if (index == n - 1) {
        return;
    }

    if (balance + coins[index] < coins[index + 1]) {
        balance += coins[index];
        types++;
    }
    withdraw(index + 1, balance);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here

    cin >> T;
    while (T--) {
        coins.clear();
        types = 1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c;
            coins.push_back(c);
        }

        withdraw(0, 0);

        cout << types << "\n";

    }


    return 0;
}




