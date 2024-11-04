class Solution:
    def makeFancyString(self, s: str) -> str:
        newString = s[0]
        cnt = 1
        for x in s[1:]:
            if x == newString[-1] and cnt == 2:
                continue
            elif x == newString[-1] and cnt < 2:
                cnt += 1
            else:
                cnt = 1
            newString += x
        return newString

print(Solution().makeFancyString("leeetcode"))