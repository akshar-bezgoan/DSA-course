#Implementing an array

class Array():
    def __init__(self):
        self.length = 0
        self.data = {}
    
    def get(self, index): #O(1)
        return self.data[index]    
    
    def append(self, item): #O(1)
        self.data[self.length] = item
        self.length += 1
        return self
    
    def pop(self): #O(1)
        lastItem = self.data[self.length-1]
        del self.data[self.length-1]
        self.length -= 1
        return lastItem
    
    def delete(self, index): #O(n)
        item = self.data[index]
        self.shift(index)
        
    def shift(self, index): #O(n)
        for i in range(index, self.length -1):
            self.data[i] = self.data[i+1]
        del self.data[self.length-1]
        self.length -= 1
    


    
