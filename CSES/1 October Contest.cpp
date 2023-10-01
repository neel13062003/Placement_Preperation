1 October Contest

A). Maximum Value of an Ordered Triplet I

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    long long store = (long long)(nums[i]-nums[j])*nums[k];
                    maxi = max(maxi,store);
                }
            }
        }
        return maxi;
    }
};


B). Maximum Value of an Ordered Triplet II

class Solution {
public:
    #define ll long long
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll>maxiR(n);
        
        int curr = nums[n-1];
        for(int i=nums.size()-1;i>=0;i--){
            curr = max(nums[i],curr);
            maxiR[i] = curr;
        }
        
        long long maxi = 0; 
        long long maxiL = nums[0];
        for(int i=1;i<n-1;i++){
            long long store = (maxiL-nums[i])*maxiR[i+1];
            maxi = max(maxi,store);
            maxiL = max(maxiL,nums[i]+0LL);
        }
        
        return maxi;
    }
};


C). Minimum Size Subarray in Infinite Array

class Solution {
public:
    int minSizeSubarray(vector<int>& vec, int target) {
        vector<int> nums;
        for(int i=0; i<500; i++){
            nums.insert(nums.end(), vec.begin(), vec.end());
        }
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                if(sum == target) minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};


D).  Count Visited Nodes in a Directed Graph


class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int index,int &count) {
        vis[index] = true;
        count++;
        for (int neighbor : adj[index]) {
            if (!vis[neighbor]) {
                dfs(adj, vis, neighbor,count);
            }
        }
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size(); // Number of nodes (assuming 0-based indexing).
        vector<int> ans(n);
        
        vector<vector<int>> adj(n); // Initialize adjacency list.
        
        for (int i = 0; i < edges.size(); i++) {
            int u = i; // Assuming the edges are given as indices of the target nodes.
            int v = edges[i]; // Assuming the edges represent connections from u to v.
            adj[u].push_back(v);
        }
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            vector<bool> vis(n, false);
            
            if (!vis[i]) {
                dfs(adj, vis, i,count);
            }
            
            ans[i] = count; 
        }
        
        return ans;
    }
};