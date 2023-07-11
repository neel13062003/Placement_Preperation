//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {


      //using priority queue we find two min
       priority_queue<long long,vector<long long>,greater<long long>> pq;

       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }

       long long cost=0;
       while(pq.size()>1){
           long long first=pq.top();
           pq.pop();

           long long second=pq.top();
           pq.pop();

           long long mergeLength=first+second;
           cost=cost+mergeLength;

           pq.push(mergeLength);
       }
       return cost;






















       /* sort(arr,arr+n);                   // 2  3 4 6
        int sum=0;
        int total=0;
        for(int i=0;i<n;i++){
            total=total+arr[i];
        }
        sum=arr[0]+arr[1];
        for(int i=2;i<n-2;i++){
            sum=arr[i]+sum;
        }
        return total+sum;*/
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
