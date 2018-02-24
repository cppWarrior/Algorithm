// 11389.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 정렬 안해도 됐을지도?
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int morning[110]; int after[110];
int main()
{
	int n, d, r;
	while (1) {
		cin >> n >> d >> r;
		if (n == 0 && d == 0 && r == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> morning[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> after[i];
		}
		sort(morning, morning + n);
		sort(after, after + n);
		reverse(after, after + n);
		
		int overpay = 0;
		for (int i = 0; i < n; i++) {
			int sum = morning[i] + after[i];
			if (sum > d) {overpay += sum - d;}
		}
		overpay = overpay * r;

		cout << overpay << "\n";

	}

	system("pause");
    return 0;
}

