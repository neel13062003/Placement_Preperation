//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solveRec(int wt[],int val[],int index,int capacity){
        if(index==0){
            if(wt[0]<= capacity){
                return val[0];
            }else{
                return 0;
            }
        }
        
        int include=0;
        if(wt[index]<= capacity) include = val[index]+ solveRec(wt,val,index-1,capacity-wt[index]); 
        int exclude = 0 + solveRec(wt,val,index-1,capacity);
        
        int ans = max(include,exclude);
        return ans;
    }
    
    int solveMem(int wt[],int val[],int index,int capacity,vector<vector<int>>&dp){
        if(index==0){
            if(wt[0]<= capacity){
                return val[0];
            }else{
                return 0;
            }
        }
        
        if(dp[index][capacity] != -1) return dp[index][capacity]
        
        int include=0;
        if(wt[index]<= capacity) include = val[index]+ solveRec(wt,val,index-1,capacity-wt[index],dp); 
        int exclude = 0 + solveRec(wt,val,index-1,capacity,dp);
        
        int ans = max(include,exclude);
        return d[index][capacity]=ans;
    }
    
    int solveTab(int wt[],int val[],int n,int capacity){
       vector<vector<int>>dp(n,vector<int>(capacity+1,-1)); 
       
       for(int W=wt[0];W<=capacity;W++){
            if(wt[0]<= capacity){
               dp[0][W]=val[0];
            }else{
                dp[0][W]=0;
            }
       }
       
       
       for(int index=1;index<n;index++){
           for(int w=0;w<=capacity;w++){
               int include=0;
               if(wt[index] <= W){
                   include = val[index]+dp[index-1][W-weight[index]];
               }
               int exclude= 0+ dp[index-1][W];
               
               dp[index][W]=max(include,exclude);
           }
       }
       return dp[n-1][capacity];
    }
    
    
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return solveRec(wt,val,n-1,W);
        
        // vector<vector<int>>dp(W+1,vector<int>(W+1,-1));
        // return solveMem(wt,val,n-1,W,dp);
        
        return solveTab(wt,val,n-1,W);
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