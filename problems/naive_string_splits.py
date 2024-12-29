def solve():
    T = int(input())
    
    results = []
    for _ in range(T):
        n, m = map(int, input().split())
        s = input().strip()
        t = input().strip()

        result = []
        for i in range(1, n):
            x = s[:i]
            y = s[i:]
            combined = x + y

            if len(t) % len(combined) == 0 and t == combined * (len(t) // len(combined)):
                result.append('1')
            else:
                result.append('0')
        results.append(''.join(result))
    
    print("\n".join(results))

solve()
