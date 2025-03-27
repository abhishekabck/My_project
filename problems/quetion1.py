ipt = "in@#fytq&!"
lst = list(ipt)
i, j  = 0, len(ipt) - 1

while i < j:
    if lst[i].isalnum() and lst[j].isalnum():
        lst[i], lst[j] = lst[j], lst[i]
        print(lst)
        i, j = i+1, j-1
    elif not lst[i].isalnum():
        i += 1
    else:
        j -= 1
print("".join(lst))