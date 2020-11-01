import time

#这里表示装饰器
#用来计算一段函数的运行时间
def display_time(fun):
    def wrapper(*args):#*args代表有多少个参数带多少个参数
        t1 = time.time()
        result = fun(*args)
        t2 = time.time()
        print(t2 - t1)
        return result
    return wrapper

#调用的时候
@display_time