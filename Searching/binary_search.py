#Binary search

def binary_search(arr, key):
	high = len(arr) - 1
	low = 0
	while True:
		mid = (high + low)//2
		if key > arr[mid]:
			low = mid
		elif key < arr[mid]:
			high = mid
		else:
			return mid
		
		if high == low or low == high-1:
			return False
			
print(binary_search([1,2,3,4,6], 5))
