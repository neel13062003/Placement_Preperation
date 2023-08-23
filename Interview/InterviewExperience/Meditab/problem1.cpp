//Code : Neel Soni
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &vec) {
    unordered_set<int> presentNumbers;
    vector<int> missingNumbers;

    for (int num : vec) {
        presentNumbers.insert(num);
    }

    for (int i = 1; i <= 10; i++) {
        if (presentNumbers.find(i) == presentNumbers.end()) {
            missingNumbers.push_back(i);
        }
    }

    return missingNumbers;
}

int main() {
    vector<int> vec = {5,2,6};

    vector<int> ans = solve(vec);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
