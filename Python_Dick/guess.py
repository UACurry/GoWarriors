import random

n = 1
down = int(input("输入下限数值"))
up = int(input("输入上限数值"))

answer = random.randint(down,up)
temp = int(input("猜一下这系统想的数"))
guess = temp


guess_num = 1
while guess != answer:
    n += 1

    if guess == answer:
        print("哎呀，小机灵鬼")
        print("用%d次就猜对了"%guess_num)
        break
    elif guess < answer:
        print("小了，哥们")
        guess_num +=1
        
    else:
        print("大了，大了")
        guess_num +=1
        

    guess = int(input("哎呀，猜错了，重新输入吧"))

    
print("成功通过")
print("您用%d次通过了"%(n))
