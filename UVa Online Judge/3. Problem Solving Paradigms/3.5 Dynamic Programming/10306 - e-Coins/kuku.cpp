// 10306.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[301][301]; int m, s, t, ans; 
vector<pair<int, int>> v;
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> t;
	while (t--) {
		v.clear(); 
		cin >> m >> s;
		for (int i = 0; i < m; i++) {
			int fir, sec; cin >> fir >> sec;
			v.push_back(make_pair(fir, sec));
		}
		ans = 1000;
		for (int i = 0; i < 301; i++) {
			for (int j = 0; j < 301; j++) {
				dp[i][j] = 1000;
			}
		}
		dp[0][0] = 0;

		for (int i = 0; i < v.size(); i++) {
			int a = v[i].first;	int b = v[i].second;
			//cout << "-------------------\n";
			for (int x = a; x <= s; x++) {
				for (int y = b; y <= s; y++) {
					dp[x][y] = min(dp[x][y], dp[x - a][y - b] + 1);
					//cout << "dp[" << x << "][" << y << "] = " << dp[x][y] << "\n";
					if (x*x + y*y == s*s) {
						if (ans > dp[x][y]) ans = dp[x][y];
					}
				}
			}
		}

		if (ans == 1000) printf("not possible\n");
		else {
			printf("%d\n", ans);
		}
		
	}
	system("pause");
    return 0;
}

