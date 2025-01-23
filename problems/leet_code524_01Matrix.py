# Input Matrix
mat = [
    [0, 0, 0],
    [0, 1, 0],
    [0, 0, 0]
]
visited = [
    [False, False, False],
    [False, False, False],
    [False, False, False]
]

def find_nearest_distance(mat, i, j):
    ud = up_distance_of(mat, i, j)
    dd = down_distance_of(mat, i, j)
    ld = left_distance_of(mat, i, j)
    rd = right_distance_of(mat, i, j)
    