import random
sum = 0
i = 1

while i <= 5:
    x = random.uniform(0,1)
    sum += x
    i +=1

average = sum/5
print("%.12f"%average)
print("%14.5f"%average)
print("{:14.3%}".format(average))