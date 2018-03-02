// 12405.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
//  # 이 나오면 앞에 .의 숫자가 3으로 나눠 떨어지면 . 숫자를 벡터에 저장
// #.에서 다음 .은 새로운 시작을 합니다.
// 3으로 나눠떨어지지 않는경우 #은 .으로 생각한다.
// ## 이면 무조건 벡터에 넣어준다. 

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
string field2; int n; vector<int> v; int cnt = 0;
int main()
{
	freopen("test.txt", "r", stdin);
	int testcase; scanf("%d", &testcase);
	for (int z = 1; z <= testcase; z++) {
		scanf("%d\n", &n);
		cin >> field2;
		cnt = 0;
		int start = 0;

		// .이 나오기 시작하는 점을 찾는다. 
		for (int i = 0; i < n - 1; i++) {
			if (field2[i] == '.') {
				start = i;
				break;
			}
		}
		//cout << "start = " << start << "|   ";
		field2.push_back('#');
		field2.push_back('#');
		 // 수들을 세고 벡터에 넣는다. 
		for (int i = start; i <= n; i++) {
			if (field2[i] == '.') cnt++;
			else if (field2[i] == '#') {
				if (field2[i + 1] == '#') {
					v.push_back(cnt);
					cnt = 0;
				}
				else if (field2[i + 1] == '.') {
					if (cnt % 3 == 0) { 
						v.push_back(cnt);
						cnt = 0;
					}
					else {
						cnt++;
					}
				}
			}
			
		}
		int ans = 0;
		int vsize = v.size();
		for (int i = 0; i < vsize; i++) {
			//cout << v[i] << " ";
		}
		//cout << " |  ";
		for (int i = 0; i < vsize; i++) {
			if (v[i] % 3 == 0) {
				ans += v[i] / 3;
			}
			else {
				ans += (v[i] / 3) + 1;
			}
		}
		v.clear();
		cout << "Case " << z << ": " << ans << "\n";
		field2.clear();
	}
	system("pause");
    return 0;
}

