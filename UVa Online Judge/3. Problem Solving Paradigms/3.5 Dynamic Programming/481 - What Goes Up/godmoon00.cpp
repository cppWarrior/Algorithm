#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<long long> numbers;
int p[1000001];

void printAns(int idx, int num) {
    if(idx == 0)
        return;
    if(p[idx] == num) {
        printAns(idx - 1, num - 1);
        cout << v[idx - 1] << "\n";
    }
    else {
        printAns(idx - 1, num);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> n)
    {
        v.push_back(n);
    }

    int ans = 0;
    int last;
    for (int i = 0; i < v.size(); i ++) {
        auto pos = lower_bound(numbers.begin(), numbers.end(), v[i]);
        p[i + 1] = distance(numbers.begin(), pos) + 1;
        if (pos == numbers.end())
        {
            ans++;
            numbers.push_back(v[i]);
        }
        else
        {
            *pos = v[i];
        }

    }
    cout << ans << "\n-\n";
    printAns(v.size(), ans);
}
