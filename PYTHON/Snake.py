
wn = turtle.Screen() 

wn.title("Snake Game") 

wn.bgcolor("blue") 

  
# the width and height can be put as user's choice 

wn.setup(width=600, height=600) 

wn.tracer(0) 

  

  
# head of the snake 

head = turtle.Turtle() 

head.shape("square") 

head.color("white") 
head.penup() 

head.goto(0, 0) 

head.direction = "Stop"

  

  
# food in the game 

food = turtle.Turtle() 

colors = random.choice(['red', 'green', 'black']) 

shapes = random.choice(['square', 'triangle', 'circle']) 

food.speed(0) 
food.shape(shapes) 
food.color(colors) 
food.penup() 

food.goto(0, 100) 

  

  

pen = turtle.Turtle() 

pen.speed(0) 
