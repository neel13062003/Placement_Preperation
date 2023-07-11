//Link = https://leetcode.com/submissions/detail/963881157/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex + 10);
        
        for(int i = 0; i <= rowIndex; i++){
            ans[i].resize(i + 1, 1);
            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        
        vector<int> ans1;
        
        for(int j = 0; j <= rowIndex; j++){
            ans1.push_back(ans[rowIndex][j]);
        }
        
        return ans1;
    }
};