//Link =  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    
    int solveRec(int index, int buy, vector<int>& prices, int limit) {
        if (index == prices.size() || limit == 0)
            return 0;
        
        int profit = 0;
        if (buy) {
            int buyKaro = -prices[index] + solveRec(index + 1, 0, prices, limit);
            int skipKaro = solveRec(index + 1, 1, prices, limit);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solveRec(index + 1, 1, prices, limit - 1);
            int skipKaro = solveRec(index + 1, 0, prices, limit);
            profit = max(sellKaro, skipKaro);          
        }
        return profit;
    }
    
    int solveMem(int index, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>>& dp) {
        if (index == prices.size() || limit == 0)
            return 0;
        
        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        
        int profit = 0;
        if (buy) {
            int buyKaro = -prices[index] + solveMem(index + 1, 0, prices, limit, dp);
            int skipKaro = solveMem(index + 1, 1, prices, limit, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solveMem(index + 1, 1, prices, limit - 1, dp);
            int skipKaro = solveMem(index + 1, 0, prices, limit, dp);
            profit = max(sellKaro, skipKaro);          
        }
        return dp[index][buy][limit] = profit;
    }
    
    int solveTab(vector<int>& prices, int limit) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(limit + 1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int currLimit = 1; currLimit <= limit; currLimit++) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + dp[index + 1][0][currLimit];
                        int skipKaro = dp[index + 1][1][currLimit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + dp[index + 1][1][currLimit - 1];
                        int skipKaro = dp[index + 1][0][currLimit];
                        profit = max(sellKaro, skipKaro);
                    }
                    dp[index][buy][currLimit] = profit;
                }
            }
        }
        return dp[0][1][limit];
    }
    
    int solveSpace(vector<int>& prices, int limit) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(limit + 1, 0)));
        
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int currLimit = 1; currLimit <= limit; currLimit++) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + next[0][currLimit];
                        int skipKaro = next[1][currLimit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + next[1][currLimit - 1];
                        int skipKaro = next[0][currLimit];
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][currLimit] = profit;
                }
            }
            next=curr;
        }
        return next[1][limit];
    }

    
    int maxProfit(vector<int>& prices) {
        // return solveRec(0,1,prices,2);
        
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1,vector<vector<int>> (2,vector<int>(3, -1)));
        // return solveMem(0, 1, prices, 2,dp);
        
        // return solveTab(prices,2);
        
        return solveSpace(prices,2);
    }
};