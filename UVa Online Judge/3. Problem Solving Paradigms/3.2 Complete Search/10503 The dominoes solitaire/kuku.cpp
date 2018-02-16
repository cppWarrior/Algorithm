// 10503.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// vector pair + backtracking

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int first1, first2, last1, last2; bool ans = false;
int n, m; bool check[100]; int cnt = 0;
vector<pair<int, int>> v[100];
void search(int x) {
	if (cnt > n) return;
	if (x == last1 && cnt == n) {
		ans = true;
	}
	for (int i = 0; i < m; i++) {
		if ((v[i].front().first == x || v[i].front().second == x) && !check[i]) {
			check[i] = true;
			cnt++;
			if (v[i].front().first == x && v[i].front().second != x) {
				search(v[i].front().second);
			}
			else if (v[i].front().first != x && v[i].front().second == x) {
				search(v[i].front().first);
			}
			else if (v[i].front().first == x && v[i].front().second == x) {
				search(v[i].front().first);
			}
			check[i] = false;
			cnt--;
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	while (1) {
		ans = false; cnt = 0;
		memset(check, 0, 100 * sizeof(bool));

		scanf("%d", &n);
		if (n == 0) break;
		scanf("%d", &m);
		scanf("%d %d", &first1, &first2);
		scanf("%d %d", &last1, &last2);

		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			if (a > b) v[i].push_back(make_pair(b,a));
			else {
				v[i].push_back(make_pair(a, b));
			}	
		}

		search(first2);
		if (ans) printf("YES\n");
		else {
			printf("NO\n");
		}
		for (int i = 0; i < m; i++) {
			v[i].clear();
		}
	}
	system("pause");
    return 0;
}

