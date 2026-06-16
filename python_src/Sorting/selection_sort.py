#Implementing a selection sort

def selection_sort(numbers):

    for i in range(len(numbers)-1): 
    
        for j in range(i+1, len(numbers)):

            if numbers[j] < numbers[i]:

                numbers[i], numbers[j] =  numbers[j], numbers[i]
    
    return numbers

print(selection_sort([2,9,3,6,7,3,2,4,4]))
        