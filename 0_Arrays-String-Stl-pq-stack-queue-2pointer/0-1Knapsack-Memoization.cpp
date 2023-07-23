//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solveMem(int start,vector<vector<int>>&dp,int W,int wt[],int val[],int n){
        if (start == n || W == 0)return 0;
        
        if(dp[start][W] != -1) return dp[start][W];
        
        //either take or not take
        int ans;
        if (wt[start] > W)
            //notTake;
            ans = solveMem(start + 1, dp, W, wt, val, n);  
        else
            //max(Take,NotTake);
            ans = max(solveMem(start + 1, dp, W, wt, val, n), val[start] + solveMem(start + 1, dp, W - wt[start], wt, val, n));

        return dp[start][W] = ans;
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return solveMem(0, dp, W, wt, val, n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends