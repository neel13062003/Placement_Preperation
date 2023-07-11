//Link = https://leetcode.com/submissions/detail/930101198/

// class Solution {
// public:
    
//     void display(vector<vector<char>>& ans, int n, string s) {
//         vector<char> vec;
//         for (int i = 0; i < n; i++) {
//             vec.push_back(s[i]);
//         }
//         ans.push_back(vec);
//     }
    
//     void findPermutations(vector<vector<char>>& ans, int n, string s) {
//         sort(s.begin(), s.end());
//         do {
//             display(ans, n, s);
//         } while (next_permutation(s.begin(), s.end()));
//     }
    
//     string getPermutation(int n, int k) {
//         string s="";
//         for(int i=1;i<=n;i++){
//             s +=i + '0'; // convert int to char
//         }
        
//         int x = s.size();
//         vector<vector<char>>ans;
//         findPermutations(ans, x, s);
        
//         vector<string> ans1;
//         for (int i = 0; i < ans.size(); i++) {
//             ans1.push_back(string(ans[i].begin(), ans[i].end()));
//         }
        
//         return ans1[k-1]; // return k-1th permutation
//     }
// };
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n, 1);
        for (int i = 1; i < n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }
        
        vector<char> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = '1' + i;
        }
        
        string result;
        k--;
        for (int i = n; i >= 1; i--) {
            int index = k / factorials[i - 1];
            result.push_back(digits[index]);
            digits.erase(digits.begin() + index);
            k %= factorials[i - 1];
        }
        
        return result;
    }
};

/*For the previous question, the time complexity of the original solution is O(n * n!), where n is the number of digits. This is because we are generating all the permutations of the digits, which takes O(n!) time, and for each permutation, we are iterating over the n digits to create a vector of characters, which takes O(n) time. So the overall time complexity is O(n * n!).

For the optimized solution, the time complexity is O(n^2), which is much faster than the previous solution. This is because we are computing the factorials and the indices of the digits in O(n) time, and then iterating over the digits from right to left, which takes O(n) time. So the overall time complexity is O(n^2).*/
