def factorical(n):
    if n == 1:
        return 1 
    else:
        return n *factorical(n-1)
number = int(input("输入"))
result = factorical(number)
print(result)