// 11286.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int course[10100][6]; bool check[10100]; int ans[10100]; int maxi = 1; int result = 0;
	freopen("test.txt", "r", stdin);
	while (1) {
		memset(check, 1, 10100 * sizeof(bool));
		memset(ans, 0, 10100 * sizeof(int));
		result = 0; maxi = 1;
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", &course[i][j]);
			}
			sort(course[i], course[i] + 5);
			if (i == 0) { check[0] = true; ans[0]++; }
			else {
				for (int k = 0; k <= i; k++) {
					for (int l = 0; l < 5; l++) {
						if (check) {
							if (course[k][l] != course[i][l]) break;
							if (l == 4 && (course[k][l] == course[i][l])) {
								check[i] = false;
								ans[k]++;
								if (ans[k] > maxi) maxi = ans[k];
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] == maxi) {
				result += ans[i];
			}
		}
		printf("%d\n", result);

	}

	system("pause");
    return 0;
}

