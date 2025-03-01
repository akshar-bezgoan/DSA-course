#Our first singly linked list DS
from my_array import Array
"""
myLinkedList = {
	head: {
		value: 10,
		next: {
			value: 5,
			next: {
				value: 16,
				next: None
			}			
		}
	}
}
"""
class Node():
	def __init__(self, value):
		self.value = value
		self.next = None

class LinkedList():
	def __init__(self, value):
		newNode = Node(value)
		self.head = newNode
		self.tail = self.head
		self.length = 1
    
	def append(self, value): # O(1)
		newNode = Node(value)
		self.tail.next = newNode
		self.tail = newNode
		self.length += 1
		return self
    
	def prepend(self, value): # O(1)
		newNode = Node(value)
		newNode.next = self.head
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
		self.length += 1
		return self.get_all()
		
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
		
	
	
	def traverse(self, index):
		#TODO: check parameters
		
		counter = 0
		current = self.head
		
		while counter != index:
			current = current.next
			counter += 1
		
		return current

	

	def reverse(self):
		if self.length == 1:
			return self
		
		newLinked = LinkedList(self.head.value)
		current = self.head
		current = current.next
		for i in range(self.length-1):
			if current.value != None:
				newLinked.prepend(current.value)
				current = current.next
		self = newLinked
		return self		
		

myLinkedList = LinkedList(10)
myLinkedList.append(5) 
myLinkedList.append(16) 
myLinkedList.prepend(1) 
myLinkedList.insert(2,6)
print(myLinkedList.get_all().data)
print(myLinkedList.reverse().get_all().data)


