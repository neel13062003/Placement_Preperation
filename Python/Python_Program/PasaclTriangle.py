class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        
        for i in range(numRows):
            row = [1] * (i+1)
            for j in range(1, i):
                row[j] = ans[i-1][j-1] + ans[i-1][j]
            ans.append(row)
        
        return ans

# class Solution {
# public:
#     vector<vector<int>> generate(int numRows) {
#         //Here possbile you can only declare rows and not columns
#         vector<vector<int>>ans(numRows);
        
#         for(int i=0;i<numRows;i++){
#             ans[i].resize(i+1,1);
#             for(int j=1;j<i;j++){
#                 ans[i][j] =  ans[i-1][j-1] + ans[i-1][j];
#             }
#         }
#         return ans;
#     }
# };