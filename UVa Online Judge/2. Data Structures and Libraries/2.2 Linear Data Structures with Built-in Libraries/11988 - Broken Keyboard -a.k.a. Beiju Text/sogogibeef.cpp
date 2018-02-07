//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    // move pointer to the beginning of list after encountering '['
    string input;
    while (cin >> input) {
        list<char> beiju;
        beiju.clear();
        auto position = beiju.begin();

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '[') {
                position = beiju.begin();
                continue;

            } else if (input[i] == ']') {
                position = beiju.end();
                continue;
            }

            beiju.insert(position, input[i]);

        }


        for (auto &i:beiju) {
            cout << i;
        }
        cout << "\n";


    }


    return 0;
}





