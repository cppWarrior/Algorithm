// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int n, d, r;
//int morning[110], night[110];
vector<int> morning, night, payment;
int route;
int sum;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> n >> d >> r;
    while (n != 0 && d != 0 && r != 0) {
        morning.clear();
        night.clear();
        payment.clear();
        sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> route;
            morning.push_back(route);
        }
        for (int i = 0; i < n; i++) {
            cin >> route;
            night.push_back(route);
        }

        sort(morning.begin(), morning.end());
        sort(night.rbegin(), night.rend());

        for (int i = 0; i < n; i++) {
            if((morning[i]+night[i])>d){
                payment.push_back((morning[i] + night[i] - d) * r);
            }
        }


        for (auto &i:payment) {
            sum += i;
        }

        cout << sum << "\n";
        cin >> n >> d >> r;
    }


    return 0;
}





