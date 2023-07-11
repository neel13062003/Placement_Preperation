class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        p = permutations(nums)
        L = []
        for i in p:
            L.append(list(i))
        return L     