// 1260.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int a[1100], b[1100];
	int t; cin >> t;
	while (t--) {
		memset(b, 0, 1100 * sizeof(int));
		memset(a, 0, 1100 * sizeof(int));
		int n; cin >> n;
		for (int i = 0; i < n; i++) {cin >> a[i];}
		for (int i = 1; i < n; i++) {
			int ref = a[i]; int cnt = 0;
			for (int j = 0; j < i; j++) {
				if (a[j] <= ref) cnt++;
			}
			b[i - 1] = cnt;
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans += b[i];
		}
		cout << ans << "\n";
	}
	system("pause");
    return 0;
}

