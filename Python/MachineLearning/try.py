class Solution:
    def myPow(self, x: float, n: int) -> float:
        if (n == 0):
            return 1
        elif n < 0:
            return x/self.myPow(x, n+1)
        else :
            return x*self.myPow(x, n-1)
print(Solution().myPow(2.00000, -2))