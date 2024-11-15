import matplotlib.pyplot as plt
import numpy as np

#draw line in diagram from position (0,0) to (6,250):

xaxis=np.array([0,6])
yaxis=np.array([0,250])

plt.plot(xaxis, yaxis)
plt.show()