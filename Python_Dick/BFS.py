graph = {
    "A": ["B", "C"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D", "E"],
    "D": ["B", "C", "E", "F"],
    "E": ["C", "D"],
    "F": ["D"]
}


def BFS(graph, start):
    queue = []  #python 数组可以动态增删，所以用列表来代表队列
    queue.append(start)
    seen = set()  #看下已经访问过的
    seen.add(start)

    #寻找最短路径
    #创建一个映射表，来表示一个点的前面那个结点
    partent = {start: None}
    #拿到的vertex ，有很多w， w的前一个点就是vertex

    while (len(queue) > 0):
        #当队列长度不等于0时候，拿一个点出来
        vertex = queue.pop(0)
        nodes = graph[vertex]  #邻接点
        for w in nodes:
            if w not in seen:
                queue.append(w)
                seen.add(w)
                #这一步是添加映射
                partent[w] = vertex
        print(vertex)
    return partent


BFS(graph, "A")
print("---------------")
#寻找最短路径
parent = BFS(graph, "E")
print("输出映射表")
for key in parent:
    print(key, parent[key])

print("------------------")
#从B出发到起点
v = "B"
while v != None:
    print(v)
    v = parent[v]