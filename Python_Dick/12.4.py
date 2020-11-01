import matplotlib.pyplot as plt
import pandas as pd
import numpy as np



df=pd.read_excel(r"D:/软件/火狐/python实验/data/carts.xlsx")
df2=pd.read_excel(r"D:/软件/火狐/python实验/data/depart.xlsx")
newcarts="newcarts.xlsx"
averagecarts="avergood.xlsx"
plt.rcParams["font.sans-serif"]=["SimHei"]
plt.rcParams["axes.unicode_minus"]=False
group=df.groupby([u"部门"])["数量"].sum().to_frame()
df3=pd.merge(group["数量"],df2["部门"],on="部门",how="inner")
df3.to_excel(newcarts)
df4=pd.read_excel(r"newcarts.xlsx")
df4=pd.merge(df4,df2,on="部门",how="inner")
df4["average"]=df4["数量"]/df4["人数"]
x=np.array(list(df4["部门"]))
y=np.array(list(df4["average"]))
df4.to_excel(averagecarts)
plt.xticks(fontproperties="SimHei",fontsize=11,rotation=-60)
plt.ylabel(u"平均数量",fontproperties="SimHei")
plt.title("办公用品申请数量的时间分布",fontproperties="SimHei")
plt.bar(x,y,align="center")
for a,b in zip(x,y):
    plt.text(a,b+0.05,"%.0f" %b,ha="center",va="bottom",fontsize=7)
plt.show()
