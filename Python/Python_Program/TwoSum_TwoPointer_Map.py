from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numPairs = [(num, index) for index, num in enumerate(nums)]
        numPairs.sort(key=lambda x: x[0])

        left = 0
        right = len(numPairs) - 1
        ans = []

        while left <= right:
            if numPairs[left][0] + numPairs[right][0] == target:
                ans.append(numPairs[left][1])
                ans.append(numPairs[right][1])
                break
            elif numPairs[left][0] + numPairs[right][0] > target:
                right -= 1
            else:
                left += 1

        return ans


        # using map
        # numIndices = {}
        # for i, num in enumerate(nums):
        #     complement = target - num
        #     if complement in numIndices:
        #         return [numIndices[complement], i]
        #     numIndices[num] = i
        # return []           