class Solution:
    def decodeString(self, s: str) -> str:
        stack1, stack2 = [""], [""]
        i, n = 0, len(s)
        while i < n:
            if s[i].isalpha():
                stack2[-1] += s[i]
            elif s[i].isdigit():
                if i > 0 and not s[i-1].isdigit():
                    stack1.append("")
                stack1[-1] += s[i]
            elif s[i] == "[":
                stack2.append("")
            else:
                string = stack2.pop()
                stack2[-1] += string*int(stack1.pop())
                if not stack1:
                    stack1.append("")
            i += 1
        return stack2[-1]