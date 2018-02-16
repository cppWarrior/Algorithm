// 10901.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	freopen("test.txt", "r", stdin);
	int clock = 0; bool check = false; // true면 반대편으로 이동
	bool ferry = 0; // 0 왼쪽, 1 오른쪽
	queue<pair<int,int>> q_left; // 왼쪽 
	queue<pair<int,int>> q_right; // 오른쪽
	vector<pair<int, int>> v;
	vector<pair<int, int>>::iterator it;
	int testcase; scanf("%d", &testcase);
	while(testcase--) {
		v.clear();
		clock = 0;
		ferry = 0;
		check = false;
		int order = 1;
		int n, t, m; 
		scanf("%d %d %d", &n, &t, &m);
		for (int i = 0; i < m; i++) {
			int a; char b[10];
			scanf("%d %s", &a, &b);
			if (b[0] == 'l') q_left.push(make_pair(a,order));
			else q_right.push(make_pair(a, order));
			order++;
		}

		while (!q_left.empty() || !q_right.empty()) {
			//cout << "ferry = " << ferry << " clock = " << clock << "\n";
			for (int j = 0; j < n; j++) {
				if (!ferry) { // ferry는 왼쪽에 있다. 
					int lc = -1, rc = -1;
					if (!q_left.empty() && q_left.front().first <= clock) lc = q_left.front().first;
					if (!q_right.empty()) rc = q_right.front().first;
					if (lc == -1) { // 이동만
						if (rc <= clock && rc != -1) {
							check = true;
						}
					}
					else if (lc != -1) { // 저장 후 이동
						int left_first = q_left.front().first;
						if (left_first <= clock) {
							//printf("%d\n", clock + t);
							v.push_back(make_pair(q_left.front().second, clock + t));
							q_left.pop();
							check = true;
						}
					}
				}
				else if (ferry) {
					int lc = -1, rc = -1;
					if (!q_left.empty()) lc = q_left.front().first;
					if (!q_right.empty() && q_right.front().first <= clock) rc = q_right.front().first;
					if (rc == -1) { // 이동만
						if(lc <= clock && lc != -1) check = true;
					}
					else if (rc != -1) {
						int right_first = q_right.front().first;
						if (right_first <= clock) {
							//printf("%d\n", clock + t);
							v.push_back(make_pair(q_right.front().second, clock + t));
							q_right.pop();
							check = true;
						}
					}
				}
			}

			if (check) {
				if (!ferry) ferry = true;
				else ferry = false;
				check = false;
				clock += t;
			}
			else {
				clock += 1;
			}
		}

		sort(v.begin(), v.end());
		for (int aa = 0; aa < m; aa++) {
			cout << v[aa].second << "\n";
		}
		if(testcase != 0) cout << "\n";
	}
	system("pause");
	return 0;
}

