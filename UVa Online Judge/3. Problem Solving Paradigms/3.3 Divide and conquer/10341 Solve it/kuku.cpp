// 10341.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 이분 탐색을 이용.
// 원래는 정답이 ans < 0.0001 이면 탐색을 멈췄지만 
// 계속 WA뜨고 틀린테스트 케이스도 못찾겠어서 
// 이분 탐색 반복을 30번 정도 돌림 
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int p, q, r, s, t, u;
double func(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
int main()
{
	freopen("test.txt", "r", stdin);
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		bool check = false;	double left = 0.0, right = 1.0;
		double mid;
		

		if ((func(0) > 0 && func(1) > 0) || (func(1) < 0 && func(0) < 0)) {
			cout << "No solution\n";
		}
		else {
			int m = 30;
			while (m--) {
				mid = (left + right) / 2;
				//cout <<left <<" "<<right << " "<< mid << " value =  " << func(mid) << "\n";
				if (func(mid) > 0) {
					left = mid;
				}
				else {
					right = mid;
				}
			}
			cout << fixed;
			cout.precision(4);
			cout << left << "\n";
		}
	}
	system("pause");
    return 0;
}

