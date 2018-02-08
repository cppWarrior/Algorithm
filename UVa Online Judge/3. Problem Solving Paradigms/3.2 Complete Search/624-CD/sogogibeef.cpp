// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int N, track, numTrack;
vector<int> playlist, cd, temp;
int trackLength;


int vectorSum(vector<int> v) {
    int sum = 0;
    for (auto &i:v) {
        sum += i;
    }
    return sum;
}


void makeTape(int sum, int index) {
    if (sum > N) return;
    if (index == numTrack) {
        if (sum > trackLength) {
            trackLength = sum;
            cd = temp;
        }
        return;
    }

    temp.push_back(playlist[index]);
    makeTape(sum + playlist[index], index + 1);

    temp.pop_back();
    makeTape(sum, index + 1);



}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    while (cin >> N) {
        cin >> numTrack;
        playlist.clear();
        cd.clear();
        temp.clear();
        trackLength = 0;
        bool need = true;


        for (int i = 0; i < numTrack; i++) {
            cin >> track;
            playlist.push_back(track);
        }
//
        if (vectorSum(playlist) <= N) {
            for (auto &i:playlist) {
                cout << i << " ";
            }
            cout << "sum:" << vectorSum(playlist) << "\n";
            need = false;
        }

        if(need){
            makeTape(0, 0);
            for (auto &i:cd) {
                cout << i << " ";
            }


            cout << "sum:" << trackLength << "\n";
        }

    }


    return 0;
}




