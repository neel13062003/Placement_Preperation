//link = https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-111/problems
// Find Longest String

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
static bool cmp(string&s1,string&s2){
    if(s1.size()!=s2.size()) return s1.size()>s2.size();
    return s1<s2;
}
    string longestString(vector<string> &words)
    {
        // code here
        int k=INT_MIN;
        string ans="";
        vector<string>v;
        unordered_map<string,int>mpp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mpp[words[i]]++;
           
        }
        sort(words.begin(),words.end(),cmp);
        int i=0,t=1;
        while(i<n){
            string st=words[i];
            string s;
            for(int j=0;j<st.size();j++){
                s+=st[j];
                if(mpp.find(s)==mpp.end()){
                    t=0;
                    break;
                }
                
            }
            
            if(t==1){
               return st;
            }
            i++;
        }
        
       return "";
    }
};

// class Solution
// {
// public:
//     static bool cmp(pair<int,string>&a,pair<int,string>&b){
//         return a.first>b.first || (a.first==b.first && a.second<b.second);
//         // return a.first>b.first;
//     }
    

//     bool isSolve(string &str,vector<string> &words,unordered_map<string ,int>&mp1){
//         unordered_map<string ,int>mp;
//         int i=0;
//         string temp = ""; 
//         temp += str[0];
//         mp[temp]++;
//         for(int i=1;i<str.size();i++){
//             temp += str[i];
//             mp[temp]++;   
//         }    
        
//         // cout<< " "<<endl;
//         // for(auto it:mp){
//         //     cout<<it.first<<endl;
//         // }
//         // cout<< " "<<endl;
        
        
        
//         // cout<< " "<<endl;
//         // for(auto it:mp1){
//         //     cout<<it.first<<endl;
//         // }
//         // cout<< " "<<endl;
        
        
//         for(auto it:mp){
//             if(mp1.find(it.first) == mp.end()){
//                 return false;
//             }
//         }
//         return true;
//     }

//     string longestString(vector<string> &words)
//     {
//         vector<pair<int,string>>vec;
//         for(int i=0;i<words.size();i++){
//             int n = words[i].size();
//             vec.push_back({n,words[i]});
//         }
//         sort(vec.begin(),vec.end(),cmp);
        
//         // cout<<" "<<endl;
//         // for(int i=0;i<vec.size();i++){
//         //     cout<<vec[i].second << " ";
//         // }
//         // cout<<" "<<endl;
        
//         unordered_map<string ,int>mp1;
//         for(int i=0;i<words.size();i++){
//             mp1[words[i]]++;
//         }
        
//         int final_ans=INT_MIN;
//         int maxi = INT_MIN;
//         string final_str = "";
//         vector<string>vec123;
//         int p=0;
//         for(int i=0;i<vec.size();i++){
//             string str = vec[i].second;
//             if(isSolve(str,words,mp1)){
//                 int x = str.size();
//                 maxi = max(final_ans,x);
//                 if(maxi > final_ans){
//                     final_str = str;
//                     vec123.push_back(final_str);
//                     final_ans = maxi;
//                 }
//                 p=1;
//             }
//         }
//         if(p==1){
//             sort(vec123.begin(),vec123.end());
//             int s = vec123.size();
//             string red = vec123[0];
//             return red;
//         }
//         else return "";
//     }
// };


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
static bool cmp(string&s1,string&s2){
    if(s1.size()!=s2.size()) return s1.size()>s2.size();
    return s1<s2;
}
    string longestString(vector<string> &words)
    {
        // code here
        int k=INT_MIN;
        string ans="";
        vector<string>v;
        unordered_map<string,int>mpp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mpp[words[i]]++;
           
        }
        sort(words.begin(),words.end(),cmp);
        int i=0,t=1;
        while(i<n){
            string st=words[i];
            string s;
            for(int j=0;j<st.size();j++){
                s+=st[j];
                if(mpp.find(s)==mpp.end()){
                    t=0;
                    break;
                }
                
            }
            
            if(t==1){
               return st;
            }
            i++;
        }
        
       return "";
    }
};

// class Solution
// {
// public:
//     static bool cmp(pair<int,string>&a,pair<int,string>&b){
//         return a.first>b.first || (a.first==b.first && a.second<b.second);
//         // return a.first>b.first;
//     }
    

//     bool isSolve(string &str,vector<string> &words,unordered_map<string ,int>&mp1){
//         unordered_map<string ,int>mp;
//         int i=0;
//         string temp = ""; 
//         temp += str[0];
//         mp[temp]++;
//         for(int i=1;i<str.size();i++){
//             temp += str[i];
//             mp[temp]++;   
//         }    
        
//         // cout<< " "<<endl;
//         // for(auto it:mp){
//         //     cout<<it.first<<endl;
//         // }
//         // cout<< " "<<endl;
        
        
        
//         // cout<< " "<<endl;
//         // for(auto it:mp1){
//         //     cout<<it.first<<endl;
//         // }
//         // cout<< " "<<endl;
        
        
//         for(auto it:mp){
//             if(mp1.find(it.first) == mp.end()){
//                 return false;
//             }
//         }
//         return true;
//     }

//     string longestString(vector<string> &words)
//     {
//         vector<pair<int,string>>vec;
//         for(int i=0;i<words.size();i++){
//             int n = words[i].size();
//             vec.push_back({n,words[i]});
//         }
//         sort(vec.begin(),vec.end(),cmp);
        
//         // cout<<" "<<endl;
//         // for(int i=0;i<vec.size();i++){
//         //     cout<<vec[i].second << " ";
//         // }
//         // cout<<" "<<endl;
        
//         unordered_map<string ,int>mp1;
//         for(int i=0;i<words.size();i++){
//             mp1[words[i]]++;
//         }
        
//         int final_ans=INT_MIN;
//         int maxi = INT_MIN;
//         string final_str = "";
//         vector<string>vec123;
//         int p=0;
//         for(int i=0;i<vec.size();i++){
//             string str = vec[i].second;
//             if(isSolve(str,words,mp1)){
//                 int x = str.size();
//                 maxi = max(final_ans,x);
//                 if(maxi > final_ans){
//                     final_str = str;
//                     vec123.push_back(final_str);
//                     final_ans = maxi;
//                 }
//                 p=1;
//             }
//         }
//         if(p==1){
//             sort(vec123.begin(),vec123.end());
//             int s = vec123.size();
//             string red = vec123[0];
//             return red;
//         }
//         else return "";
//     }
// };


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends