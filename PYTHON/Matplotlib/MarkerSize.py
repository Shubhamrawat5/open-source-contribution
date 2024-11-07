import matplotlib.pyplot as plt
import numpy as np

#you cna use the keyword argument markersize or the shorter version, ms to set the size of the markers

yaxis=np.array([7,2,5,1,9])
plt.plot(yaxis,marker='o',ms=20)  # basiclly what it does is that ot just increase or decreases the size of the end points
plt.show()


#marker color
# you can use the keyword argument markeredgecolor or the shorter mec to set the color of the edge of the markers

#set the edge color to red
plt.plot(yaxis,marker='o',ms=20,mec='r')
plt.show() 


#you can use the keyword argument markerfacecolor or the shorter mfc to set the color inside the edge of the markers:

#set the face color to red

plt.plot(yaxis,marker='o',ms=20,mfc='r')
plt.show()

#Use both the mec and mfc arguments to color the entire marker:
#Example : Set the color of both the edge and the face to red:
plt.plot(yaxis, marker = 'o', ms = 20, mec = 'r', mfc = 'r')
plt.show()

#You can also use Hexadecimal color values:
#Example Mark each point with a beautiful green color:
plt.plot(yaxis, marker = 'o', ms = 20, mec = '#4CAF50', mfc = '#4CAF50')
