import tkinter as tk
import tkinter.messagebox
import random 
import re

game = tk.Tk()                        
game.geometry('400x200')
game.title('欢迎来到猜数字小游戏')
answer = random.randint(1, 1024)

label1 = tk.Label(game,text="游戏规则：系统随机生成")
label1.grid(row=0,padx=20, pady=8,columnspan=2,rowspan=2)

label2 = tk.Label(game, text='请输入你猜测的数字:',bg='LightSeaGreen',font = ('微软雅黑',10))
label2.grid(row=2,column=0,sticky='w',padx=5)

text = tk.Entry(game, width=20)
text.grid(row=2,column=1,sticky='w')


def guess():                           #定义一个函数，在鼠标触发确定按钮时实现该函数
    guess_number = text.get()         #通过get函数获取文本框中的内容
    if guess_number =='' :
        tk.messagebox.showerror("警告", "Oh!输入不能为空")
    else:
        if not re.findall('[0-9]+',str(guess_number)):
            tk.messagebox.showerror("警告", "Oh!只能输入数字")
        else:
                guess_number = int(float(guess_number))
                if guess_number > answer:
                    tkinter.messagebox.showinfo("错误", "Oh~你猜的数字太大啦")
                if guess_number < answer:
                    tkinter.messagebox.showinfo("错误", "Oh~你猜的数字太小啦")
                if guess_number == answer:
                    tkinter.messagebox.showinfo("正确", "Oh~恭喜你，猜对啦!")

button2 = tkinter.Button(game, text='确定', command=hit,width=10,bg='RoyalBlue',font = ('微软雅黑',10))
button2.grid(row=2,column=2,sticky='s',padx=8, pady=8)

game.mainloop()