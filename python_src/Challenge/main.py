from collections import defaultdict, deque
import time

start = time.perf_counter()

def connections(pairs):
    graph = defaultdict(set)
    for f1, f2 in pairs:
        graph[f1].add(f2)
        graph[f2].add(f1)
    return graph

def check_friends(graph, p1, p2):
    if p2 in graph[p1]:
        return True
    
    visited = {p1}
    q = deque()
    q.append(p1)
    i =0
    while q:
        curr = q.popleft()
        for f in graph[curr]:
            if f == p2:
                return True
            if f not in visited and i<2:
                visited.add(f)
                q.append(f)
        i+=1
    return False


with open('friends.txt', 'r') as f:
    lines = f.readlines()

friend_data = []
for line in lines:
    line = line.strip()
    f1, f2 = map(int, line.split())
    friend_data.append((f1, f2))



graph = connections(friend_data)
p1 = int(input())
p2 = int(input())
print(check_friends(graph, p1, p2))

end = time.perf_counter()
print(end-start)
