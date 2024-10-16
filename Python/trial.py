def isEqual(s, t) -> int:
    n, m = len(s), len(t)
    if n < m :
        return -1
    if n == m and s != t:
        return -1
    elif s == t:
        return 0
    k = 0
    count = 0
    for i in t:
        x = s.find(i, k)
        if x == -1:
            return -1
        elif x != k:
            count +=1
            k = x+1
        else:
            k += 1
                
    return count


def main() -> None:
    test = int(input())
    for i in range(test):
        n, m = list(map(int, input().split()))
        s = input()
        t = input()
        print(isEqual(s, t))

if __name__ == "__main__":
    main()