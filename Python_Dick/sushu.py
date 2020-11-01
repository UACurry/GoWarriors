import random

list = []
x = []

for m in range(1,101):
    n = random.randint(0,500)
    list.append(n)
print(list)

for i in list:
    for j in range(2,i):
        if i%j == 0:
            break
    else:
        x.append(i)

print("其中是素数的有")
for k in range(len(x)):
    print(x[k],end=" ")
    if (k+1) % 8 == 0:
        print("\n")
