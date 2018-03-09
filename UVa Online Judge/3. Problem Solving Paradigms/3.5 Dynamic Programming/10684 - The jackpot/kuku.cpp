// 10684.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 카데인 알고리즘 - DP
// 더하다가 합이 0 이하로 나오면 그 배열은 0으로 바꿔준다. 
// 그리고 구 부분에서 합을 새로 시작한다. 
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int n; int arr[11000]; int dp[11000]; int ans, sum;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		ans = 0; sum = 0;
		memset(arr, 0, 11000 * sizeof(int));

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
			//cout << sum << "\n";
			if (sum < 0) { // 합이 0 아래로 내려가면 여기서 새로 시작한다.
				arr[i] = 0;
				sum = 0;
			}
			if (sum > ans) ans = sum;
		}

		// 출력부
		if (ans == 0) printf("Losing streak.\n");
		else {
			printf("The maximum winning streak is %d.\n", ans);
		}
	}
	system("pause");
    return 0;
}

vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
