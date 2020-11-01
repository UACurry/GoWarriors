import math


def hanoi(n,x,y,z):
    if n == 1:
        print(x,'-->',z)
    else:
        hanoi(n-1,x,z,y)#将前n-1个盘子从x到y
        print(x,'-->',z)#将最底下的最后一个盘子从X到Z
        hanoi(n-1,y,x,z)#将y-1个盘子到z上

n = int(input("请输入层数"))

print(hanoi(n,"x","y","z"))