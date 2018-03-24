// 10004.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// BFS를 이용함.
// 시간 복잡도: O(V+E) ?? 맞나ㅋㅋ

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int n; bool check; bool visited[200]; int colored[200]; // 1이면 흰 2면 검은
vector<int> v[200]; queue<pair<int,int>> q;
int main()
{
	while (cin >> n) {
		if (n == 0) break;
		int l; cin >> l;
		for (int i = 0; i < l; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		memset(visited, 0, 200 * sizeof(bool));
		memset(colored, 0, 200 * sizeof(int));
		check = true;

		q.push(make_pair(0, 1));
		visited[0] = true;
		colored[0] = 1;
		while (!q.empty() & check) {
			int value = q.front().first;
			int color = q.front().second;
			//cout <<"value = "<<value << " color = " << color << "\n";
			q.pop();
			for (int i = 0; i < v[value].size(); i++) {
				int next = v[value][i];
				//cout << "next = " << next << "\n";
				
				if (!visited[next]) { // 방문 ㄴㄴ
					visited[next] = true;
					if (color == 1) {
						colored[next] = 2;
						q.push(make_pair(next, 2));
					}
					else if (color == 2) { 
						colored[next] = 1;
						q.push(make_pair(next, 1)); 
					}
				}
				else { // 방문 했으면 확인
					if (colored[next] == color) {
						check = false;
					}
				}

				if (!check) break;
			}

		}

		if (check) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";

		for (int i = 0; i < 200; i++) {
			v[i].clear();
		}
		while (!q.empty()) q.pop();
	}


	system("pause");
    return 0;
}

