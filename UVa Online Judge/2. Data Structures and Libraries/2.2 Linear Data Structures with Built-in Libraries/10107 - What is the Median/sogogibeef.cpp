// Jeong-Min Lim (limjeongmin@wustl.edu)

//#include <bits/stdc++.h>
#include "/Users/jeongminlim/stdc++.h"

using namespace std;
int n, counter, median;
vector<int> numbers;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    while(cin>>n){
        counter++;
        numbers.push_back(n);
        sort(numbers.begin(),numbers.end());

        if (counter % 2 == 1){
            median = numbers[(counter - 1) / 2];
        }else{
            median =  ((long long int)numbers[(counter - 1) / 2] + numbers[(counter + 1) / 2]) / 2;;
        }
        cout << median << "\n";
    }



    return 0;
}





