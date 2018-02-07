
//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
bool front = false;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    string line;
    string text, b, f;

    while (cin >> line) {
        text.clear();
        b.clear();
        f.clear();

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '[') {
                front = true;
                reverse(f.begin(), f.end());
                text = f + text;
                f.clear();
                continue;

            } else if (line[i] == ']') {
                front = false;
                reverse(f.begin(), f.end());
                text = f + text;
                f.clear();
                continue;
            }

            if (front) {
                f = line[i] + f;
            } else {
                text = text + line[i];
            }

        }
        reverse(f.begin(), f.end());
        text = f + text;
        cout << text << "\n";
    }


    return 0;
}
