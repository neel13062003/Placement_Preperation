//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int>ans;
        int minAmount=0;
        int maxAmount=0;

        sort(candies,candies+N);

        int i = 0, j = N - 1;

        // Calculate minimum amount
        while(i <= j){
            minAmount += candies[i];
            i++;
            j -= K;
        }

        i = 0;
        j = N - 1;

        // Calculate maximum amount
        while(i <= j){
            maxAmount += candies[j];
            i += K;
            j--;
        }

        ans.push_back(minAmount);
        ans.push_back(maxAmount);
        return ans;
        // vector<int>ans;
        // int minAmount=0;
        // int maxAmount=0;
        
        // sort(candies,candies+N);
        // //sort(candies.begin(),candies.end());
        
        
        // // priority_queue<int>pq1;        //maxheap
        // // priority_queue<int,vector<int>,greater<int>>pq1;      //min-heap
        // deque<int>pq1;  //min
        // deque<int>pq2;  //max
        
        // //Insert All Required Data in Priority_Queue
        // for(int i=0;i<N;i++){
        //     pq1.push_back(candies[i]);
        // }
        // reverse(candies,candies+N);
        // for(int i=0;i<N;i++){
        //  pq2.push_back(candies[i]);
        // }
        
        // int temp =K;
        // int store = K;
        
        // //For Min Cost -  pq2
        // while(!pq1.empty()){
        //     minAmount += pq1.front();
        //     pq1.pop_front();
           
           
        //   while(K-- && !pq1.empty()){
        //       int x = pq1.back();
        //       //pq1.erase(x);
        //       pq1.pop_back();
        //   }
        //   K=temp;
        // }
        
        
        // K=store;
        // //For Max Cost
        // while(!pq2.empty()){
        //     maxAmount += pq2.front();
        //     pq2.pop_front();
            
        //     while(temp-- && !pq2.empty()){
        //         int y = pq2.back();
        //         pq2.pop_back();
        //     }
        //     K=store;
        // }
     
        
        // ans.push_back(minAmount);
        // ans.push_back(maxAmount);
        // return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends