class Solution:
    def kthCharacter(self, k: int, operations: list[int]) -> str:
        result = "a"
        count = 0
        for i in range(len(operations)):
            if operations[i] == k%2 == 1:
                count += 1
            k //= 2
        return chr(97+count%26)

print(Solution().kthCharacter(10,[0,1,0,1]))