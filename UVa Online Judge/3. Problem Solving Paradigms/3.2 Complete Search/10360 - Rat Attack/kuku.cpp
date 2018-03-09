// 10360.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int killed[1050][1050]; int ans1, ans2, sum;
int main()
{
	int n; cin >> n;
	for (int s = 0; s < n; s++) {
		int d, m; cin >> d >> m;
		// 초기화
		for (int z = 0; z < 1030; z++) {
			memset(killed[z], 0, sizeof(int) * 1030);
		}
		sum = 0;
		//
		for (int i = 0; i < m; i++) {
			int x, y, c; cin >> x >> y >> c;
			int l = x - d, r = y - d, up = x + d, down = y + d;
			if (l < 0) l = 0;
			if (r < 0 ) r = 0;
			if (up > 1024 ) up = 1024;
			if (down > 1024) down = 1024;
			//cout << l << " " << r << " " << up << " " << down << "\n";
			for (int a = l; a <= up; a++) {
				for (int b = r; b <= down; b++) {
					killed[a][b] += c;
					//cout <<a << " " << b << " " <<killed[a][b] << "\n";
				}
			}
		}
		sum = 0;
		for (int i = 0; i < 1024; i++) {
			for (int j = 0; j < 1024; j++) {
				if (killed[i][j] > sum) {
					sum = killed[i][j];
					ans1 = i; ans2 = j;
				}
			}
		}
		cout << ans1 << " " << ans2 << " " << sum << "\n";
	}
    return 0;
}

