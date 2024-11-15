import matplotlib.pyplot as plt
import numpy as np

#plotting x and y points

#the plot() function is used to draw points(markers) in a diagram
#by default the plot function draw a line from point to point 


#draw a line in a diagram fromm position (1,3) to position (8,10)
xaxis=np.array([1,8])
yaxis=np.array([3,10])
plt.plot(xaxis, yaxis)
plt.show()