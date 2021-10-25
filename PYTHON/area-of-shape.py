shape=str(input("choose what shape are you looking for [circle/around, triangle, rectangle]:"))

while shape:
    if shape=="circle" or shape=="around":
        r=float(input("type what is the radius of the circle (in cm):"))          
        if r%7==0:
           Area=(22/7)*r**2
        elif r%7!=0:
            Area=3.14*r**2 
        print("So, area of a circle with radius", r, "is","{:2}".format(Area),"cm^2")
        print("DONE")
    elif shape== "triangle":
        h=float(input("type what is the height of the triangle (in cm):"))
        s=float(input("type what is the length of the base of the triangle (in cm):"))
        Area= 1/2*h*s
        print("So, area of a triangle with height",h,"and length",s,"is","{:2}".format(Area),"cm^2")
        print("DONE")
    elif shape=="rectangle":
        l1=float(input("type what is the length of the rectangle (in cm):"))
        l2=float(input("type what is the width of rectangle (in cm):"))
        Area= l1*l2
        print("So, area of a rectangle with length", l1,"and width",l2, "is","{:2}".format(Area), "cm^2")
        print("DONE")
    else:
        print("Error")
        print("type the shape in the list")
    shape=str(input("choose what shape are you looking for [circle/around, triangle, rectangle]:"))
       


    
