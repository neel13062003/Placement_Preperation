#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, vector<string>> myDictionary1;
    map<string, vector<string>> myDictionary2;

    // Insert key-value pairs
    myDictionary1["a"] = {"green"};
    myDictionary1["b"] = {"red", "blue"};
    myDictionary1["d"] = {"violet"};

    myDictionary2["b"] = {"green", "yellow", "red", "violet", "pink"};


    map<string, int> colorCount;

    // Count occurrences from myDictionary1
    for (const auto& pair : myDictionary1) {
        for (const auto& color : pair.second) {
            colorCount[color]++;
        }
    }

    // Count occurrences from myDictionary2
    for (const auto& pair : myDictionary2) {
        for (const auto& color : pair.second) {
            colorCount[color]++;
        }
    }



    for (const auto& pair : colorCount) {
        if(pair.second == 1){
            cout<<pair.first<<endl;
        }
    }

    return 0;
}
