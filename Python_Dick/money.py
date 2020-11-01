print("----欢迎使用用户运费计算器----")

weight = int(input("请输入货物重量"))
distance = int(input("请输入距离"))
p = 20

if distance<250:
    d = 0
elif 250<=distance<500:
    d = 0.02
elif 500<=distance<1000:
    d = 0.05
elif 1000<=distance<2000:
    d = 0.08
elif 2000<=distance<3000:
    d = 0.1
else:
    d = 0.15

f = p*weight*distance*(1-d)    

print("运费价格为:{}".format(f))
    

