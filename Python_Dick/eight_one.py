import time
class Student: 
    def __inti__(self,sno,sname,sbirth):
        self.sname = sname
	    self.sno = sno
	    self.sbirth = sbirth

	def age(self):
        a = self.birth.split('.')
	    b = gmtime()
	    y = int(a[0])
	    by = b[0] - y
        print("岁数为：%s岁"%(by))
	
	
	def showStduent(self):
        print('学号：',self.sno,'姓名：',self.sname,'出生日期:',self.sbirth)

student1 = Student(01,'李明','2000.06.08')
print(student1.showStudent())
print(student1.age())
