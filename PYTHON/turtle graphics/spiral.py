import turtle as t
import time as ti
from itertools import cycle

colors = cycle(['red','orange','yellow','blue','green','purple'])

def draw_circle(size,angle,shift):
    t.pencolor(next(colors))
    t.circle(size)
    t.right(angle)
    t.forward(shift)
    draw_circle(size + 5,angle+1,shift+1)

t.bgcolor('black')
t.speed('fast')
t.pensize(4)

draw_circle(30,0,1)

ti.sleep(3)
t.hideturtle()