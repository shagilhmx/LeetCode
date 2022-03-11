class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        
        ans = ''
        for el in s:
            ans = el + ' ' + ans
        
        ans = ans.strip()
        return ans
        