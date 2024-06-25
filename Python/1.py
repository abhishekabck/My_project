class Solution:
    def myAtoi(self, s: str) -> int:
        number = 0
        lead = 1
        st = ""
        for i in s:
            if i == " " and lead == 1:
                pass
            elif i in "-+" and lead == 1:
                st += i
                lead = 0
            elif i in "0123456789":
                st += i
                lead = 0
            else :
                break
        try :
            number = int(st)
        except :
            number = 0
        if (number > 0) and (number>=2147483647):
            number = 2147483647
        elif (number < 0) and (number < -2147483648):
            number = -2147483648
        return number
er = Solution()
print(er.myAtoi("-5-"))