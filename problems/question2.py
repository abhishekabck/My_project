def genOTP(string: str, n: int):
    OTP = ""
    for i in range(0, 2*n, 2):
        OTP += str(int(string[i])**2)
    print(OTP)
genOTP("91741749", 4)