// 12032.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 최대한 계단을 많이 밟고 가는게 이득임
// 정답을 위해 이분 탐색 부분을 약간 조정함.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int t, n; int arr[100100];
bool search(int k) {
	int power = k;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (pos + power < arr[i]) return false;
		else if (pos + power == arr[i]) {
			power--;
			pos = arr[i];
		}
		else if (pos + power > arr[i]) {
			pos = arr[i];
		}

	}
	return true;
}
int main()
{
	freopen("test.txt", "r", stdin);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
		}
		int lo = 1; int hi = arr[n - 1];
		int mid; int ans = arr[n-1];
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
			//cout << lo << " " << mid << " " << hi << " ";
			//cout << search(mid) << "\n";
			if (search(mid)) {  
				hi = mid;
				ans = mid;
			}
			else {
				lo = mid + 1;
			}

		}
		printf("Case %d: %d\n", i, ans);

	}

    return 0;
}

