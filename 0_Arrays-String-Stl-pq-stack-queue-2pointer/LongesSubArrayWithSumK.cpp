//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int m, int K) { 
       int left=0;int right=0;
       int sum=a[0];
       int maxLen=0;
       //Time Complexity = O(N); bcz inner loop not iterate each time till n still in worst situation
       while(right<n){
           
           while(left<=right && sum>K){
               sum-=a[left];
               left++;
           }
           
           if(sum==K) maxLen = max(maxLen,right-left+1);
           right++;
           if(right<n){
               sum+=a[right];
           }
       }
    }
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends