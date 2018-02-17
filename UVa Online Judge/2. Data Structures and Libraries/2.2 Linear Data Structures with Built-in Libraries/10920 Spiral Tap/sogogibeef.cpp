// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
// 어떤 수가 제일 처음 보드에 나타날 때 좌표를 구하고 보드 사이즈가 커질때마다 x, y축으로 1씩 더해주었습니다.


long long int size, coord;
long long int L, S; // largest square. smallest square.
long long int x, y;
vector<long long int> rng;
int run;
bool foundHere;
long long int side;
long long int stretch;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code begins
    cin >> size >> coord;
    while (size != 0 || coord != 0) {
        rng.clear();
        run = 0;
        foundHere = false;


        if (coord == 1) {
            x = 1;
            y = 1;
            for (int i = 0; i < size / 2; i++) {
                x++;
                y++;
            }
            cout << "Line = " << y << ", column = " << x << ".\n";

        } else {
            L = 1;

            while (coord > L * L) {
                L++;
            }
            S = L;
            L--;


            if (L % 2 == 0 && L != 0) {
                L -= 1;
                S -=1;
            }
//            cout << "L = " << L << "\n";



            side = ((L + 2) * (L + 2) - L * L) / 4;

            for (int j = L * L + 1; j < (L + 2) * (L + 2) + 1; j += side) {
                rng.clear();
                run++;
                for (int i = j; i < side + j; i++) {
                    rng.push_back(i);
                    if (coord == i) {
                        foundHere = true;
//                        cout << "L = " << L << "\n";

                        break;
                    }
                }

                if (foundHere) {
                    break;
                }
            }


            stretch = rng.size();

            if (foundHere == true) {
                if (run == 1) {
                    x = L + 1;
                    y = L + 2;
                    for (int i = 1; i < stretch; i++) {
                        x--;
                    }
                } else if (run == 2) {
                    x = 1;
                    y = L + 1;
                    for (int i = 1; i < stretch; i++) {
                        y--;
                    }

                } else if (run == 3) {
                    x = 2;
                    y = 1;
                    for (int i = 1; i < stretch; i++) {
                        x++;
                    }

                } else if (run == 4) {
                    x = L + 2;
                    y = 2;
                    for (int i = 1; i < stretch; i++) {
                        y++;
                    }
                }


                if (size > S){
                    x += (size-S) / 2;
                    y += (size-S) / 2;
                }




                cout << "Line = " << y << ", column = " << x << ".\n";

            }


        }


        cin >> size >> coord;
    }


    return 0;
}





