class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = str(x)
        b = ''.join(reversed(a))   #b = a[::-1]
        # if a == b :
        #     return true
        # else :
        #     return false
        return a == b