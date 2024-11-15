import matplotlib.pyplot as plt
import numpy as np

#the plot only the markers you can use shortcut string notation parameter 'o',which means ring

#draw to pints in the diagram , one at position (1,3) and one in position (8,10)

xaxis=np.array([1,8])
yaxis=np.array([3,10])
plt.plot(xaxis,yaxis,'o')
plt.show()