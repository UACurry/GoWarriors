#面向对象  

#class eg:座位  与   object eg:具体的座位号

class BankAccount:
    #构造器
    def __init__(self,accountNumber,accountName,balance):
        
        #成员变量
        self.accountNumber = accountNumber
        self.accountName   = accountName
        self.balance       = balance
    
    #存钱
    def deposit(self,amount):
        self.balance = self.balance + amount

    #取钱
    def withdraw(self,amount):
        self.balance = self.balance - amount

    #修改内置方法
    def __str__(self):
        return "({},{})".format(self.accountName,self.balance)

    #一个账号和另外一个账号做比较 lt 小于的意思
    def __lt__(self,other):
        return self.balance < other.balance

    #大于
    def __gt__(self,other):
        return self.balance > other.balance