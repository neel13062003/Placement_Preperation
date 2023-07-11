from collections import defaultdict

class Solution:
    def longestPalindrome(self, s: str) -> int:
        if len(s) == 1:
            return 1
        
        hasOddFrequency = False
        charCounts = defaultdict(int)
        
        for char in s:
            charCounts[char] += 1
        
        count = 0
        
        for char, freq in charCounts.items():
            if freq % 2 == 0:
                count += freq
            else:
                count += freq - 1
                hasOddFrequency = True
        
        if hasOddFrequency:
            count += 1
        
        return count

