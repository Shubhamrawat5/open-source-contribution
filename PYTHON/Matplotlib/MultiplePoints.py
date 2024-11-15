import matplotlib.pyplot as plt
import numpy as np

#You can plot as many points as you like, just make sure you have the same number of points in both axis.

#Draw a line in a diagram from position (1, 3) to (2, 8) then to (6, 1) and finally to position (8, 10):

xaxis=([1,2,6,8])
yaxis=([3,8,1,10])
plt.plot(xaxis,yaxis)
plt.show()