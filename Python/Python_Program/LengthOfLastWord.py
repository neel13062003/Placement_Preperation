# class Solution:
#     def lengthOfLastWord(self, s: str) -> int:
#         s1 = ''.join(reversed(s))
#         count = 0
#         p = False
        
#         for i in range(len(s1)):
#             if not s1[i].isspace():
#                 count += 1
#                 p = True
#             elif p:
#                 break
        
#         return count
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()  # Remove leading and trailing whitespace
        if not s:  # Empty string
            return 0
        
        count = 0
        for i in range(len(s) - 1, -1, -1):  # Iterate from the end of the string
            if s[i].isspace():
                break
            count += 1
        
        return count
