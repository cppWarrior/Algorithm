// 10496.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int t, x, y, startx, starty; int map[21][21]; bool visited[15];
vector<int> v[15]; int m; int ans = 1000000;
void search(int next, int sum, int cnt) {
	//cout << next << " ";
	if (cnt == m + 1) { // 다 방문했으면 결과랑 비교
		int result = sum + map[next][0];
		//cout << "result = " << result << "\n";
		if (result < ans) ans = result;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (!visited[i]) {
			visited[i] = true;
			//cout << "map[next][i] = " << map[next][i] << "\n";
			//cout << sum + map[next][i] << "\n";
			search(i, sum + map[next][i], cnt + 1);
			visited[i] = false;
		}
	}

}
int main()
{
	freopen("test.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cin >> startx >> starty;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			int a, b; cin >> a >> b;
			v[i].push_back(a);
			v[i].push_back(b);
		}
		// 초기화
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				map[i][j] = 0;
			}
		}
		ans = 100000;
		for (int i = 0; i < 15; i++) {
			visited[i] = 0;
		}

		// start -> 위치점들: start는 0
		for (int i = 1; i <= m; i++) {
			int a = v[i][0] - startx;
			int	b = v[i][1] - starty;
			if (a < 0) a = a*-1;
			if (b < 0) b = b*-1;
			map[0][i] = a + b;
			map[i][0] = a + b;
		}

		for (int i = 1; i <= m; i++) {
			int refx = v[i][0]; int refy = v[i][1];
			for (int j = 1; j <= m; j++) {
				int a = v[j][0] - refx;
				int b = v[j][1] - refy;
				if (a < 0) a = a*-1;
				if (b < 0) b = b*-1;
				map[i][j] = a + b;
				map[j][i] = a + b;
			}
		}

		visited[0] = true;
		for (int i = 1; i <= m; i++) {
			//cout << "0 ";
			visited[i] = true;
			search(i, map[0][i], 2);
			visited[i] = false;
		}
		cout << "The shortest path has length " << ans << "\n";

		for (int i = 0; i <= m; i++) v[i].clear();


	}
	system("pause");
    return 0;
}

