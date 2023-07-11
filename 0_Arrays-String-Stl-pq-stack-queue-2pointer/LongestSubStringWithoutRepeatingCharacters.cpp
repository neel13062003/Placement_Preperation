class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int count = 0;
        int start = 0;
    
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
                start = mp[s[i]] + 1;
                count = i - start;
            }
            
            mp[s[i]] = i;
            count++;
            ans = max(ans, count);
        }
        
        return ans;
    }
};
//Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/