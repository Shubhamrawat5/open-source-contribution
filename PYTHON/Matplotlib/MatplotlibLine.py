import matplotlib.pyplot as plt
import numpy as np

#you can use the keyword argument linestyle or shorter ls, to change the style of the plotted line 

yaxis=np.array([5,1,9,4])
plt.plot(yaxis,linestyle='dotted')
plt.show()

plt.plot(yaxis,linestyle='dashed')
plt.show()

#shorter syntax
#the line style can be written in a shorter syntax
'''
linestyle can be written as ls.
dotted can be written as :.
dashed can be written as --.
'''

plt.plot(yaxis,ls=':')
plt.show()

'''
Style	Or
'solid' (default)	'-'	
'dotted'	':'	
'dashed'	'--'	
'dashdot'	'-.'	
'None'	'' or ' '	
'''

#line color
yaxis=np.array([7,2,9,1,5])
plt.plot(yaxis,color='r')
plt.show()

#You can also use Hexadecimal color values:
plt.plot(yaxis,c='#4CAF50')
plt.show()

plt.plot(yaxis, c = 'hotpink')
plt.show()


#line width
'''
You can use the keyword argument linewidth or the shorter lw to change the width of the line.
The value is a floating number, in points:
'''
plt.plot(yaxis, lw = '20.5')
plt.show()


#multiple lines 
'''
you can plt as many lines as you like by simply adding more plt.plot() function
'''

yaxis1=np.array([7,2,9,1,5])
yaxis2=np.array([3,1,9,2,5])
plt.plot(yaxis1)
plt.plot(yaxis2)
plt.show()


'''
You can also plot many lines by adding the points for the x- and y-axis for each line in the same plt.plot() function.

(In the examples above we only specified the points on the y-axis, meaning that the points on the x-axis got the the default values (0, 1, 2, 3).)

The x- and y- values come in pairs:
'''
x1 = np.array([0, 1, 2, 3])
y1 = np.array([3, 8, 1, 10])
x2 = np.array([0, 1, 2, 3])
y2 = np.array([6, 2, 7, 11])
plt.plot(x1, y1, x2, y2)
plt.show()

