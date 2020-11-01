print("------欢迎使用BMI计算程序--------")

name = input("请输入您的姓名")
high = input("请输入您的身高(m)")
weight = input("请输入您的体重(kg)")
man = input("请输入您的性别(F/M)")

BMI = float(float(weight)/(float(high)**2))

if BMI < 18.5:
    trouble = "偏瘦"
elif 18.5 <= BMI < 23.9:
    trouble = "正常"
elif 24 <= BMI < 27:
    trouble = "过重"
elif 28 <= BMI < 32:
    trouble = "肥胖"
else:
    trouble = "非常肥胖"
print("姓名:%s 身体状态:%s"%(name,trouble))

