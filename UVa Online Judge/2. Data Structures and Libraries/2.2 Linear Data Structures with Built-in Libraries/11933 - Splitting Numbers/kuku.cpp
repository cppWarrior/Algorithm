// 11933.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	while (1) {
		int n; scanf("%d", &n);
		if (n == 0) break;
		int even_cnt = 1;
		int a = 0, b = 0;
		int m = n; int idx = 0;
		while (m > 0) {
			if (m & 1) { // 마지막이 1인가?
				if (even_cnt % 2 != 0) { // 홀수번째이면 1을 넣는다.
					a = a | 1 << idx; // 1 을 추가한다. 
					even_cnt++;
				}
				else {
					even_cnt++;
				}
			}
			idx++;
			m = m >> 1;
		}
		b = n - a;
		printf("%d %d\n", a, b);
	}
	system("pause");
    return 0;
}

