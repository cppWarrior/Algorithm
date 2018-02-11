// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int n, daily, entry;
long long int payment;
multiset<int> bills;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n;
    while (n != 0) {
        bills.clear();
        payment = 0;

        for (int i = 0; i < n; i++) {
            cin >> daily;
            if (daily != 0) {
                for (int j = 0; j < daily; j++) {
                    cin >> entry;
                    bills.insert(entry);
                }
            }
            payment += (long long int) *prev(bills.end()) - *bills.begin();
            bills.erase(bills.find(*prev(bills.end())));
            bills.erase(bills.find(*bills.begin()));
        }
        cout << payment << "\n";
        cin >> n;
    }


    return 0;
}





