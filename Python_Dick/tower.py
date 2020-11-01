n = int(input("请输入金字塔层数"))
for i in range(1,n+1):
    print((n-i)*" ",end="")
    print((2*i-1)*"*")
 
