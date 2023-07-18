//SubArray Standard Problems 



A ----> 65
B ----> 66
..etc

a ----> 97
b ----> 98  


1) Maximum Subarray with returning string with ascii value 
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
        map<char,int> mp;
       
       for(int i=0;i<n;i++)
       {
           mp[x[i]]=b[i];
       }
        string temp,global_ans;
        int sum=0,global_sum=INT_MIN;
        
        for(int i=0;i<w.size();i++){
            if(mp.find(w[i])!=mp.end()){
               sum=sum+mp[w[i]];        
            }
            else{
                if(w[i]<=90)
                 sum=sum +(w[i]-'A'+65);
                else
                 sum=sum+(w[i]-'a'+97);
            }
            temp.push_back(w[i]);
            if(global_sum<sum){
                global_sum=sum;
                global_ans=temp;
            }
            if(sum<0){
                sum=0;
                temp="";
            }
        }
      return global_ans;
      }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}


//Subarray with given sum
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    // vector<int> subarraySum(vector<int>arr, int n, long long s){
            //When Solve Pair Problem
    //     vector<int>ans;
    //     sort(arr.begin(),arr.end());
    //     int left=0;
    //     int right=n-1;
    //     while(left<right){
    //         if(arr[left]+arr[right]==s){
    //             ans.push_back(left);
    //             ans.push_back(right);
    //         }
    //         else if(arr[left]+arr[right]>s){
    //             right--;
    //         }else{
    //             left++;
    //         }
    //     }
    //   return ans;
    //}
     vector<int> subarraySum(vector<int>arr, int n, long long s){
           int l = 0;
           int r = 0;
       
           vector<int > ans;
       
           bool isfound = 0;
           int sum = arr[0];
       
           if(s == 0){
              ans.push_back(-1);
              return ans;
           }
       
           while(r < n){
                if(sum == s){
                   isfound = 1;
                   break;
                }
                else if(sum < s){
                  r++;
                  if(r < n){
                      sum += arr[r];
                  }
                }
                else{
                   sum -= arr[l];
                   l++;
           }
       }
       
       if(isfound){
           ans.push_back(l+1);
           ans.push_back(r+1);
           
           return ans;
       }
       ans.push_back(-1);
       return ans;
    }   
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends