// 11057 - 2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 정렬 후 이분탐색을 함.
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, money; int books[10100]; 
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("test.txt", "r", stdin);
	while (cin >> n) {
		// 초기화
		memset(books, 10100, sizeof(int));

		// 입력부
		for (int i = 0; i < n; i++) {
			cin >> books[i];
		}
		cin >> money;


		sort(books, books + n);
		int ans1, ans2;
		int ans_diff = 1000003;
		int first, second;

		for (int i = 0; i < n; i++) {
			first = books[i]; second = money - first;
			//cout << "first = " << first << " " << second << "\n";
			//cout << "low    mid    high\n";
			if (first < money && first <= second) { // 2분 탐색을 한다.
				int lo = i, high = n - 1;
				while (lo <= high) {
					int mid = (lo + high) / 2;
					//cout << books[lo] << " " << books[mid] << " " << books[high] << "\n";
					if (books[mid] == second) {
						int diff = second - first;
						if (diff < ans_diff) {
							ans_diff = diff;
							ans1 = first;
							ans2 = second;
						}
						break;
					}
					else if (books[mid] < second) {
						lo = mid + 1;
					}
					else if (books[mid] > second) {
						high = mid - 1;
					}

				}
			}
		}

		cout << "Peter should buy books whose prices are " << ans1 << " and " << ans2 << ".\n\n";

	}
    return 0;
}

