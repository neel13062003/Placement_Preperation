class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++) {
            s += char('0' + i);
        }

        string result;

        while (n > 0) {
            int groupSize = factorial(n - 1);
            int index = (k - 1) / groupSize;

            result += s[index];
            s.erase(s.begin() + index);

            k = (k - 1) % groupSize + 1;
            n--;
        }

        return result;
    }

    int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
};

// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         string s;
//         for (int i = 1; i <= n; i++) {
//             s += char('0' + i);
//         }
//         cout << s << endl;
//         // Placeholder return value
//         // return "";
        
//         string nums = s;
//         vector<vector<char>> ans;
//         sort(nums.begin(), nums.end());
//         do {
//             ans.push_back(vector<char>(nums.begin(), nums.end()));
//         } while (next_permutation(nums.begin(), nums.end()));
        
        
//         string final_ans(ans[k-1].begin(), ans[k-1].end());
//         return final_ans;
//     }
// };