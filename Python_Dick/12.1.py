import matplotlib.pyplot as plt
import pandas as pd
import openpyxl
import numpy as np


df=pd.read_excel(r"D:/软件/火狐/python实验/data/carts.xlsx")
df2=pd.read_excel(r"D:/软件/火狐/python实验/data/depart.xlsx")
newcarts="newcarts.xlsx"
plt.rcParams["font.sans-serif"]=["SimHei"]
plt.rcParams["axes.unicode_minus"]=False
groupnum=df.groupby([u"部门"])["数量"].sum().to_frame()
df2=pd.merge(groupnum["数量"],df2["部门"],on="部门",how="inner")
df2.to_excel(newcarts)
print(groupnum)
x=np.array(list(df2["部门"]))
y=np.array(list(groupnum["数量"]))
xticks=list(df2.部门)
plt.xticks(fontproperties="SimHei",rotation=60)
plt.ylabel(u"数量",fontproperties="SimHei")
plt.title("各部门办公用品总数量",fontproperties="SimHei")
plt.bar(x,y,width=0.7)
for a,b in zip(x,y):
    plt.text(a,b+0.05,"%.0f" %b,ha="center",va="bottom",fontsize=9)
plt.show()

