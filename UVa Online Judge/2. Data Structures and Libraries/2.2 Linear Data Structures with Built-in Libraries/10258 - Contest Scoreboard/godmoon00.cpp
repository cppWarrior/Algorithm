#include <bits/stdc++.h>

using namespace std;

bool submit[101];
int Time[101];
int accepted[101];
int wrong[101][10];
bool isAccepted[101][10];
vector<tuple<int, int, int>> v;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--) {
        v.clear();
        memset(isAccepted, false, sizeof(isAccepted));
        memset(submit, false, sizeof(submit));
        memset(accepted, 0, sizeof(accepted));
        memset(wrong, 0, sizeof(wrong));
        memset(Time, 0, sizeof(Time));

        while (true) {
            string s;
            getline(cin, s);

            if (s == "") break;
            istringstream iss(s);

            int contestant, problem, time;
            char l;
            iss >> contestant >> problem >> time >> l;

            submit[contestant] = true;

            if (!isAccepted[contestant][problem]) {
                if (l == 'I') {
                    wrong[contestant][problem]++;
                }
                else if (l == 'C') {
                    accepted[contestant]++;
                    Time[contestant] += time + 20 * wrong[contestant][problem];
                    isAccepted[contestant][problem] = true;
                }
            }
        }

        for (int i = 1; i <= 100; i++) {
            if (submit[i]) {
                v.push_back(make_tuple(-accepted[i], Time[i], i));
            }
        }

        sort(v.begin(), v.end());
        for (auto& i: v) {
            cout << get<2>(i) << ' ' << -get<0>(i) << ' ' << get<1>(i) << '\n';
        }
        if (t > 0) cout << '\n';
    }
}
