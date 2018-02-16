// 732 - 2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// stack을 이용했습니다. 
// i와 o의 숫자가 정해져있습니다.
// 벡트레킹처럼 하나씩 진행했습니다.
// 정답이면 벡터 v에 저장.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
vector<char> v;
stack<char> st1;
string input, target;
int num; 
void search(int cnt_i, int cnt_o) {
	if (cnt_i == num && cnt_o == num) {
		int vsize = v.size();
		for (int j = 0; j < vsize; j++) {
			if(j != vsize - 1) cout << v[j] << " ";
			else if (j == vsize - 1) cout << v[j] << "\n";
		}
	}
	for (int i = 0; i < 2; i++) {
		if (i == 0) { //push
			if (cnt_i < num) {
				st1.push(input[cnt_i]);
				v.push_back('i');
				search(cnt_i + 1, cnt_o);
				st1.pop();
				v.pop_back();
			}
		}
		else if (i == 1) {
			if (cnt_o < num && !st1.empty()) {
				char a = st1.top();
				if (target[cnt_o] == a) {
					st1.pop();
					v.push_back('o');
					search(cnt_i, cnt_o + 1);
					st1.push(a);
					v.pop_back();
				}
			}
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	while (getline(cin, input), getline(cin, target)) {

		num = input.size();
		cout << "[\n";
		int input_size = input.size();
		int target_size = target.size();

		if (input_size == target_size && (input_size != 0 || target_size != 0)) { search(0, 0); }
		
		cout << "]\n";
		while (!st1.empty()) {
			st1.pop();
		}
		v.clear();
		input.clear();
		target.clear();
	}

	//system("pause");
    return 0;
}

