// sogogibeef(limjeongmin@wustl.edu)
#include <bits/stdc++.h>

using namespace std;
int TC;
string tree;
map<string, int> satellite;
set<string> treeSet;
vector<string> treeVector;
int total;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //code here
    cin >>TC;
    cin.ignore();
    cin.ignore();

    while(TC--)
    {
        // Initialization of variables
        total = 0;
        treeSet.clear();
        satellite.clear();
        treeVector.clear();

        while(true)
        {
            if(!getline(cin, tree)||tree =="")
            {
                break; // Remember how to use getline to get inputs until next input is blank line break.
            }
            satellite[tree]++;
            treeSet.insert(tree);
            total ++;
        }

        // Use set to filter out duplicate elements and then assign the values to a vector for easier manipulation
        treeVector.assign(treeSet.begin(),treeSet.end());
        sort(treeVector.begin(),treeVector.end());

        //trees.erase(unique(trees.begin(),trees.end()),trees.end()); //unique elements vector : how to use just vectors to filter out duplicates

        /* //This block is not supported in C++98 environment
        for (auto &i:treeVector){
        cout << i << " " << setprecision(4) << fixed << satellite[i] / (double) total * 100 << "\n";
        }*/
        
        for(int i = 0; i < satellite.size(); i++)
        {
            cout << treeVector[i] << " " << setprecision(4) << fixed << satellite[treeVector[i]] / (double) total * 100 << "\n";
        }
       
        
        if (TC!=0)
        {
            cout <<"\n";
        }
    }
    return 0;
}
