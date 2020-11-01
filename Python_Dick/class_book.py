import datetime
class Human:
    def __init__(self,age,name):
        self.age=age
        self.name=name
class Administrator(Human):
    def __init__(self,age,name,sal):
        self.sal=sal
class Student(Human):
    def __init__(self,sno,age,name,brbook,brmonth,brdate):
        self.sno=sno
        self.brbook=brbook
        self.brmonth = brmonth
        self.brdate=brdate
    def brtime(self):
        print(datetime.datetime.now().day-self.brdate+30*(datetime.datetime.now().month-self.brmonth))
st=Student(1817443033,19,'李欣','数据结构(python)',9,30)
st.brtime()