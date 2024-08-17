class Solution:
    def romanToInt(self, s: str) -> int:
        table = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000}
        result = 0
        sign = 1
        for i in range(len(s)):
            if i < (len(s)-1) and table[s[i]] < table[s[i+1]]:
                sign = -1
            result += table[s[i]]*sign
            sign = 1
        return result
print(Solution().romanToInt("MCMXCIV"))
