class Solution:
    def isFascinating(self, n: int) -> bool:
        a = n * 2
        b = n * 3
        s1 = str(n)
        s2 = str(a)
        s3 = str(b)
        mp = {}
        s = s1 + s2 + s3
        for i in range(len(s)):
            if s[i] in mp:
                return False
            elif s[i]=='0':
                return False
            mp[s[i]] = 1

        return len(mp) == 9
