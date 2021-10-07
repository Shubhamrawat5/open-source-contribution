from tkinter import *
import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup

url = 'https://www.mohfw.gov.in/'
html= urllib.request.urlopen(url).read()
soup=BeautifulSoup(html,'html.parser')

lst = list()
tags= soup('strong')
for tag in tags:
	x=tag.get('class', None) 
	if x is not None:
		lst.append(tag.contents[0].strip())
        
val=[]
for i in range(len(lst)):
    if(i%2!=0):
        val.append(str(lst[i]))
 # here end main logic
#------------------------------------------------------------------------------------------------------------------------
 # here begins the GUI Code
root=Tk()
root.title("INDIA COVID TRACKER")
root.configure(background="black")
root.geometry('270x200')
root.resizable(0, 0) 
#main label:
m = Label(root, text="INDIA COVID TRACKER", bg="black", fg= "white")
m.grid(row=0, column=1)


#active, discharged, deaths labels:
act = Label(root, text="\nActive Cases: ", bg="black", fg= "white").grid(row=4, column=0)
a = Label(root, text="\n" +val[0], bg="black", fg= "white").grid(row=4, column=1)


dis = Label(root, text="\nDischarges: ", bg="black", fg= "white").grid(row=5, column=0)
di = Label(root, text="\n"+ val[1], bg="black", fg= "white").grid(row=5, column=1)

dea = Label(root, text="\nDeaths: ", bg="black", fg= "white").grid(row=6, column=0)
de = Label(root, text="\n"+ val[2], bg="black", fg= "white").grid(row=6, column=1)

#close button:
btn = Button(root, text= 'CLOSE', width=8, command = root.destroy, bg="black", fg= "white").grid(row=8, column=1, padx=10, pady=20)


root.mainloop()