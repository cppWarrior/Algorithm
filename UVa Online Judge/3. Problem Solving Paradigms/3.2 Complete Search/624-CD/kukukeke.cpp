// 624 CD.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
//
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n; int tracks; int a[100]; bool check[100] = { 0, }; int sum = 0;
int ans_diff; int ans_sum = 0; int ans_cnt = 0; int diff; int cnt = 0;
void search(int x) {
	if (x == tracks) return;
	for (int i = x; i < tracks; i++) {
		if (!check[i]) {
			check[i] = true;
			sum += a[i];
			for (int i = 0; i < tracks; i++) {
				if (check[i]) { 
					//cout << a[i] << " ";
					cnt++;
				}
			}
			//cout << "\n";
			diff = n - sum;
			if (diff >= 0 && diff < ans_diff && sum <= n) {
				v.clear();
				for (int i = 0; i < tracks; i++) {
					if (check[i]) v.push_back(a[i]);
				}
				ans_sum = sum;
				ans_diff = diff;
				ans_cnt = cnt;
			}
			else if (diff >= 0 && diff == ans_diff && sum <= n) {
				if (cnt > ans_cnt) {
					v.clear();
					for (int i = 0; i < tracks; i++) {
						if (check[i]) v.push_back(a[i]);
					}
					ans_sum = sum;
					ans_diff = diff;
					ans_cnt = cnt;
				}
			}
			/*
			cout << "sum =  " << sum << "\n";
			cout << "cnt = " << cnt << "\n";
			cout << "ans_cnt = " << ans_cnt << "\n";
			cout << "\n";*/
			cnt = 0;

			search(i + 1);
			check[i] = false;
			sum -= a[i];
		}
	}	
}
int main()
{
	freopen("test.txt", "r", stdin);
	while (scanf("%d %d", &n, &tracks) == 2) {
		for (int i = 0; i < tracks; i++) {
			scanf("%d", &a[i]);
		}
		diff = n + 1;
		ans_diff = n;
		search(0);
		int k = v.size();
		//memset(check, false, sizeof(check));
		for (int i = 0; i < k; i++) {
			printf("%d ", v[i]);
		}
		printf("sum:%d\n", ans_sum);
	}
	//system("pause");
    return 0;
}

