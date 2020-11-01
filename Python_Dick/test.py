import collections
re = "12345678"


def RX(rectangle):
    result = ''
    for c in rectangle:
        result = c + result
    return result


c = RX(re)
print(c)
queue = collections.deque #创建队列
queue.append()
queue.popleft