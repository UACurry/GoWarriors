p = int(input("请输入整数"))
sum = 0

while (p != 0):
    sum +=  (p%10)
    p = p//10

print(sum)

