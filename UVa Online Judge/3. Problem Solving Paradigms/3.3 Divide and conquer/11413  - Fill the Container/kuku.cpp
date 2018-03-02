// 11413.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#define vesselmax 1000000000
using namespace std;
int vessel[1100]; int n, m; int ans;
bool check(int x) {
	int container = x;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (vessel[i] > container) {
			if (cnt == m) return false;
			container = x;
			cnt++;
		}
		container -= vessel[i];
	//	cout << container << " " << cnt << "\n";
	}
	return true;
}
int main()
{
	while (cin >> n >> m) {
		int lo = 1;
		for (int i = 0; i < n; i++) { 
			cin >> vessel[i]; 
			if (vessel[i] > lo) lo = vessel[i];
		}
		int hi = 1000000000; int mid; int ans;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			cout << lo << " " << hi << " " << mid << " " << check(mid) << "\n";

			if (!check(mid)) { // lo를 키운다.
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
				ans = mid;
			}
		}
		cout << ans << "\n";
	}
	
	system("pause");
    return 0;
}

