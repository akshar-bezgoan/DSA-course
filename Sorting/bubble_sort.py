#Implementing bubble sort

def bubble(arr):
    switch = True
    while switch == True:
        switch = False
        for i in range(len(arr)-1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                switch = True
                
    return arr

print(bubble([2,9,3,6,7,3,2,4,4]))