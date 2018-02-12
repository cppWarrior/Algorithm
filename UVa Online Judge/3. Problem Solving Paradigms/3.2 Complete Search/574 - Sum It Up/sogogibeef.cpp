// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int t, n, e;
bool empty = true;
vector<int> numbers, temp;
set<vector<int>> solutions;

void makeSum(int index, vector<int> ans, int sum) {
    if (sum > t) {
        return;
    }

    if (index == n) {
        if (sum == t) {
            empty = false;
            solutions.insert(ans);
        }
        return;
    }


    ans.push_back(numbers[index]);
    makeSum(index + 1, ans, sum + numbers[index]);
    ans.pop_back();
    makeSum(index + 1, ans, sum);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >> t >> n;


    while (n != 0 && t != 0) {

        // Initialize
        temp.clear();
        numbers.clear();
        solutions.clear();
        empty = true;


        for (int i = 0; i < n; i++) {
            cin >> e;
            numbers.push_back(e);
        }

        makeSum(0, temp, 0); // Driver


        // Printing portion
        cout << "Sums of " << t << ":\n";


        vector<vector<int>> v (solutions.rbegin(),solutions.rend());

        for (auto &i:v) {
            cout << i[0];
            if (i.size() != 1) {
                for (int j = 1; j < i.size(); j++)
                    cout << "+" << i[j];
            }
            cout << "\n";
        }


        if (empty) {
            cout << "NONE\n";
        }



        cin >> t >> n;
    }


    return 0;
}
