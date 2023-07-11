/*
The time complexity of the backtracking solution to find all combinations of a set of n elements is O(2^n), where n is the size of the input set. This is because, for each element in the set, there are two possibilities: either it is included in the current combination, or it is not included. Therefore, there are a total of 2^n possible combinations.

In the modified implementation with a constraint of finding all combinations of size k, the time complexity is reduced to O(2^k), where k is the size of the desired combinations. This is because we limit the size of the combinations to k, and thus only generate combinations of size k instead of all possible combinations of the input set.

Note that this time complexity assumes that the size of the output (the number of possible combinations) is exponential in the size of the input. If, for example, we are only interested in a small number of combinations (less than 2^k), the time complexity can be less than O(2^k) in practice.
*/

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int start,int k) {

    if(temp.size()==k){
        res.push_back(temp);
    }
    //res.push_back(temp);

    for (int i = start; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        backtrack(nums, res, temp, i + 1,k);
        temp.pop_back();
    }
}

vector<vector<int>> getCombinations(vector<int>& nums,int k) {
    vector<vector<int>> res;
    vector<int> temp;
    //backtrack(nums, res, temp, 0);
    backtrack(nums, res, temp, 0,k);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int k=2;
    vector<vector<int>> combinations = getCombinations(nums,k);
    for (auto c : combinations) {
        for (auto num : c) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
