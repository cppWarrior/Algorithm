// 11926.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <cstring>
using namespace std;
int main()
{
	bool check[1000100]; bool ans = true;
	freopen("test.txt", "r", stdin);
	while (1) {
		ans = true;
		memset(check, 0, 1000100*sizeof(bool));
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) {
			int start1; int end1;
			scanf("%d %d", &start1, &end1);
			if (ans) {
				for (int j = start1 + 1; j <= end1; j++) {
					if (check[j]) ans = false;
					check[j] = true;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			int start2, end2, interval;
			scanf("%d %d %d", &start2, &end2, &interval);
			if (ans) {
				while (1) {
					for (int j = start2 + 1; j <= end2; j++) {
						if (check[j]) { ans = false; }
						check[j] = true;
					}
					start2 += interval;
					end2 += interval;
					if (start2 + 1 > 1000000) break;
					if (end2 > 1000000) {
						end2 = 1000000;
					}
				}
			}
		}
		if (ans == true) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");

	}

	system("pause");
    return 0;
}

