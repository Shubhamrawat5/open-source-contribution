import matplotlib.pyplot as plt
import numpy as np

#you can use the keyword argument marker to emphasize each point with a specified marker:
yaxis=np.array([3,7,1,6])
plt.plot(yaxis,marker='o')
plt.show()
plt.plot(yaxis,marker='*')
plt.show()
'''
Marker	Description
'o'	Circle	
'*'	Star	
'.'	Point	
','	Pixel	
'x'	X	
'X'	X (filled)	
'+'	Plus	
'P'	Plus (filled)	
's'	Square	
'D'	Diamond	
'd'	Diamond (thin)	
'p'	Pentagon	
'H'	Hexagon	
'h'	Hexagon	
'v'	Triangle Down	
'^'	Triangle Up	
'<'	Triangle Left	
'>'	Triangle Right	
'1'	Tri Down	
'2'	Tri Up	
'3'	Tri Left	
'4'	Tri Right	
'|'	Vline	
'_'	Hline
'''