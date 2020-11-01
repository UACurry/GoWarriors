nums = input("请输入一个整数")
num = [ int(n) for n in nums if n.isdigit()]
print(sum(set(num)))

