// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int b, s;

vector<string> big;
vector<string> small;
vector<string> temp;
vector<int> ans;
string line;
int counter;
//orientation 0 1 2 3


bool compare(vector<string> a, vector<string> b) {
    return (equal(a.begin(), a.end(), b.begin()));
}

void rotate90(vector<string> &a) { // don't forget to use & sign to actually change values
    // reverse rows in vector, put vector into 2D array, transpose, and then put into vector again.
    int len = a.size();
    string c[len][len];
    string e;
    vector<string> newMatrix;
    e.clear();

    // reverse rows
    for (int i = 0; i < len; i++) {
        reverse(a[i].begin(), a[i].end());
    }

    // put vector into 2D array
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            c[i][j] = a[i].substr(j, 1);
        }
    }

    // transpose 2D array
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            swap(c[i][j], c[j][i]);
        }
    }

    a.clear();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            e.append(c[i][j]);
        }
        a.push_back(e);
        e.clear();
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //id here
    cin >> b >> s;
    while (b != 0 && s != 0) {
        ans.clear();
        big.clear();
        small.clear();
        temp.clear();


        for (int i = 0; i < b; i++) {
            cin >> line;
            big.push_back(line);
        }

        for (int i = 0; i < s; i++) {
            cin >> line;
            small.push_back(line);
        }


        for (int o = 0; o < 4; o++) {
            counter = 0;
            for (int i = 0; i < b - s + 1; i++) {
                for (int j = 0; j < b - s + 1; j++) {
                    for (int k = 0; k < s; k++) {
                        temp.push_back(big[i + k].substr(j, s));
                    }
                    if (compare(small, temp)) {
                        counter++;
                    }
                    temp.clear();
                }
            }
            ans.push_back(counter);
            rotate90(big);
        }


        for (int i = 0; i < 4; i++) {
            if (i == 3) {
                cout << ans[i];
            } else {
                cout << ans[i] << " "; // Presentation error...
            }
        }
        cout << "\n";
        cin >> b >> s;
    }

    return 0;
}

