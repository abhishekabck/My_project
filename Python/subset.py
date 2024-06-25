res = []
nums = [1,2,3]
subset = []

def dfs(i):
    if i >= len(nums):
        res.append(subset.copy())
        return
    # decision to include nums[i]
    subset.append(nums[i])
    dfs(i + 1)
    # decision NOT to include nums[i]
    subset.pop()
    dfs(i + 1)

dfs(0)
print(res)