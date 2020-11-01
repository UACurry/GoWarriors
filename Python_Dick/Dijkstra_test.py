#BFS算最短路径的升级版，加了权值后
import heapq

#优先队列
PriorityQueue = []
heapq.heappush(PriorityQueue, (5, "A"))
heapq.heappush(PriorityQueue, (7, 'B'))
heapq.heappush(PriorityQueue, (3, 'C'))
heapq.heappush(PriorityQueue, (6, 'D'))

a = heapq.heappop(PriorityQueue)
b = a[0]
print(b)