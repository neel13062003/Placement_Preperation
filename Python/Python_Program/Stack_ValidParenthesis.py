class Solution:
    def isValid(self, s: str) -> bool:
        stack = [];
        for i in range(len(s)):    
            if s[i]=='(' or s[i]=='{' or s[i]=='[' :
                stack.append(s[i]);
            elif s[i]==')' or s[i]=='}' or s[i]==']':
                if stack:
                    if  (s[i]==')' and stack[-1]=='(') or \
                        (s[i]=='}' and stack[-1]=='{') or  \
                        (s[i]==']' and stack[-1]=='['): 
                        stack.pop()
                    else:
                        return False 
                else:
                    return False
                
        return len(stack)==0