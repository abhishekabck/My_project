import string

if __name__ == '__main__':
    s = set(input())
    digits = set(string.digits)
    lcase = set(string.ascii_lowercase)
    ucase = set(string.ascii_uppercase)
    result = [False, False, False, False, False]
    result[-1] = ucase.isdisjoint(s)
    result[-2] = lcase.isdisjoint(s)
    result[-3] = digits.isdisjoint(s)
    result[-4] = result[-1] or result[-2]
    result[-5] = result[-1] or result[-2] or result[-3]
    for x in result:
        print(x)