// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
map<string, int> trend;
int tc;
int popularity;
int courses[5];
string combi;
int dup = 0;
bool singleMax = true;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> tc;

    while (tc != 0) {
        trend.clear();
        popularity = -1;
        singleMax = true;
        dup = 0;

        for (int i = 0; i < tc; i++) {
            combi.clear();
            cin >> courses[0] >> courses[1] >> courses[2] >> courses[3] >> courses[4];
            sort(courses, courses + 5);
            for (int i = 0; i < 5; i++) {
                combi += to_string(courses[i]);
            }


            trend[combi]++;
        }

        for (auto const &x:trend) {
            if (x.second > popularity) {
                popularity = x.second;
            }
        }

        for (auto const &x:trend) {
            if (x.second == popularity) {
                singleMax = false;
                dup++;
            }
        }


        if (!singleMax) cout << popularity * dup << "\n";
        else cout << popularity << "\n";


        cin >> tc;
    }


    return 0;
}





