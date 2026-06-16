#Implementing an insertion sort

def insertion_sort(arr):
    for i in range(1,len(arr)):
        ins = i
        curr = arr.pop(i)
        for j in range(i-1, -1, -1):
            if arr[j] > curr:
                ins = j
        arr.insert(ins, curr)
    return arr

print(insertion_sort([9,4,7,3,5,3,9,0,0,3]))
        