// 10107.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[10100];	int cnt = 0; int median;
	int input_num;

	while (1) {
		cin >> input_num;
		if (cin.fail()) break;
		arr[cnt] = input_num;
		cnt++; 
		sort(arr, arr + cnt);
		int median_idx = cnt / 2;
		if (cnt % 2 != 0) { // 홀수개이면 
			cout << arr[median_idx] << "\n";
		}
		else {
			int median_idx2 = median_idx - 1;
			int ans = (arr[median_idx] + arr[median_idx2]) / 2;
			cout << ans << "\n";
		}
	}

	system("pause");
    return 0;
}

