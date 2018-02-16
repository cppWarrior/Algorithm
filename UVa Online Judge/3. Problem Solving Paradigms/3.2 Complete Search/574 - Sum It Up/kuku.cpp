// 574.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// using backtracking
// save in the vectors and if it`s the same contents 
// then skip. 

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> tempvector;
vector<int> v[1000]; int cnt = 0; int flag = false;
int total, number; int arr[13]; bool check[13] = {false,};
void search(int idx, int sum) {
	//cout << idx << " " << sum << "\n";
	if (idx == number || sum > total) return;
	if (sum == total) {

		tempvector.clear();
		flag = true;
		bool same_vector_check = true;
		if (cnt != 0) { // 전의 벡터와 비교한다.
			for (int i = 0; i < 13; i++) { // 임시 벡터를 만든다. 
				if (check[i]) {	tempvector.push_back(arr[i]);}
			}
			int tempsize = tempvector.size();

			for (int q = 0; q < cnt; q++) {
				int k = v[q].size();
				if (k == tempsize) { // vector랑 크기가 같으면 비교한다.
					for (int i = 0; i < tempsize; i++) {
						if (tempvector[i] != v[q][i]) { // 다른 벡터이다.
							break;
						}
						if (tempvector[i] == v[q][i] && i == tempsize - 1) { // 같은 벡터이면
							same_vector_check = false;
						}
					}
				}
			}
			// samecheck = true 면 넣는다. 
			if (same_vector_check) {
				for (int i = 0; i < 13; i++) {
					if (check[i]) {
						v[cnt].push_back(arr[i]);
					}
				}
				cnt++;
			}

		}
		else { // cnt = 0 이면 그냥 넣는다. 
			for (int i = 0; i < 13; i++) {
				if (check[i]) {
					v[cnt].push_back(arr[i]);
				}
			}
			cnt++;
		}
	}
	for (int i = idx + 1; i < number; i++) {
		if (!check[i]) {
			check[i] = true;
			search(i, sum + arr[i]);
			check[i] = false;
		}
	}
}
int main()
{
	//freopen("test.txt", "r", stdin);
	while (1) {
		flag = false;
		memset(check, 0, 13 * sizeof(bool));
	
		scanf("%d %d", &total, &number);
		if (total == 0 && number == 0) break;
		for (int i = 0; i < number; i++) {
			scanf("%d", &arr[i]);
		}
		printf("Sums of %d:\n", total);
		for (int i = 0; i < number; i++) {
			check[i] = true;
			search(i,arr[i]);
			check[i] = false;
		}
		
		if (!flag) {
			printf("NONE\n");
		}
		else {
			for (int i = 0; i < cnt; i++) {
				int k = v[i].size();
				for (int j = 0; j < k; j++) {
					printf("%d", v[i][j]);
					if (j != k - 1) { printf("+"); }
					if (j == k - 1) printf("\n");
				}
				v[i].clear();
			}
		}
	}

	system("pause");
    return 0;
}

