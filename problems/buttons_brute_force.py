## Let's break down the problem with 1 by 1 writing
"""
Let assume the length of the pass is n
then for first choieces the user will have n choices of keys to press
for (n-1) wrong keys it will lead to all the previous pressed keys to unpressed
but for 1 keys it will lead to next step where user will be entering 2nd position pass
so for n = 4
user will have 4 choices In which 1 of them is valid key while other 3 are invalid but as we have to find worst
possible case thus we will first select all invalid keys as follows:
1. pressing first invalid key
2. pressing second invalid key
3. pressing third invalid key
As all invalid keys have been pressed we will next press valid key
4. pressing fourth valid key
thus up until now total pressed keys are 3(invalid) + 1(valid)
now after pressing 1 valid key we are moved to next step 
"""