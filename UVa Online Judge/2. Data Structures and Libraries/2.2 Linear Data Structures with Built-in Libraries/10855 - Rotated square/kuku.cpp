// 146.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	while (1) {
		string str; string str2;
		cin >> str;
		str2 = str;
		if (str[0] == '#') break;

		int a = str.size();
		next_permutation(str.begin(), str.end());
		sort(str2.begin(), str2.end());
		if (str == str2) {
			cout << "No Successor\n";
		}
		else {
			for (int i = 0; i < a; i++) {
				cout << str[i];
			}
			cout << "\n";
		}
	}
	system("pause");
    return 0;
}

