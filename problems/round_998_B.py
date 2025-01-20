
def solve(n, m, matrix):
    if n == 1:
        print(1)
        return
    result = dict()
    for x in range(n):
        result[matrix[x][0]] = x + 1
    
    for x in range(n):
        for y in range(1, m):
            if matrix[x][y] != matrix[x][y-1] + n:
                print("-1")
                return
    for x in range(n-1):
        print(result[x], end=" ")
    print(result[n-1])

def main():
    t = int(input())
    for i in range(t):
        matrix = []
        n, m = map(int, input().split())
        for x in range(n):
            array = list(map(int, input().split()))
            array.sort()
            matrix.append(array)
        solve(n, m, matrix)
        

if __name__ == "__main__":
    main()