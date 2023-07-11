class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        L = []
        ans=-1
        for i in range(len(nums)):
            if nums[i] == target:
                L.append(i)
                break
        
        if len(L)==0:
            L.append(-1)
        
        for i in range(len(nums)):
            if nums[i] == target:
                ans = i
                
        L.append(ans)   
        return L