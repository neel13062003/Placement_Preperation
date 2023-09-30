#include "Solution.h"
#include <vector>

Solution::Solution()
{
}

std::vector<std::vector<int>> Solution::subsets(std::vector<int>& nums)
{
    std::vector<std::vector<int>> ans;
    ans.push_back({});

    int n = nums.size();
    int subset = 1 << n;

    for (int i = 1; i < subset; i++)
    {
        std::vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                temp.push_back(nums[j]);
        }
        ans.push_back(temp);
    }

    return ans;
}

Solution::~Solution()
{
}
