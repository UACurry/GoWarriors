import pandas as pd
import matplotlib.pyplot as plt



catering_sale = 'D:/软件/火狐/python实验/data/catering_sale.xls' 
data =  pd.read_excel(catering_sale, index_col = u'日期') 
print(data.describe())



catering_sale = 'D:/软件/火狐/python实验/data/catering_sale.xls' 
data = pd.read_excel(catering_sale, index_col = u'日期')
plt.rcParams['font.sans-serif'] = ['simhei'] 
plt.rcParams['axes.unicode_minus'] = False 

plt.figure()  
p = data.boxplot(return_type='dict') 
x = p['fliers'][0].get_xdata()
y = p['fliers'][0].get_ydata()
y.sort() 


for i in range(len(x)):
    if i > 0:
        plt.annotate(y[i], xy = (x[i], y[i]), xytext=(x[i] + 0.05 -0.8/(y[i] - y[i - 1]), y[i]))
    else:
        plt.annotate(y[i], xy = (x[i], y[i]), xytext=(x[i] + 0.08, y[i]))
plt.show()  




catering_sale = 'D:/软件/火狐/python实验/data/catering_sale.xls' 
data = pd.read_excel(catering_sale, index_col = u'日期')

data = data[(data[u'销量'] > 400)&(data[u'销量'] < 5000)] #过滤异常数据
statistics = data.describe() 

statistics.loc['range'] = statistics.loc['max']-statistics.loc['min'] 
statistics.loc['var'] = statistics.loc['std']/statistics.loc['mean'] 
statistics.loc['dis'] = statistics.loc['75%']-statistics.loc['25%']

print(statistics)
