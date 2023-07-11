class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.strip()
        s1 = ""

        for i in range(len(s)):
            if s[i].isalpha() and s[i].islower():
                s1 += s[i]
            elif s[i].isalpha() and s[i].isupper():
                s1 += s[i].lower()
        
        s2 = ''.join(reversed(s1))
        return s1 == s2

        # s = ''.join(c.lower() for c in s if c.isalnum())
        # s1 = ''.join(reversed(s))
        # return s == s1
    
    # def isPalindrome(self, s: str) -> None:
    #     s = s.strip()
    #     s1 = ""

    #     for i in range(len(s)):
    #         if s[i].isalpha() and s[i].islower():
    #             s1 += s[i]
    #         elif s[i].isalpha() and s[i].isupper():
    #             s1 += s[i].lower()

    #     s2 = ''.join(reversed(s1))

    #     print()
    #     print(s1)
    #     print()
    #     print(s2)
    #     print()

    #     if s1 == s2:
    #         print("Input is a palindrome")
    #     else:
    #         print("Input is not a palindrome")

# Driver code
solution = Solution()

# Test case 1
input_str = "A man, a plan, a canal: Panama"
print(f"Input: {input_str}")
print(f"Is palindrome? {solution.isPalindrome(input_str)}")
print()

# Test case 2
input_str = "race a car"
print(f"Input: {input_str}")
print(f"Is palindrome? {solution.isPalindrome(input_str)}")
