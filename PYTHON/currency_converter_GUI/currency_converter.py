import pandas as pd
data = [["USD",1,1],["AUD",1.44,0.735727],["BRL",4.63,0.216159],["IDR", 13952, 0.000072],["INR",71.35,0.014014],["MXN",18.92,0.052864],["NOK",8.83,0.113208],["RUB",62.12,0.16097],["TRY",5.96,0.167833]]
df=pd.DataFrame(data,columns=("Currency_Code", "USD_to_Currency", "Currency_to_USD")) 

from tkinter import *
import time
curr = Tk()
curr.geometry("1200x700")
curr. title('Currency_Converter')

ca=StringVar()
def convert():
    for i in range(0,9):
        if(fr.get()==df.Currency_Code[i]):
            for j in range(0,9):
                if(to.get()==df.Currency_Code[j]):
                    b=((int(c.get())*df.Currency_to_USD[i]*df.USD_to_Currency[j]))
    cam.configure(text="Converted Amount : "+str(b)+str(to.get()), font = ('Arial',18,''))
    
def reset():
    c.set(0)
    fr.set("Select")
    to.set("Select")
    cam.configure(text = 'Converted Amount : --', font = ('Arial',18,''))

am = Label(curr, text = 'Amount : ', font = ('Arial',18,''))
am.place(x=450,y=100)
c=StringVar()
hourEntry= Entry(curr, width=10, font=("Arial",18,""), textvariable=c) 
hourEntry.place(x=570,y=100) 
am = Label(curr, text = 'From : ', font = ('Arial',18,''))
am.place(x=450,y=200)
fr=StringVar()
fr.set("Select")
option1 = OptionMenu(curr, fr, *df["Currency_Code"])
option1.place(x=540,y=200)
am = Label(curr, text = 'To : ', font = ('Arial',18,''))
am.place(x=650,y=200)
to=StringVar()
to.set("Select")
option2 = OptionMenu(curr, to, *df["Currency_Code"])
option2.place(x=710,y=200)
cobtn = Button(curr, text='Convert', width=20, height= 3, command=convert)
cobtn.place(x=440,y=300)
rsbtn = Button(curr, text='Reset', width=20, height= 3, command=reset)
rsbtn.place(x=620,y=300)
cam = Label(curr, text = 'Converted Amount : ----', font = ('Arial',18,''))
cam.place(x=450,y=400)

mainloop()