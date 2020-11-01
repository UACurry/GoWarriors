import tkinter
import random
import tkinter.messagebox

game = tkinter.Tk()
game.geometry('400x200')
game.title('欢迎来到猜数字小游戏')
answer = random.randint(1, 1024)

num = 0

label1 = tkinter.Label(game, text="游戏规则：系统随机生成数字，范围为1-1024")
label1.grid(columnspan=2, rowspan=2)

label2 = tkinter.Label(game, text='请输入你猜测的数字:')
label2.grid(row=2, column=0, sticky='w')

text = tkinter.Entry(game, width=20)
text.grid(row=2, column=1, sticky='w')


def guess():
    guess_number = text.get()
    global num
    if guess_number == '':
        tkinter.messagebox.showerror("警告", "Oh!输入不能为空")

    else:
        guess_number = int(float(guess_number))
        if guess_number > answer:
            tkinter.messagebox.showinfo("错误", "Oh~你猜的数字太大啦")
            num += 1
        if guess_number < answer:
            tkinter.messagebox.showinfo("错误", "Oh~你猜的数字太小啦")
            num += 1
        if guess_number == answer:
            tkinter.messagebox.showinfo("正确", "Oh~恭喜你，猜对啦!")
            num += 1
            numGuess()


def numGuess():
    if num == 1:
        tkinter.messagebox.showinfo('结果正确', '我靠！一次答对！')
    elif num < 10:
        tkinter.messagebox.showinfo('结果正确', '十次以内就答对了牛逼\t尝试次数：' + str(num))
    elif num < 50:
        tkinter.messagebox.showinfo('无奈', '还行哦\t尝试次数：' + str(num))
    else:
        tkinter.messagebox.showinfo('好吧。。。。。您都试了超过50次了。。。。尝试次数：' + str(num))


button2 = tkinter.Button(game,
                         text='确定',
                         command=guess,
                         width=10,
                         bg='RoyalBlue',
                         font=('微软雅黑', 10))
button2.grid(row=2, column=2, sticky='s', padx=8, pady=8)

game.mainloop()