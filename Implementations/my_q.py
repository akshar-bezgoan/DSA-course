#Queue implementation

class Node():
    def __init__(self, value):
        self.value = value
        self.next = None
        
class Q():
	def __init__(self):
		self.first = None
		self.last = None
		self.length = 0
		
	def peek(self):
		return self.first
		
	def eq(self, value):
		new = Node(value)
		if self.length == 0:
			self.first = new
			self.last = new
		else:
			self.last.next = new
			self.last = new
			
		self.length += 1
		
		return self
	def dq(self):
		if self.first != self.last:	
			self.first = self.first.next
		else:
			self.last = None
			self.first = None
		self.length -= 1
		 
		return self
		
