intCount = 0
strCount = 0
ontherCount = 0

n = input("请输入")
for i in n:
    if i.isdigit():
        intCount += 1
    elif i.isalpha():
        strCount += 1
    else:
        ontherCount += 1

print("数字个数",intCount,"字符个数",strCount,"其他个数",ontherCount)