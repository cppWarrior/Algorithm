// 599.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// 1. vector에 graph를 입력합니다. 
// 2, 주어진 A,B,C,D 같은게 나오면 하나씩 가보면서 
// acorn인지 tree인지 확인합니다. 
// 트리는 E = V - 1 개의 간선을 갖는 것을 이용합니다. 

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
vector<int> v[26];
char nodes[30]; bool visited[30]; int node_cnt = 0, edge_cnt = 0;
void graph_finder(int x) { 
	// dfs 이용
	if (visited[x]) return; // 왔던 길임.
	visited[x] = true;
	//cout << "x = " << x << "\n";
	node_cnt++; 
	//cout << node_cnt << " " << edge_cnt << "\n";
	int v1_size = v[x].size();
	for (int i = 0; i < v1_size; i++) {
		int next = v[x][i];
		if (visited[next]) continue;
		else {
			edge_cnt++;
			graph_finder(next);
			//edge_cnt++;
		}
	}
}
int main()
{
	freopen("test.txt", "r", stdin);
	int t; scanf("%d", &t);
	while (t--) {
		// 초기화
		int acorn = 0; int tree = 0;
		memset(nodes, 0, sizeof(nodes));
		memset(visited, 0, sizeof(visited));

		while (1) {
			char a[29];	scanf("%s", &a);
			if (a[0] == '*') break;
			int first = a[1] - 65; // Z는 25
			int second = a[3] - 65;
			
			v[first].push_back(second);
			v[second].push_back(first);
		}

		string input2; cin >> input2;
		int input2_size = input2.size();
		for (int i = 0; i < input2_size; i++) {
			if (input2[i] == ',') continue;
			else { // 알파벳
				int num = input2[i] - 65;
				int vsize = v[num].size();
				if (vsize == 0) { // acorn입니다. 
					acorn++;
				}
				else { // tree인지 확인
					node_cnt = 0; edge_cnt = 0;
					graph_finder(num);
					//cout << node_cnt << " " << edge_cnt << "\n";
					if (node_cnt == edge_cnt + 1) tree++;
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
		for (int i = 0; i < 27; i++) {
			v[i].clear();
		}

	}
	system("pause");
    return 0;
}

