# color https://finthon.com/matplotlib-color-list/
#
import matplotlib.pyplot as plt
import numpy as np

data = [1799, 632, 2859]
labels = ['MySQL', 'TiDB', 'UHP-SQL']

plt.title('2 thread insert tps',fontsize='large')
plt.bar(range(len(data)), data, lw=2, tick_label=labels, color=['lightgray', 'lightgray', 'lightgray'])
plt.show()
