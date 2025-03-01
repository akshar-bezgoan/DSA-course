#My first doubly Linked List implementation

from my_array import Array

class Node():
	def __init__(self, value):
		self.prev = None
		self.value = value
		self.next = None
		

class LinkedList():
	def __init__(self, value):
		newNode = Node(value)
		self.head = newNode
		self.tail = self.head
		self.length = 1
		self.prev = None
		
	def append(self, value): # O(1)
		newNode = Node(value)
		self.tail.next = newNode
		newNode.prev = self.tail
		self.tail = newNode
		self.length += 1
		return self
		
	def prepend(self, value): # O(1)
		newNode = Node(value)
		newNode.next = self.head
		self.head.prev = newNode
		self.head = newNode
		self.length += 1        
		return None  
	
	def get_all(self):
		array = Array()  
		current = self.head
		while current != None:
			array.push(current.value)
			current = current.next
		return array
	
	def insert(self, index, value):
		if index >= self.length:
			return self.append(value)
		
		newNode = Node(value)
		
		leader = self.traverse(index-1)
		holdingPointer = leader.next
		leader.next = newNode
		newNode.next = holdingPointer
		newNode.prev = leader
		self.length += 1
		return self.get_all()
		
	def traverse(self, index):
		#TODO: check parameters
		
		counter = 0
		current = self.head
		
		while counter != index:
			current = current.next
			counter += 1
		
		return current
		
	def remove(self, index):
		if index >= self.length:
			leader = self.traverse(self.length-2)
			leader.next = None
			self.tail = leader
		else:
			leader = self.traverse(index-1)
			follow = self.traverse(index+1)
			leader.next = follow
		self.length -= 1
		return self.get_all().data
	
mLL = LinkedList(5)
mLL.append(10)
mLL.prepend(1)
mLL.insert(2, 6)
mLL.remove(1)
print(vars(mLL.get_all()))
