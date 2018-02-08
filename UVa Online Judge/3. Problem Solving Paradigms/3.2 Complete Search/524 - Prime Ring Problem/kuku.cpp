// 524.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int n; bool check[17] = { false, }; // 사용하면 true;
bool sosu[40] = {false,}; // sosu면 false;
int ans[17];
void eratos() {
	for (int i = 2; i < 41; i++) {
		int next = i;
		if (!sosu[next]) {
			while (next < 40) {
				next += i;
				sosu[next] = true;
			}
		}
	}
}
void print() {
	printf("1 ");
	for (int i = 1; i < n; i++) {
		if(i != n - 1) printf("%d ", ans[i]);
		else {
			printf("%d\n", ans[i]);
		}
	}
	//printf("\n");
}
void search(int prev, int cnt) {
	if (cnt == n) {
		//처음과 마지막 비교
		if (!sosu[prev + 1]) { // 정답이다.
			print();
		}
		else { return; }

		// 옳은 결과
	}
	for (int i = 2; i <= n; i++) {
		if (check[i]) { continue; }
		else if (!check[i]) { // 쓰지않은 숫자라면 
			if (!sosu[prev + i]) { // 소수이면 다음을 진행한다.
				check[i] = true;
				ans[cnt] = i;
				search(i, cnt + 1);
				check[i] = false;
				ans[cnt] = 0;
			}
		}
	}
}
int main()
{
	eratos(); // 소수를 구한다.
	int k = 0;
	while (scanf("%d", &n) != EOF) {
		memset(check, false, sizeof(check));
		if (k++) putchar('\n');
		printf("Case %d:\n", k);
		search(1, 1);
	}
	
	//system("pause");
    return 0;
}

