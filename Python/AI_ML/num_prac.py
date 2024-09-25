import numpy as np

def mean(arr):
    mean = 0
    for i in arr:
        mean += i
    return mean/len(arr)

def main():
    x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14])
    y = np.array([100, 300, 350, 500, 750, 850, 900, 950, 1250, 1350, 1400, 1550, 1600, 1650, 1700])
    print(y*x)
main()