//lINK = https://leetcode.com/problems/replace-non-coprime-numbers-in-array/submissions/992350021/

class Solution{
    private:
        bool isCoprime(int x, int y)	// O(logM)  where M is max(x, y)
        {
            return gcd(x, y) == 1;		
        }
        int gcd(int x, int y)			// O(logM)  where M is max(x, y)
        {
            return __gcd(x, y);		
        }
        int lcm(int x, int y)			// O(logM)  where M is max(x, y)
        {
            long long LCM = x;
            LCM *= y;
            LCM /= gcd(x, y);
            return LCM;
        }
    public:
        vector<int> replaceNonCoprimes(vector<int> &nums)
        {

            vector<int> ans;
            int n = nums.size();
            ans.push_back(nums[0]);
            for (int i = 1; i < n; i++)
            {
                int curr = nums[i];
                while (ans.size() && !isCoprime(ans.back(), curr))
                {
                    int top = ans.back();
                    ans.pop_back();
                    curr = lcm(curr, top);
                }
                ans.push_back(curr);
            }
            return ans;
        }
};