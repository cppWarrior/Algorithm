// 10258.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 입출력이 너무 거지같네요.


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string>
#include <sstream>
using namespace std;
bool cmp(tuple<int, int, int>& i, tuple<int, int, int>& j) {
	if (get<0>(i) != get<0>(j)) { return get<0>(i) > get<0>(j); }
	else {
		if (get<1>(i) != get<1>(j)) { return get<1>(i) < get<1>(j); }
		else {
			return get<2>(i) < get<2>(j);
		}
	}
} 
int main()
{
	vector<tuple<int, int, int>> v;
	vector<tuple<int, int, int>>::iterator it;
	bool participate[110] = { 0, }; bool done[110][11];
	int team[110]; bool number[110][11] = {0,}; // 푼 문제의 수를 확인. 
	int time[110] = { 0, }; bool check[110][11] = {0,}; char letter;
	
	stringstream ss;
	string str;
	freopen("test.txt", "r", stdin);
	int t; 
	getline(cin, str);
	ss.clear();
	ss << str;
	ss >> t;
	t++;
	//cout << t;
	for(int l = 0; l < t; l++) {
		//cout << "l = " << l << "\n";
		// 초기화
		memset(done, 0, sizeof(done));
		memset(team, 0, sizeof(team));
		memset(number, 0, sizeof(number));
		memset(time, 0, sizeof(time));
		memset(check, 0, sizeof(check));
		memset(participate, 0, sizeof(participate));
		v.clear();

		int a, b, c; char d; string str;
		while (getline(cin,str)) {
			if (str.empty()) break;
		
			ss.clear();
			ss << str;
			ss >> a >> b >> c >> d;
			//scanf(" %d %d %c\n", &b, &c, &d);
			participate[a] = true;
			//cout << a << " " << b << " " << c << " " << d << "\n";
			if (d == 'I') check[a][b] = true;
			else if (d == 'C' && !done[a][b]) {
				done[a][b] = true;
				number[a][b] = true;
				if (check[a][b]) { // 틀렸던 문제 + penalty time
					time[a] = time[a] + c + 20;
				}
				else time[a] = time[a] + c;
				//cout << "time[" << a << "] = " << time[a] << "\n";
			}
			else continue;
		}

		for (int i = 1; i <= 100; i++) {
			if (participate[i]) {
				int cnt = 0;
				for (int j = 1; j <= 9; j++) {
					if (number[i][j]) cnt++;
				}
				v.push_back(make_tuple( cnt,time[i],i ));
			}
		}
		sort(v.begin(), v.end(),cmp);

		for (const auto& i : v) {
			cout << get<2>(i) << " " << get<0>(i) << " " << get<1>(i) << "\n";
		}

		if (l == 0 || l == t - 1) continue;
		else {
			printf("\n");
		}

	}
	
	system("pause");
    return 0;
}

