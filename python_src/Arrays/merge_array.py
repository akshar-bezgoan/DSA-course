def merge(arr1, arr2):
    arr = []
    while len(arr) != len(arr1) + len(arr2) and arr1 and arr2:
        if arr1[0] > arr2[0]:
            arr.append(arr2[0])
            del arr2[0]
        else:
            arr.append(arr1[0])
            del arr1[0]
        print(arr)
    return arr
print(merge([3,4,8,9],[2,4,7,8,9]))