p = []
i = 2
for i in range(2,100):
    for j in range(2,i):
        if i % j == 0:
            break
    else:
            p.append(i)
print(p)