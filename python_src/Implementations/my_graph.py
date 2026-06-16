#Graph implementation

class Graph():
	def __init__(self):
		self.nodes = 0
		self.adj_list = {}
		
	def addVertex(self, node):
		self.nodes += 1
		self.adj_list[node] = []
		return self.adj_list
			
	def addEdge(self, node1, node2):
		self.adj_list[node1].append(node2)
		self.adj_list[node2].append(node1)
		return self.adj_list
	
	def showConnections(self):
		all_nodes = self.adj_list.keys()
		for node in all_nodes:
			node_connections = self.adj_list[node]
			connections = ''
			for vertex in node_connections:
				connections += vertex + ' '
			print(f'{node} --> {connections}')
			
myGraph = Graph()
myGraph.addVertex("0")
myGraph.addVertex("1")
myGraph.addVertex("2")
myGraph.addVertex("3")
myGraph.addVertex("4")
myGraph.addVertex("5")
myGraph.addVertex("6")
myGraph.addEdge("3", "1")
myGraph.addEdge("3", "4")
myGraph.addEdge("4", "2")
myGraph.addEdge("4", "5")
myGraph.addEdge("1", "2")
myGraph.addEdge("1", "0")
myGraph.addEdge("0", "2")
myGraph.addEdge("6", "5")

myGraph.showConnections()
