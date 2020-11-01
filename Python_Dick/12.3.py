import matplotlib.pyplot as plt
import pandas as pd
import openpyxl
import matplotlib.dates as mdates
import numpy as np



df=pd.read_excel(r"D:/软件/火狐/python实验/data/carts.xlsx")
df2=pd.read_excel(r"D:/软件/火狐/python实验/data/depart.xlsx")
newcarts="newcarts.xlsx"
plt.rcParams["font.sans-serif"]=["SimHei"]
plt.rcParams["axes.unicode_minus"]=False
good=df.groupby([u"日期"])["数量"].sum().to_frame()
print(good.index)
x=np.array(list(good.index))
y=np.array(list(good["数量"]))
plt.ylabel(u"数量",fontproperties="SimHei")
plt.title("各办公用品申请量",fontproperties="SimHei")
plt.gca().xaxis.set_major_formatter(mdates.DateFormatter("%Y-%m-%d"))
plt.plot(x,y)
for a,b in zip(x,y):
    plt.text(a,b+0.05,"%.0f" %b,ha="center",va="bottom",fontsize=7)
plt.show()
