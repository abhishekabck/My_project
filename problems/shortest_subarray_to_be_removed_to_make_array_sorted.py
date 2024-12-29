def kaprekarNumbers(p, q):
    # Write your code here
    results = []
    if p <= 1 and p >= 1:
        results.append(1)
    if p <= 9 and q >= 9:
        results.append(9)
    if p < 45:
        p = 45
    for x in range(p, q+1):
        dx = len(str(x))
        sqr = f"{x*x}" 
        r = int(sqr[:dx])
        l = sqr[dx:]
        if l == "":
            l = 0
        l = int(l)
        if r+l == x:
            results.append(x)
    if len(results) == 0:
        print("INVALID RANGE")
    else:
        print(" ".join(map(str, results)))

kaprekarNumbers(99, 100)