'''
   2 --- 0
  / \
 /   \
1-----3
'''

#Edge list
graph = [[0,2],[2,3], [2,1], [1,3]] #Shows connections between vertexes

#Adjacent list
graph2 = [[2], [2,3], [0,1,3], [1,2]] #Each index represents a node, and the elements represent its connections

#Adjacent matrix
graph3 = [
	[0,0,1,0],  #graph3[0][2] = 1 so 0 is connected to 2, graph3[0][1] = 0 so 0 is not connected to one
	[0,0,1,1],  # in a weighted graph, 0 =0 but 1 = weight
	[1,1,0,1],
	[0,1,1,0]
]
