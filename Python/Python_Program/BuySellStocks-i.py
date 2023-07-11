class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
#         if len(prices)==0:
#             return 0
#         if len(prices)==1:
#             return prices[0]
        
#         profit = prices[0]
#         # maxi = float('-inf')
#         for i in range(1,len(prices)):
#             diff = prices[i]-prices[i-1]
#             profit = max(profit,diff)
#             maxi = max(profit,maxi)
        # return max(maxi, 0)    
    
        mini = prices[0];
        profit = 0;
        for i in range(1,len(prices)):
            profit = max(profit, prices[i]-mini);
            mini = min(mini,prices[i]);
        
        return profit;