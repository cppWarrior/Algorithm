// 10920 - 2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 마지막 숫자에서 시작합니다.
// 아래, 왼쪽, 위 3번 움직이고 
// 오른쪽으로 1번 그리고 1칸 아래로 내려가면 2번째 작은 네모가 나옴
// 같은 걸 반복
// 반복하는 도중 p >= edge 이면 좌표를 구하고 정답 
// 반드시 long long을 써야함.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
long long sz, p; bool anscheck; long long length; long long ans_l, ans_col;
int main()
{
	while (1) {
		scanf("%lld %lld", &sz, &p);
		if (sz == 0 && p == 0) break;
		anscheck = false;
		length = sz - 1;
		// length 계산이 잘못된듯.
		long long edge = sz*sz;
		//cout << edge << "\n";
		int line = sz, col = sz;
		if (edge == p) { ans_l = line; ans_col = col; anscheck = true; }
		while (1) {
			if (anscheck) break;
			// 3번 움직인다. 
			for (int i = 0; i < 3; i++) {
				edge -= length;
				if (i == 0) { line -= length; }
				else if (i == 1) { col -= length; }
				else if (i == 2) { line += length; }
				//cout << "edge = " << edge << " line = " << line << " col = " << col << "\n";
				if (edge == p) { ans_l = line; ans_col = col; anscheck = true; }
				if (edge < p) {
					long long diff = p - edge; anscheck = true;
					if (i == 0) { ans_l = line + diff; ans_col = col; }
					else if (i == 1) { ans_l = line; ans_col = col + diff; }
					else if (i == 2) { ans_l = line - diff; ans_col = col;}
				}
				if (anscheck) break;
			}
			length--;
			if (anscheck) break;
			// 오른쪽으로 한번 
			edge -= length;
			col += length;
			//cout << "edge = " << edge << " line = " << line << " col = " << col << "\n";
			if (edge == p) { ans_l = line; ans_col = col; anscheck = true; }
			if (edge < p) {
				long long diff = p - edge; anscheck = true;
				ans_l = line; ans_col = col - diff;
			}
			if (anscheck) break;
			// 아래로 한번
			edge--; line--; length--;
			//cout << "edge = " << edge << " line = " << line << " col = " << col << "\n";
			if (edge == p) { ans_l = line; ans_col = col; anscheck = true; }
			if (anscheck) break;
		}
		printf("Line = %lld, column = %lld.\n", ans_l, ans_col);
	}

	system("pause");
    return 0;
}

