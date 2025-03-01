#Implementing a Binary Search Tree
#remove() function is a python translation of Andrei's JavaScript function
#remove() function is not my work
import json


class Node():
	def __init__(self, value):
		self.value = value
		self.left = None
		self.right = None
		self.frequency = 0
		
class BST():
	def __init__(self):
		self.root = None
	
	def insert(self, value):
		new = Node(value)
		if self.root == None:
			self.root = new
		
		else:
			found = False
			current = self.root
			while found == False:
				if value > current.value:
					if current.right != None:
						current = current.right	
					else:
						current.right = new
						current.right.frequency += 1
						found = True
										
				elif value < current.value:
					if current.left != None:
						current = current.left	
					else:
						current.left = new
						current.left.frequency += 1
						found = True
				
				else:
					pass
					current.frequency += 1
					
		return self
		
	def lookup(self, value):
		if self.root == None:
			return None
		
		else:
			found = False
			current = self.root
			while found == False:
				if value > current.value:
					if current.right != None:
						current = current.right	
					else:
						return None
										
				elif value < current.value:
					if current.left != None:
						current = current.left	
					else:
						return None
				
				else:
					return current
					
	def remove(self, value):
		if self.root is None:
		    return False

		current_node = self.root
		parent_node = None

		while current_node:
		    if value < current_node.value:
		        parent_node = current_node
		        current_node = current_node.left
		    elif value > current_node.value:
		        parent_node = current_node
		        current_node = current_node.right
		    else:
		        # We have a match, get to work!

		        # Option 1: No right child
		        if current_node.right is None:
		            if parent_node is None:
		                self.root = current_node.left
		            else:
		                if current_node.value < parent_node.value:
		                    parent_node.left = current_node.left
		                elif current_node.value > parent_node.value:
		                    parent_node.right = current_node.left

		        # Option 2: Right child which doesn't have a left child
		        elif current_node.right.left is None:
		            current_node.right.left = current_node.left
		            if parent_node is None:
		                self.root = current_node.right
		            else:
		                if current_node.value < parent_node.value:
		                    parent_node.left = current_node.right
		                elif current_node.value > parent_node.value:
		                    parent_node.right = current_node.right

		        # Option 3: Right child that has a left child
		        else:
		            # Find the right child's leftmost child
		            leftmost = current_node.right.left
		            leftmost_parent = current_node.right
		            while leftmost.left is not None:
		                leftmost_parent = leftmost
		                leftmost = leftmost.left

		            # Parent's left subtree is now leftmost's right subtree
		            leftmost_parent.left = leftmost.right
		            leftmost.left = current_node.left
		            leftmost.right = current_node.right

		            if parent_node is None:
		                self.root = leftmost
		            else:
		                if current_node.value < parent_node.value:
		                    parent_node.left = leftmost
		                elif current_node.value > parent_node.value:
		                    parent_node.right = leftmost

		        return True

		return False
			
def traverse(node):
    if node is None:
        return None
    tree = {"value": node.value}
    tree["left"] = traverse(node.left)
    tree["right"] = traverse(node.right)
    return tree

tree = BST()
tree.insert(9)
tree.insert(4)
tree.insert(6)
tree.insert(20)
tree.insert(170)
tree.insert(15)
tree.insert(1)
tree.remove(170)
tree_json = json.dumps(traverse(tree.root), indent=2)
print(tree_json)
	
