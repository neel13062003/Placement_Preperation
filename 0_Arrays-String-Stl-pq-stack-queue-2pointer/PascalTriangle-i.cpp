// Link  = https://leetcode.com/submissions/detail/963883788/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //Here possbile you can only declare rows and not columns
        vector<vector<int>>ans(numRows);
        
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1,1);
            for(int j=1;j<i;j++){
                ans[i][j] =  ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};