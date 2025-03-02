#Basic Linear Search

def linear_search(arr, key):
	for i in range(len(arr)):
		if arr[i] == key:
			return i
	
	return False

print(linear_search([2,4, 'a', True, 0.7], True)) #Linear searches can be operated on unordered lists with different data types inside it

#Best case - O(1)
#Average case - O(n)
#Worse case - O(n)
