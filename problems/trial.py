import math
def kthFactor(n: int, k: int) -> int:
        s1 = list(filter(lambda x: n%x == 0, range(1, math.floor(math.sqrt(n)) + 1)))
        s2 = []
        if s1[-1]*s1[-1] != n:
            s2.append(n//s1[-1])
        s2 += [n//s1[-x] for x in range(2, len(s1)+1)]
        if k <= len(s1):
            return s1[k-1]
        elif k <= len(s2) + len(s1):
            return s2[k-len(s1)-1]
        return -1

print(kthFactor(2,2))