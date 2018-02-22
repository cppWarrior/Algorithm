#include <bits/stdc++.h>

using namespace std;

int m[201][201];
int r, c;
char F;
string s;

void BtoD(int t, int b, int l, int r)
{
    bool allZero = true, allOne = true;

    for (int i = t; i < b; i ++) {
        for (int j = l; j < r; j++) {
            if (m[i][j]) allZero = false;
            else allOne = false;
        }
    }

    if (allZero) s += "0";
    else if (allOne) s += "1";
    else {
        s += "D";

        if (t + 1 == b) {
            BtoD(t, b, l, (l + r + 1) / 2);
            BtoD(t, b, (l + r + 1) / 2, r);
        }

        else if (l + 1 == r) {
            BtoD(t, (t + b + 1) / 2, l, r);
            BtoD((t + b + 1) / 2, b, l, r);
        }

        else {
            BtoD(t, (t + b + 1) / 2, l, (l + r + 1) / 2);
            BtoD(t, (t + b + 1) / 2, (l + r + 1) / 2, r);
            BtoD((t + b + 1) / 2, b, l, (l + r + 1) / 2);
            BtoD((t + b + 1) / 2, b, (l + r + 1) / 2, r);
        }
    }
}

void DtoB(int t, int b, int l, int r)
{
    if (s.length() == 0) return;
    if (*(s.end() - 1) != 'D') {
        for (int i = t; i < b; i ++) {
            for (int j = l; j < r; j ++) {
                m[i][j] = (*(s.end() - 1)) - '0';
            }
        }
        s.erase(s.end() - 1);
    }
    else {
        s.erase(s.end() - 1);
        if (t + 1 == b) {
            DtoB(t, b, l, (l + r + 1) / 2);
            DtoB(t, b, (l + r + 1) / 2, r);
        }

        else if (l + 1 == r) {
            DtoB(t, (t + b + 1) / 2, l, r);
            DtoB((t + b + 1) / 2, b, l, r);
        }

        else {
            DtoB(t, (t + b + 1) / 2, l, (l + r + 1) / 2);
            DtoB(t, (t + b + 1) / 2, (l + r + 1) / 2, r);
            DtoB((t + b + 1) / 2, b, l, (l + r + 1) / 2);
            DtoB((t + b + 1) / 2, b, (l + r + 1) / 2, r);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> F) {
        s = "";
        if (F == '#') break;
        cin >> r >> c;

        if (F == 'D') {
            cin >> s;
            reverse(s.begin(), s.end());
            DtoB(0, r, 0, c);

            cout << "B";
            cout.width(4); cout << right << r;
            cout.width(4); cout << right << c << '\n';
            int k = 1;
            for (int i = 0; i < r; i ++) {
                for (int j = 0; j < c; j ++, k++) {
                    cout << m[i][j];
                    if (k % 50 == 0 && !(i == r - 1 && j == c - 1)) cout << '\n';
                }
            }
            cout << '\n';
        }
        else {
            for (int i = 0; i < r; i ++) {
                for (int j = 0; j < c; j ++) {
                    char temp;
                    cin >> temp;
                    m[i][j] = temp - '0';
                }
            }
            BtoD(0, r, 0, c);

            cout << "D";
            cout.width(4); cout << right << r;
            cout.width(4); cout << right << c << '\n';
            int k = 1, length = s.length();
            for (int i = 0; s[i]; i++, k++) {
                cout << s[i];
                if (k % 50 == 0 && i != length - 1) cout << '\n';
            }
            cout << '\n';
        }
    }
}
