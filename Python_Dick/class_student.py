import time
class Student:
    def __inti__(self,sno,sname,sbirth):
	    self.sno = sno
	    self.sname = sname
	    self.sbirth = sbirth	


    def age(self):
        a = self.sbirth.split('.')
        b = gmtime()
        y = int(a[0])
        by = b[0]- y        

	    print("岁数为:%s 岁" %by)

    def showStduent(self):
	    print('学号：',self.sno,'姓名：',self.sname,'出生日期:',self.sbirth)
	

student = Student(01,'李明','2000.06.08')
student.showStudent()
student.age()
