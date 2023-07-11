//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(const pair<double, pair<double, double>>& A, const pair<double, pair<double, double>>& B) {
    return A.first > B.first;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    vector<pair<double, pair<double, double>>> vec;

    for (int i = 0; i < n; i++) {
        vec.push_back(make_pair(1.0 * (arr[i].value) / arr[i].weight, make_pair(arr[i].value, arr[i].weight)));
    }

    sort(vec.begin(), vec.end(), cmp);

    double ans = 0;
    for (int i = 0; i < n && W > 0; i++) {
        if (vec[i].second.second <= W) {
            ans += vec[i].second.first;
            W -= vec[i].second.second;
        } else {
            ans += (W / vec[i].second.second) * vec[i].second.first;
            W = 0;
        }
    }

    return ans;
}

};


//Function to get the maximum total value in the knapsack.
    // double fractionalKnapsack(int W, Item arr[], int n)
    // {
    //     vector<double>vec;
    //     for(int i=0;i<n;i++){
    //         vec.push_back(double(arr[i].value/arr[i].weight));
    //     }
    //     sort(vec.begin(),vec.end());     reverse(vec.begin(),vec.end());   
    //or sort(vec.begin(), vec.end(), greater<double>());
        
    //     double ans=0;
    //     while(W!=0){
    //         for(int i=0;i<n;i++){
    //             if(arr[i].weight < W){
    //               ans+= arr[i].value;
    //               W -= arr[i].weight;
    //             } 
    //             else{
    //               ans+= (W/arr[i].weight) * arr[i].value;
    //               W =0;
    //             }  
    //         }
    //     }
    //     return ans;
    // }


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends