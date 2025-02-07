class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        i, j = 0, len(s2) - 1
        count = 0
        while i < j:
            if s1[i] == s2[i]:
                i += 1
            if s1[j] == s2[j]:
                j -= 1
            
            if s1[i] != s2[i] and s1[j] != s2[j]:
                if s1[i] == s2[j] and s1[j] == s2[i]:
                    count += 1
                    i += 1
                    j -= 1
                else:
                    return False
                
        return count <= 1

print(Solution().areAlmostEqual("bank", "kanb"))