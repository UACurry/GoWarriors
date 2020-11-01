import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt

canteen_persons = "D:/软件/火狐/python实验/data/canteen_persons.xlsx"

data = pd.read_excel(canteen_persons,index_col=u'time')
data.plot()
plt.show()