#Implementing a hash table
from my_array import Array


class Hash():
    def __init__(self, size):
        self.data = Array()
        self.length = size
        for i in range(self.length):
            self.data.push(None)
        
    def _hash(self, key):
        hash_value = 0
        for i in range(len(key)):
            hash_value = (hash_value + ord(key[i]) * i) % self.length
        return hash_value
    
    def set(self, key, val): #O(1)
        index = self._hash(key)
        
        if self.data.get(index) is None:
            self.data.data[index] = Array()
        
        bucket = self.data.get(index)
        bucket.push([key, val])
        
    
    def get(self, key): #O(1) if no collisions
        index = self._hash(key)
        bucket = self.data.get(index)
        
        if bucket != None:
            for i in range(bucket.length): #O(n) with collisions
                if bucket.get(i)[0] == key:
                    return bucket.get(i)[1]

        return None
    
    def get_all(self): #O(n)
        for i in range(self.length): ###
            bucket = self.data.get(i)
            if bucket != None: 
                print(f'Index{i}: {bucket.data}')
                
    def keys(self): #O(n)
        keysArray = []
        for i in range(self.data.length): ###
            if self.data.get(i):
                keysArray.append(self.data.get(i).get(0)[0])
        return keysArray

myHash = Hash(1000000)
print(myHash._hash('MaNasaaa'))
