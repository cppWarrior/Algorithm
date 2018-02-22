// 183.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// time limit 

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int arr[220][220]; int row1, col1; int idx = 0;
void b_input(int x, int y, string& str) {
	int idx = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			//cout << str[idx] << " ";
			arr[i][j] = str[idx] - 48;
			//cout << arr[i][j] << " ";
			idx++;
		}
	}
}
bool same(int x, int y, int n, int m) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + m; j++) {
			if (arr[x][y] != arr[i][j]) return false;
		}
	}
	return true;
}
void d_out(int row, int col, int row_size, int col_size) {
	// 원소들이 다 같은지 확인.
	if (row_size == 0 || col_size == 0) return;
	//if (row < 0 || row >= row1 || col < 0 || col >= col1) return;
	//cout << "row = " << row << " col =  " << col << "\n";
	if (same(row, col, row_size, col_size)) {
		cout << arr[row][col];
	}
	else {
		// 나눈다.
		int row_top, row_bottom, col_left, col_right;
		cout << "D";
		if (row_size % 2 == 0) { // 짝수이면 
			row_top = row_size / 2;
			row_bottom = row_size / 2;
		}
		else {
			row_top = (row_size / 2) + 1 ;
			row_bottom = row_size / 2;
		}
		if (col_size % 2 == 0) {
			col_left = col_size / 2;
			col_right = col_size / 2;
		}
		else {
			col_left = (col_size / 2) + 1;
			col_right = col_size / 2;
		}
		d_out(row, col, row_top, col_left);
		d_out(row, col + col_left, row_top, col_right);
		d_out(row + row_top, col, row_bottom, col_left);
		d_out(row + row_top, col + col_left, row_bottom, col_right);
	}
}
void d_in(int row, int col, int row_size, int col_size, string& str) {
	if (row_size == 0 || col_size == 0) return;
	if (str[idx] == 'D') { 
		idx++;
		int row_top, row_bottom, col_left, col_right;
		if (row_size % 2 == 0) { // 짝수이면 
			row_top = row_size / 2;
			row_bottom = row_size / 2;
		}
		else {
			row_top = (row_size / 2) + 1;
			row_bottom = row_size / 2;
		}
		if (col_size % 2 == 0) {
			col_left = col_size / 2;
			col_right = col_size / 2;
		}
		else {
			col_left = (col_size / 2) + 1;
			col_right = col_size / 2;
		}
		d_in(row, col, row_top, col_left,str);
		d_in(row, col + col_left, row_top, col_right,str);
		d_in(row + row_top, col, row_bottom, col_left,str);
		d_in(row + row_top, col + col_left, row_bottom, col_right,str);
	}
	else { // 채운다.
		for (int r = row; r < row + row_size; r++) {
			for (int s = col; s < col + col_size; s++) {
				cout << str[idx];
			}
		}
		idx++;
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	while (1) {
		//초기화
		idx = 0;
		memset(arr, 0, sizeof(arr));

		char a; 
		cin >> a;
		if (a == '#') break;
		cin >> row1 >> col1;
		string str;
		cin >> str;
		//cout << a << " " << row1 << " " << col1 << "\n";
		if (a == 'B') {
			cout << "D   " << row1 << "   " << col1 << "\n";
			b_input(row1, col1, str);
			d_out(0, 0, row1, col1);
			cout << "\n";
		}
		else if (a == 'D') {
			cout << "B   " << row1 << "   " << col1 << "\n";
			d_in(0,0,row1,col1,str);
			cout << "\n";
			//b_out(row1,col1);
		}
	}

	system("pause");
    return 0;
}

