// 10102.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <tuple>
using namespace std;
int m; int map[100][101]; int mini, ans;
int main()
{
	freopen("test.txt", "r", stdin);
	while (cin >> m) {
		// 초기화
		ans = 0;
		// 입력
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				mini = 999999;
				if (map[i][j] == 1) {
					//cout << i << " " << j << "\n";
					//cout << "---------------------\n";
					for (int k = 0; k < m; k++) {
						for (int l = 0; l < m; l++) {
							if (map[k][l] == 3) {
								//cout << k << " " << l << " ";
								int xdiff = k - i; int ydiff = l - j;
								if (xdiff < 0) xdiff = xdiff*-1;
								if (ydiff < 0) ydiff = ydiff*-1;
								//cout << xdiff << " " << ydiff << "\n";
								if (xdiff + ydiff < mini) mini = xdiff + ydiff;
							}
						}
					}
					if (mini > ans) ans = mini;
				}
			}
		}
		printf("%d\n", ans);
	}

	system("pause");
	return 0;
}


