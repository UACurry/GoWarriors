#伽尔顿板实验
#Galton_Plate.py
#梁安庆2017141461228
'''
支持自定义层数和小球数
自定义层数
支持非法输入检测,非法操作检测
允许运动加速，加速倍速0.1-1.9
允许跳过动画
动画显示
'''
from tkinter import *
from turtle import *
import random
import re
import tkinter.messagebox
import sys
import math
import threading
#窗口创建，布局
my_window = Tk()
my_window.title('Galton Plate')
my_window.geometry('720x900+550+50')
my_window.resizable(width=False,height=False)

#变量定义
v0=StringVar()#层数 输入缓存
v1=StringVar()#小球数 输入缓存
v2=StringVar()#倍速显示
v2.set('快进倍速:1')
v3=StringVar()
v3.set('跳过动画')
ball=0#小球数
nails=0#层数
nails_radius=0#钉子半径
ball_radius=0#小球半径
hig=0#层高
wid=0#钉子半间距
dy=0.1#加速度
vy=0#速度
de=1#角速度
counter=0
times_speed=1#倍速
ov_add_id=0#增加按钮生成小球id
is_end=False#是否跳过动画
cell=18#控件宽度
threads=[]#线程池
#控件创建，布局
canvas = Canvas(my_window,bg='black',width=720,height=900,highlightthickness=0)
Label(my_window,bg='black',fg='white',width=cell,font=16,
      text='输入钉子层数:').grid(row=0,column=0)
e0 = Entry(my_window,textvariable=v0,font=14,width=cell).grid(row=0,column=1)
Label(my_window,bg='black',fg='white',font=16,width=cell,
      text='输入小球数:').grid(row=0,column=3)
e1 = Entry(my_window,textvariable=v1,font=14,width=cell).grid(row=0,column=4)
Label(my_window,bg='black',fg='white',font=16,width=cell,
      textvariable=v2).grid(row=1,column=4)
#tkinter下Canvas绘制动画

canvas.create_text(20,80,font=('微软雅黑',16,),fill='white',text=str(0),tag='conter')
#实验函数
'''
原理：
对槽分别编号0-n,初始化小球值为0，小球遇到钉子向左则值+0，向右则+1
最后小球的值即为它落入的槽
速度公式v=at,v=v0+at
'''
pa = re.compile('\d{1,8}')
#运行主体
def Galton(ball):
    #对每个小球采取Ball()操作
    for i in range(ball):
        ov_id='oval_'+str(i)
        Ball(ov_id)
#小球函数
def Ball(ov):
    global counter
    canvas.delete('conter')
    counter+=1
    canvas.create_text(20,80,font=('微软雅黑',16,),fill='white',text=str(counter),tag='conter')
    temp=0#落入的槽编号
    t=0#暂存随机数
    #轨迹数组
    trail=[0 for i in range(nails)]
    #产生小球运动轨迹
    for i in range(nails-1):
        t=Get_Random()
        temp+=t
        trail[i]=t
    if not is_end:
        canvas.create_oval(nails*wid+100-ball_radius,180-(hig-nails_radius-ball_radius)-ball_radius,
                        nails*wid+100+ball_radius,180-(hig-nails_radius-ball_radius)+ball_radius,fill='red',tag=ov)
        Move(trail,ov,temp)
    else:
        rs[temp]+=1
        RS()
#小球运动的动画显示函数
def Move(trail,oval,slot):
    #global vy
    vy=0#初速度刷新为0
    y=0#垂直方向移动量
    count=0#判断次数
    temp=0#暂存y
    R=nails_radius+ball_radius
    while True:
        if y>=hig*(nails-1)+10+180+2*ball_radius+nails_radius:
            canvas.delete(oval)
            try:
                rs[slot]+=1#落入槽中
            except Exception:
                pass#忽略
            RS()
            break
        temp = y#暂存垂直方向移动量
        #碰到钉子，动画轨迹改变
        if temp/((count+2)*(hig-nails_radius-ball_radius))>=1 and count<nails-1:
            temp = 0
            degree=0#碰撞时已旋转度数
            #初始角速度 tx=R*cos(pi/2-w)  w为初始角速度 tx=R*sin(w) w=arcsin(tx/R) 碰撞时，设定tx=vy
            tw=vy/R
            if tw>1:
                tw=1
            de=math.degrees(math.asin(tw))
            if de<0:de*=-1
            vy=0#碰撞后改变垂直方向速度
            while True:
                #if x>=ball_radius+nails_radius:
                    #break
                if degree>=90:#旋转90度后跳出
                    degree=0
                    break
                canvas.after(int(10*times_speed))
                tx=R*math.cos(math.radians(90-de-degree))-R*math.cos(math.radians(90-degree))#水平方向移动量
                ty=R*math.sin(math.radians(90-degree))-R*math.sin(math.radians(90-de-degree))
                try:
                    #左转
                    if trail[count]==0:
                        canvas.move(oval,tx*(-1),ty)
                    #右转
                    elif trail[count]==1:
                        canvas.move(oval,tx,ty)
                except Exception:
                    pass#忽略掉此处异常
                canvas.update()
                degree+=de#以角速度de进行旋转
                vy=ty#更新下降速度，保证平滑运动
            count+=1
        #碰撞结束,垂直下落
        canvas.after(int(10*times_speed))
        vy+=dy#更新垂直方向速度
        canvas.move(oval,0,vy)
        canvas.update()
        y+=vy#更新垂直方向移动量
def Add_Ball():
    global ov_add_id
    ov_add_id+=1#每生成一个小球id自增,作为线程池编号和绘图编号
    global ball
    ball=1+ball
    v1.set(ball)
    ar='ov_add_id_'+str(ov_add_id)
    threads.append(threading.Thread(target=Ball,args=(ar,)))
    threads[ov_add_id-1].start()
def RS():
    for i in range(nails):
        text_id='text_'+str(i)
        try:
            canvas.delete(text_id)
        except Exception as e:
            print(e)
        finally:
            canvas.create_text(wid*i*2+100+wid,hig*(nails-1)+180+hig+10+ball_radius,font=('微软雅黑',int(ball_radius),),
                                fill='white',text=str(rs[i]),tag=text_id)
def Get_Random():
    random.seed()
    return random.randint(0,1)
#绘制背景
def Draw_Nails():
    global nails_radius,ball_radius,hig,wid
    wid=(500/(nails*2))
    hig=wid*(3**0.5)
    nails_radius = wid/5
    ball_radius = wid-nails_radius
    #绘制钉子
    for i in range(nails):
        for k in range(i+2):
            canvas.create_oval(wid*k*2+(nails-i-1)*wid+100-nails_radius,hig*i+180-nails_radius,
                               wid*k*2+(nails-i-1)*wid+100+nails_radius,hig*i+180+nails_radius,
                               fill='white')
    #绘制槽
    for i in range(nails+1):
        canvas.create_line(wid*i*2+100,hig*(nails-1)+180+10,
                           wid*i*2+100,hig*(nails-1)+180+hig+10,
                           width=2,fill='white')
    for i in range(nails):
        canvas.create_line(wid*i*2+100,hig*(nails-1)+180+hig+10,
                          wid*(i+1)*2+100,hig*(nails-1)+180+hig+10,
                          width=2,fill='white')
def StartGalton():
    global ball,nails,rs,counter
    if Check(v0.get())==None or Check(v1.get())==None or int(v0.get())>100 or int(v0.get())<1:
        tkinter.messagebox.showwarning(title='警告',message='输入非法')
        return 
    canvas.delete(ALL)
    ov_add_id=0
    counter=0
    nails=int(v0.get())
    ball = int(v1.get())
    rs=[0 for k in range(nails)]
    Draw_Nails()
    RS()
    try:
        Galton(ball)
    except Exception:
        pass
def Speed_Down():
    global times_speed
    times_speed+=0.1
    if times_speed>2:
        times_speed=2
    Show_times_speed()
def Speed_UP():
    global times_speed
    times_speed-=0.1
    if times_speed<=0.1:
        times_speed=0.1
    Show_times_speed()
def Show_times_speed():
    v2.set('快进倍速:'+str(round(2-times_speed,1)))
def To_End():
    global is_end
    is_end=not is_end
    if v3.get()=='跳过动画':
        v3.set('播放动画')
    else:
        v3.set('跳过动画')
#合法性检查
def Check(str_inner):
    return pa.match(str_inner)
Button(my_window,text="确定",width=cell,command=StartGalton).grid(row=0,column=2)
Button(my_window,text="+",width=cell,command=Add_Ball).grid(row=1,column=0)
Button(my_window,text='>>',width=cell,command=Speed_UP).grid(row=1,column=3)
Button(my_window,text='<<',width=cell,command=Speed_Down).grid(row=1,column=2)
Button(my_window,textvariable=v3,width=cell,command=To_End).grid(row=1,column=1)
#进入消息循环
canvas.place(x=0,y=0)
my_window.mainloop()
