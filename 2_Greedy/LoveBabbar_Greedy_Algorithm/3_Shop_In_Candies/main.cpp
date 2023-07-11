//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //nLOG(n)
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        //for minimum Rupess
        //Each Perchase We have K candies Free

        //Taking candies chaeper and take free candies constly
        int mini=0;
        int buy=0;                     //buy 0 index thi karsu
        int free=N-1;                  //Free Last index thi karsu
        while(buy<=free){
            mini=mini+candies[buy];
            buy++;
            free=free-K;
        }

        //For Max Candie
        int maxi=0;
        buy=N-1;                  //buy last index thi karsu
        free=0;                   //Free 0 thi karsu
        while(buy>=free){
            maxi=maxi+candies[buy];
            buy--;
            free=free+K;
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
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
