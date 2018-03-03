//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int T;
int n;
int report[1050];
int sum;



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here

    cin >> T;


    for (int i = 0; i < T; i++){
        cin >> n;
        memset(report, 0, sizeof(report));
        sum = 0;

        for (int j = 0; j < n; j++){
            cin >> report[j];
        }

        for (int j = 1; j < n; j++){
            for (int k = 0; k < j; k++){
                if (report[k] <= report[j]){
                    sum++;
                }
            }
        }

        cout << sum << "\n";








    }
    return 0;
}
