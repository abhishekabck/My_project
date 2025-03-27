def is_palindrome(x: int) -> bool:
    x = str(x)
    return x == x[::-1]

def previous_palindrome(x: int):
    x -= 1
    while not is_palindrome(x):
        x -= 1
    return x

def next_palindrome(x: int):
    x += 1
    while not is_palindrome(x):
        x += 1
    return x

def function1(innum: int):
    num1 = previous_palindrome(innum)
    num2 = previous_palindrome(innum)
    result = num1 + num2
    while not is_palindrome(result):
        num1 = previous_palindrome(num1)
        if is_palindrome(num1 + num2):
            break
        num2 = next_palindrome(num2)
    return num1+num2

print(function1(67))