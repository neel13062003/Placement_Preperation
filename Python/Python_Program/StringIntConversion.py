class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s = ""
        for i in range(len(digits)):
            s = s + str(digits[i])
        
        a = int(s)
        a = a+1
        s1 = str(a)
        
        L = []
        for i in range(len(s1)):
            L.append(int(s1[i]))
        return L