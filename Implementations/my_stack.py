from my_array import Array

class Node():
    def __init__(self, value):
        self.value = value
        self.next = None
        
class StackLL():
    def __init__(self):
        self.top = None
        self.bottom = None
        self.length = 0
        
    def peek(self):
        return self.top
        
    def push(self, value):
        new = Node(value)
        if self.length == 0:
            self.top, self.bottom = new, new
        else:
            new.next = self.top
            self.top = new
        self.length += 1
        return self
        
    def pop(self):
        if self.top != None:
            self.top = self.top.next
            stack.length -= 1
        return self


class StackA():
    def __init__(self):
        self.data = Array()  
        self.length = 0  

    def peek(self):
        if self.length == 0:
            return None 
        return self.data.get(self.length - 1) 

    def push(self, value):
        self.data.append(value)  
        self.length += 1
        return self

    def pop(self):
        if self.length > 0:
            self.data.pop() 
            self.length -= 1
        return self

            
stack = StackA()
stack.push(5)
stack.push(15)
stack.pop()
for i in range(5):
	stack.push(i**2//2)
print(stack.peek())
print(vars(stack.data))
