def main():
    t = int(input())
    for case in range(t):
        n = int(input())
        score = 0
        count_odd, count_even = 0, 0
        nums = list(map(int, input().split()))
        for x in range(n):
            num = nums[x]
            if num & 1 == 1:
                count_odd += 1
            else:
                count_even += 1
        if count_even >= 1:
            score += 1
        if count_odd > 0 and count_even:
            score += count_odd
        if count_even == 0 and count_odd > 0:
            score += count_odd - 1
        print(score)

if __name__ == "__main__":
    main()
    