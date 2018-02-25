// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int N;
vector<int> books;
int budget, price;
int a, b;
int tempA, tempB;
bool first = true;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here

    while (cin >> N) {
//        if (!first) cout << "\n";
//        if (first) first = false;


        books.clear();
        a = 1000051;
        b = 0;
        tempA = 0;
        tempB = 0;

        for (int i = 0; i < N; i++) {
            cin >> price;
            books.push_back(price);
        }

        cin >> budget;

        sort(books.begin(), books.end());

        for (int i = 0; i < N; i++) {
            if (binary_search(books.begin() + i+1, books.end(), budget - books[i])) {
                tempA = books[i];
                tempB = budget - books[i];
                if (abs(a - b) > abs(tempA - tempB)) {
                    a = tempA;
                    b = tempB;
                }
            }
        }

        cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
    }


    return 0;
}





