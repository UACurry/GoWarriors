graph = {
    "A": ["B", "C"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D", "E"],
    "D": ["B", "C", "E", "F"],
    "E": ["C", "D"],
    "F": ["D"]
}


def DFS(graph, start):
    stack = []  #python 数组可以动态增删，所以用列表来代表栈
    stack.append(start)
    seen = set()  #看下已经访问过的
    seen.add(start)
    while (len(stack) > 0):
        #现在是一个栈，弹出那么就该弹出最后一个，
        vertex = stack.pop()
        nodes = graph[vertex]  #邻接点
        for w in nodes:
            if w not in seen:
                stack.append(w)
                seen.add(w)
        print(vertex)


DFS(graph, "A")
