def solve(test_cases):
    for case in test_cases:
        a1, a2, a4, a5 = case
        max_result = 1
        possible_a3_values = [a1 + a2, a5 - a4]
        
        for a3 in possible_a3_values:
            count = 0
            if a3 == a1 + a2:
                count += 1
            if a4 == a2 + a3:
                count += 1
            if a5 == a3 + a4:
                count += 1
            max_result = max(max_result, count)
        print(max_result)

def main():
    t = int(input())
    array= list()
    for x in range(t):
        array.append(tuple(map(int, input().split())))
    solve(array)

if __name__ == "__main__":
    main()
