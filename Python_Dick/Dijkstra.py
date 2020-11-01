import heapq
import math
#BFS算最短路径的升级版，加了权值后
graph = {
    "A": {
        "B": 5,
        "C": 1
    },
    "B": {
        "A": 5,
        "C": 2,
        "D": 1
    },
    "C": {
        "A": 1,
        "B": 2,
        "D": 4,
        "E": 8
    },
    "D": {
        "B": 1,
        "C": 4,
        "E": 3,
        "F": 6
    },
    "E": {
        "C": 8,
        "D": 3
    },
    "F": {
        "D": 6
    }
}


#这个函数的作用是吧除了出发点其余的点距离设置为正无穷
def init_distance(graph, start):
    distance = {start: 0}
    for vertex in graph:
        if vertex != start:
            distance[vertex] = math.inf
    return distance


def Dijkstra(graph, start):
    PriorityQueuue = []  #优先队列
    heapq.heappush(PriorityQueuue, {0, start})  #用这个方法来放点和距离进去
    seen = set()  #看下已经访问过的   是一个集合

    #寻找最短路径
    #创建一个映射表，来表示一个点的前面那个结点
    partent = {start: None}
    #拿到的vertex ，有很多w， w的前一个点就是vertex

    distance = init_distance(graph, start)  #初始化距离

    while (len(PriorityQueuue) > 0):
        #当队列长度不等于0时候，拿一个点出来
        #这时候拿到的是一对点，距离和名字
        dist, vertex = heapq.heappop(PriorityQueuue)
        #拿到点的名字
        seen.add(vertex)

        nodes = graph[vertex].keys()  #邻接点
        for w in nodes:
            if w not in seen:
                #先算出距离,如果距离短
                if dist + graph[vertex][w] < distance[w]:  #前面都初始化为无穷大
                    heapq.heappush(PriorityQueuue,
                                   {dist + graph[vertex][w], w})

                    #这一步是添加映射
                    partent[w] = vertex  #改映射
                    distance[w] = dist + graph[vertex][w]  #更新最短那个距离
    return partent, distance


parent, distance = Dijkstra(graph, "A")
print(parent)
print(distance)