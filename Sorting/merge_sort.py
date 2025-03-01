def divide(arr):
    return [[i] for i in arr]

def merge(arr1, arr2):
    arr = []
    while arr1 and arr2:
        if arr1[0] > arr2[0]:
            arr.append(arr2.pop(0))
        else:
            arr.append(arr1.pop(0))
    arr.extend(arr1)
    arr.extend(arr2)
    return arr

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

print(merge_sort([5, 4, 2, 6, 7, 9]))
