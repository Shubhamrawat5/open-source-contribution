import matplotlib.pyplot as plt
import numpy as np

#Create labels  for a plot 
'''
with pyplot you can use the xlabel() and ylabel() function to set a label for the x-axis and y-axis
'''
x = np.array([80, 85, 90, 95, 100, 105, 110, 115, 120, 125])
y = np.array([240, 250, 260, 270, 280, 290, 300, 310, 320, 330])
plt.plot(x, y)
plt.xlabel("Average Pulse")
plt.ylabel("Calorie Burned")
plt.show()

#create a title for a plot
'''
with pyplot you can use the title() function to set a title for the plot
'''
x = np.array([80, 85, 90, 95, 100, 105, 110, 115, 120, 125])
y = np.array([240, 250, 260, 270, 280, 290, 300, 310, 320, 330])
plt.plot(x, y)
plt.title("Sudarshan's Data")
plt.xlabel("Average Pulse")
plt.ylabel("Calorie Burned")
plt.show()

#set font properties for title and labels
'''
You can use the fontdict parameter in xlabel(), ylabel(), and title() to set font properties for the title and labels.
'''
x = np.array([80, 85, 90, 95, 100, 105, 110, 115, 120, 125])
y = np.array([240, 250, 260, 270, 280, 290, 300, 310, 320, 330])
font1={'family':'serif','color':'blue','size':20}
font2={'family':'serif','color':'darkred','size':15}
plt.title("Sudarshan's Data",fontdict=font1)
plt.xlabel("Average Pulse",fontdict=font2)
plt.ylabel("Calorie Burned",fontdict=font2)
plt.plot(x,y)
plt.show()

#Position the title 
'''
you can use the loc parameter in title() to position the tile
legal value are : 'left','right' and 'center'. Default value is 'center'
'''
x = np.array([80, 85, 90, 95, 100, 105, 110, 115, 120, 125])
y = np.array([240, 250, 260, 270, 280, 290, 300, 310, 320, 330])
plt.title("Sudarshan's Data", loc = 'left')
plt.xlabel("Average Pulse")
plt.ylabel("Calorie Burned")
plt.plot(x, y)
plt.show()
