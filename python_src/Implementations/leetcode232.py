#Leetcode problem 232: Implementing Queues from Stacks

class MyQueue:
	def __init__(self):
		self.data = []
		self.length = 0

	def push(self, x: int) -> None:
		self.data.append(x)
		self.length += 1
		return self.data
      	
	def pop(self) -> int:
		self.length -= 1
		temp = []
		temp.append(self.data[0])
		del self.data[0]
		return temp[0]	
		
	def peek(self) -> int:
		return self.data[0]

	def empty(self) -> bool:
		if self.length != 0:
			return False
		return True
        
obj = MyQueue()
print(obj.push(1))
print(obj.push(2))
print(obj.push(3))
print(obj.push(4))
print(obj.pop())
print(obj.push(5))
print(obj.pop())
print(obj.pop())
print(obj.pop())
print(obj.pop())
