import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_excel('D:/软件/火狐/python实验/data/student_canteen.xlsx', 'Sheet1')

plt.rcParams['font.sans-serif'] = ['simhei']
plt.rcParams['axes.unicode_minus'] = False

fig = plt.figure()
ax = fig.add_subplot(111)
ax.hist(df['price'], bins=7)
plt.title('学生食堂数据')
plt.xlabel('price')
plt.ylabel('cardID')
plt.show()

var = df.groupby('price').price.sum()
fig = plt.figure()
ax1 = fig.add_subplot(111)
ax1.set_xlabel('price')
ax1.set_ylabel('cardID')
ax1.set_title('学生食堂数据')
var.plot(kind='bar')
plt.show()
