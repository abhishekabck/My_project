def solve(n, k, numbers):
    freq = dict()
    count = 0
    for i in range(len(numbers)):
        if freq.get(k - numbers[i], 0) > 0:
            count += 1
            freq[k - numbers[i]] -= 1
        else:
            freq[numbers[i]] = freq.get(numbers[i], 0) + 1
    print(count)

def main():
    t = int(input())
    for x in range(t):
        n, k = map(int, input().split())
        array = list(map(int, input().split()))
        solve(n, k, array)

if __name__ == "__main__":
    main()