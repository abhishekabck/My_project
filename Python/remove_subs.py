class Solution:
    def minLength(self, s: str) -> int:
        i = 0
        while i<len(s):
            if s[i:i+2] in ("AB", "CD"):
                s = s[:i] + s[i+2:]
            elif s[i-1:i+1] in ("AB", "CD"):
                s = s[:i-1] + s[i+1:]
            else:
                new_string += s[i]
                i+=1
        return len(s)

print(Solution().minLength(s = "ABFCACDB"))