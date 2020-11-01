import random
import tkinter as tk

def get_pocker(n):
    #a = random.randint(0,51)
    #b = random.randint(0,51)
    #temp = a[0]
    #a[0] = b[0]
    #b[0] = temp
    random.shuffle(n)
    return n

def getColor(n):
    if(n >= 0 and n<=12):
        return '梅花'
    elif (n>= 13 and n <= 25):
        return '方块'
    elif (n >=26 and n <= 38):
        return '红桃'
    elif (n >= 39 and n <= 51):
        return '黑桃'

def getValue(n):
    if n == 0 or n == 13 or n == 26 or n==39:
        return 'A'
    elif n == 12 or n == 38 or n == 25 or n==51:
        return 'K'
    elif n == 11 or n == 36 or n == 23 or n==49:
        return 'Q'
    elif n == 10 or n == 36 or n == 23 or n==49:
        return 'J'
    else:
        return n%13
List = []
List1 = []
List2 = []
List3 = []
List4 = []

def getPai():
    global List
    for i in range(0,52):
        List.append(i)
    List = get_pocker(List)
    for i in range(0,52):
        if i<13:
            List1.append(getColor(List[i])+'-'+str(getValue(List[i])))
        elif i<26:
            List2.append(getColor(List[i])+'-'+str(getValue(List[i])))
        elif i<39:
            List3.append(getColor(List[i])+'-'+str(getValue(List[i])))
        else:
            List4.append(getColor(List[i])+'-'+str(getValue(List[i])))
    print(List)
    print("1号",List1)
    print("2号",List2)
    print("3号",List3)
    print("4号",List4)

getPai()


win = tk.Tk()
win.title("发牌程序")
win.geometry('1000x1000')

canvas = tk.Canvas(win,width=1000, height=1000)
canvas.pack()

f = 0
x = 0
y = 0
loadv = 0
loadc = 0
lv = '23456789'
img1 = list(range(0,13))
img2 = list(range(0,13))
img3 = list(range(0,13))
img4 = list(range(0,13))
def showplayer(List0,img,x,y,f):
    for i in range(0,13):
        v = str(List0[i])
        v = v.split('-')
        if v[0] == '黑桃':
            loadc = 1
        elif v[0] == '红桃':
            loadc = 2
        elif v[0] == '梅花':
            loadc = 3
        elif v[0] == '方块':
            loadc = 4
        if v[1] == 'A':
            loadv = 1
        elif v[1] == 'J':
            loadv = 11
        elif v[1] == 'Q':
            loadv = 12
        elif v[1] == 'K':
            loadv = 13
        elif v[1] == '10':
            loadv = 10
        else:
            for j in lv:
                if v[1] in j:
                    loadv = v[1]
        img[i] = tk.PhotoImage(file = 'D:/软件/火狐/python实验/puke-images/'+str(loadc)+'-'+str(loadv)+'.gif')
        if f == 1:
            canvas.create_image(x+15*i,y,image = img[i])
        else:
            canvas.create_image(x,y+18*i,image = img[i])

showplayer(List1,img1,300,100,1)
showplayer(List2,img2,100,200,-1)
showplayer(List3,img3,300,600,1)
showplayer(List4,img4,700,200,-1)
win.mainloop()

