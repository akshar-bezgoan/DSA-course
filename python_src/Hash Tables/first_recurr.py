def firstRecurr(arr):
    counts = {}
    for i in arr:
        if i in counts.keys():
            return i
        else:
            counts[i] = 1
    return None
print(firstRecurr([1,2,5,3,4,5]))