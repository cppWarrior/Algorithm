//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"
bool exist;


using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //id here
    string id;
    cin >> id;
    while(id!="#"){
        exist = next_permutation(id.begin(), id.end());
        if(!exist){
            cout << "No Successor\n";
        }else{
            cout << id << "\n";
        }
        cin >> id;
    }

    return 0;
}





