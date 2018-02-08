//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int elements; // 0 < elements <= 16


bool counter[30];
int ring[30];
bool isPrime[50];


void getPrime(int e) {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= sqrt(e); i++) { // check prime upto sqrt()
        if (isPrime[i] == true) {
            for (int j = i * 2; j <= e; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void ringMaker(int e) {
    if ((e == elements - 1) &&
        isPrime[ring[elements - 1] + ring[elements]]) {
        for (int i = 0; i < elements; i++) {
            if (i == elements - 1) {
                cout << ring[i];
            } else {
                cout << ring[i] << " ";
            }
        }
        cout << "\n";
        return;
    }

    for (int i = 2; i <= elements; i++) {
        if (!counter[i] && isPrime[ring[e] + i]) {
            counter[i] = true;
            ring[e + 1] = i;
            ringMaker(e + 1);
            counter[i] = false; // Just like in PICNIC problem, don't forget to change counter back to false... 
        }
    }

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    int counter = 1;
    memset(isPrime, true, sizeof(isPrime));
    getPrime(50);

    while (cin >> elements) {
        if(counter>1){
            cout << "\n"; // presentation error
        }
        cout << "Case " << counter << ":\n";
        counter++;
        ring[0] = 1;
        ring[elements] = 1;
        ringMaker(0);


    }


    return 0;
}





