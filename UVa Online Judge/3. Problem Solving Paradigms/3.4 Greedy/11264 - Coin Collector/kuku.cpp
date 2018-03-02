// 11264.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// O(logn)
// 지금까지 더한 숫자의 합이 다음 수보다 작다면 그 수를 포함한다.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int coins[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("test.txt", "r", stdin);
	int t; cin >> t;
	while (t--) {
		memset(coins, 0, 1010 * sizeof(int));
		int n; cin >> n;
		int sum = 0; int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> coins[i];
		}
		for (int i = 0; i < n - 1; i++) {
			//cin >> coins[i];
			int temp = 0;
			temp = sum + coins[i];
			//cout << coins[i] << " temp = " << temp << " next = coin " << coins[i + 1] <<"\n";
			if (temp < coins[i + 1]) {
				sum = temp;
				cnt++;
			}
		}
		cout << cnt + 1 << "\n";
	}


	system("pause");
	return 0;
}



