class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        ans=-1
        for i in range(len(nums)):
            if nums[i] == target:
                ans = i
                break
            elif nums[i]>target:
                ans = i
                break
        if ans == -1:
            ans = len(nums)
        return ans