// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>

#include "/Users/jeongminlim/stdc++.h"

using namespace std;

int n, m, s;
// N S L O : 북 남 동 서
// D E F : 왼쪽, 오른쪽, 앞으로
// N 0, L 1, S 2, O 3; 4

/*          N
 *
 *  E   L   4   O   D
 *
 *          S
 */


char board[110][110];
char cell;
int nowx, nowy, dir;
char instr;
int cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here

    while (cin >> n >> m >> s) {
        if ((n == 0 && m == 0 && s == 0)) {
            break;
        }

        memset(board, 0, sizeof(board));
        dir = 0;
        nowx = 0;
        nowy = 0;
        nowx = 0;
        nowy = 0;
        cnt = 0;


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> cell;
                board[i][j] = cell;
                if (cell == 'N') {
                    dir = 0;
                    nowx = j;
                    nowy = i;
                    board[i][j] = '.';
                } else if (cell == 'L') {
                    dir = 1;
                    nowx = j;
                    nowy = i;
                    board[i][j] = '.';
                } else if (cell == 'S') {
                    dir = 2;
                    nowx = j;
                    nowy = i;
                    board[i][j] = '.';
                } else if (cell == 'O') {
                    dir = 3;
                    nowx = j;
                    nowy = i;
                    board[i][j] = '.';
                }

            }
        }


        for (int i = 0; i < s; i++) {
            cin >> instr;
            if (instr == 'D') {
                dir = (dir + 1) % 4;
            } else if (instr == 'E') {
                dir = (dir - 1 + 4) % 4;
            } else {
                if (dir == 0) {
                    if (nowy - 1 > 0) {
                        nowy -= 1;

                        if (board[nowy][nowx] == '#') {
                            nowy += 1;

                        } else if (board[nowy][nowx] == '*') {
                            cnt++;
                            board[nowy][nowx] = '.';
                        }
                    }
                } else if (dir == 1) {
                    if (nowx + 1 <= m) {
                        nowx += 1;

                        if (board[nowy][nowx] == '#') {
                            nowx -= 1;

                        } else if (board[nowy][nowx] == '*') {
                            cnt++;
                            board[nowy][nowx] = '.';
                        }
                    }
                } else if (dir == 2) {
                    if (nowy + 1 <= n) {
                        nowy += 1;

                        if (board[nowy][nowx] == '#') {
                            nowy -= 1;

                        } else if (board[nowy][nowx] == '*') {
                            cnt++;
                            board[nowy][nowx] = '.';
                        }
                    }
                } else if (dir == 3) {
                    if (nowx - 1 > 0) {
                        nowx -= 1;

                        if (board[nowy][nowx] == '#') {
                            nowx += 1;

                        } else if (board[nowy][nowx] == '*') {
                            cnt++;
                            board[nowy][nowx] = '.';
                        }
                    }
                }
            }
        }

        cout << cnt << "\n";

    }
    return 0;
}






