#include <bits/stdc++.h>

using namespace std;

int s, d, ans;
bool check[12];

void go(int i)
{
    if (i == 12) {
        int temp;

        for (int a = 0; a < 8; a++) {
            temp = 0;
            for (int b = a; b < a + 5; b++) {
                temp += check[b]? s : -d;
            }
            if (temp >= 0) return;
        }

        temp = 0;
        for (bool& a : check) {
            temp += a ? s : -d;
        }

        ans = max(ans, temp);
        return;
    }

    check[i] = true;
    go(i + 1);
    check[i] = false;
    go(i + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> s >> d) {
        memset(check, false, sizeof(check));
        ans = -1;

        go(0);
        
        if (ans < 0) {
            cout << "Deficit\n";
        }
        else {
            cout << ans << '\n';
        }
    }
}
