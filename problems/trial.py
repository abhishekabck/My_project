import pandas as pd

count = 0
sql_symbols = {"'":True, "\"":True, ";":True, "--":True, "/*":True, "*/":True, "xp_":True}

def x(y):
    global count
    for sq in sql_symbols:
        if sq and sq in y:
            count += 1
            sql_symbols[sq] = False
            return True
    return False

def x1(y):
    return y == "10.0.2.5"
# Load the CSV file
file_path = "problems/file1.csv"
data = pd.read_csv(file_path)
df = data[data["Source"].apply(x1) ]
print(df.head())
print(count)