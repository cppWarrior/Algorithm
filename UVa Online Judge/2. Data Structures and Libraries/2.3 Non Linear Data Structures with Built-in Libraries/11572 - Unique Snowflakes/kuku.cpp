// 11572.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 배열을 지우니 런타임 에러가 해결됨

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	map<int, int> snow; int ans;
	//int arr[30000]; 
	int len = 0;
	int t; scanf("%d", &t);
	while (t--) {
		len = 0; ans = 0; snow.clear();
		//memset(arr, 0, sizeof(int) * 30000);

		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			//cout << "i " << i << " arr[i] = " << arr[i] << "\n";
			if (snow.count(a) == 0) {
				snow[a] = i;
				len++;
				if (len > ans) ans = len;
			}
			else {
				if (len > ans) ans = len;
				int prev = snow[a];
				int nowlen = i - prev;
				if (nowlen > len) len++;
				else {
					len = nowlen;
				}
				snow[a] = i;
				if (len > ans) ans = len;

			}
		}
		printf("%d\n", ans);
	}
	system("pause");
    return 0;
}

