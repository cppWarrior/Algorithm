#include <bits/stdc++.h>

using namespace std;

int n;
bool check[17];

bool isPrime(int a)
{
    return a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29 || a == 31;
}

void go(vector<int>& v)
{
    int m = v.size();

    if (m == n) {
        if (isPrime(v[n - 1] + v[0])) {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << ' ';
                cout << v[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!check[i] && isPrime(i + v[m - 1])) {
            check[i] = true;
            v.push_back(i);
            go(v);
            check[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int numTest = 1;
    while (cin >> n) {
        if (numTest > 1) cout << '\n';
        memset(check, false, sizeof(check));
        check[1] = true;
        vector<int> v = {1};

        cout << "Case " << numTest << ":\n";
        go(v);
        numTest++;
    }
}
