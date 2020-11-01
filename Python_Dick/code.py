import random
checkcode=" "#用来存放验证码
for i in range(4):      
    index=random.randrange(0,2)     
    if index == 1:
        checkcode+=chr(random.randrange(65,91))         
    else:
        checkcode+=str(random.randrange(0,10))     
print("验证码:",checkcode)