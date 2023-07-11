 // string result = "";
        //  for (auto it = mp.begin(); it != mp.end(); it++) {
        //      if (it->second.second == 1  && it->second.first == k) {
        //          result = it->first;
        //     }
        // }
        //  return result;

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Solve using Unordeered map
class Solution {
public:
    static bool cmp(pair<string, int>& A, pair<string, int>& B) {
        return A.second < B.second;
    }
    
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, pair<int, int>> mp;
        
        for (int i = 0; i < arr.size(); i++) {
            string word = arr[i];
            
            mp[word].first = i;          // Storing current index
            mp[word].second++;           // Updating frequency
        }
        
        vector<pair<string, int>> index;
        for (auto it : mp) {
            if (it.second.second == 1) {
                index.push_back({it.first, it.second.first});
            }
        }
        
        sort(index.begin(), index.end(), cmp);
        
        int ans = index.size();
        
        if( k > ans) return "";
        // return string(1, index[k - 1].first);    //if char and want to return in string then require typecasting
        return index[k-1].first;
    }
};


Solve Using Map
//Map order sequence 
class Solution {
public:
    //Time Complexity = nlog(n)+nlog(n)
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;         //nlog(n) if unorder then o(n) both can take here
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        int count=0;
        for(auto it:arr){
            if(mp[it] == 1){
                count++;
                if(count==k) return it;
            }
        }
        return "";
    }
};
