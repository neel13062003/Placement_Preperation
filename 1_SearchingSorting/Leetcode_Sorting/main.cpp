#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "Solution.h" // Assuming the solution is in a header file named Solution.h


using namespace std;

int main() {
    vector<int> digits = {2,2,8,8,2};
    Solution sol;
    vector<int> evenNumbers = sol.findEvenNumbers(digits);
    for (int i = 0; i < evenNumbers.size(); i++) {
        cout << evenNumbers[i] << " ";
    }
    cout << endl;
    return 0;
}
