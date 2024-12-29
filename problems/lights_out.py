# time Complexity: O(nk) space complexity : O(k)
class Solution1:
    def countGoodSubstrings(self, s: str) -> int:
        # defining a dict for counting frequency
        count = 0
        # iterating for all substring
        for i in range(len(s) - 3 + 1):
            good_sub = {}
            # iterating to calculate frequency 
            for j in range(i, i+3):
                if s[j] in good_sub:
                    good_sub[s[j]] += 1
                else:
                    good_sub[s[j]] = 1
            # condition to check whether the substring is valid or not
            if len(good_sub) == 3:
                count+=1
        return count

# time Complexity: O(n) space complexity : O(k)
class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        if len(s) < 3:
            return 0
        result = 0
        window = dict()
        for i in range(0, 3):
            window[s[i]] = window.get(s[i], 0) + 1
        for i in range(0, len(s) - 3):
            if len(window) == 3:
                result += 1
            window[s[i]] -= 1
            if window[s[i]] == 0:
                del window[s[i]]
            window[s[i+3]] = window.get(s[i+3], 0) + 1
        if len(window) == 3:
            result += 1
        return result
print(Solution().countGoodSubstrings("xyzzaz"))