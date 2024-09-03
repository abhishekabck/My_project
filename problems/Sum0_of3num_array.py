# write a program using backtracking to print the pairs of Three numbers of which sum is zero
result = set()
nums = []
for i in range(len(nums)):
    for j in range(i+1, len(nums)):
        for k in range(j + 1, len(nums)):
            if (nums[i] + nums[j] + nums[k]) == 0:
                result.add([nums[i], nums[j], nums[k]])

