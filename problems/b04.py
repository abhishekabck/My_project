from collections import Counter

def solve(t = int(input())):
    for i in range(t):
        n, k = map(int, input().split())
        freq = Counter(list(map(int, input().split())))
        answer = len(freq)
        # if k == 0
        if k == 0:
            print(answer)
            continue
        
        if k >= (n -1):
            print(1)
            continue
        
        # else k > 0 we can remove the number of values here
        pairs = sorted([(i,freq[i],) for i in freq], key=lambda x: x[1])
    
        for pair in pairs:
            if pair[1] <= k:
                answer -= 1
                k -= pair[1]
            if pair[1] > k:
                break
        print(answer)
solve()