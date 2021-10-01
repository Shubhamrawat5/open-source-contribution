o=["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
n=["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred"]

def form(lst,o,n):
    stemp=""
    if lst[0] == '0':
        if lst[1] == '0':
            pass
        else:
            stemp = "-" + o[int(lst[1]) - 1]+stemp

    elif lst[0] == '1':
        if lst[1] == '0':
            stemp = "-" + o[-1] + stemp
        else:
            stemp = "-" + o[int(lst[1]) + 9] + stemp
    else:
        if lst[1] != '0':
            stemp = "-" + n[int(lst[0]) - 2] + stemp
            stemp = stemp + "-" + o[int(lst[1]) - 1]

        else:
            stemp = "-" + n[int(lst[0]) - 2] + stemp
    return stemp
a=int(input())
a=str(a)
s=""
if len(a)<2:
    a="0"+a
lst=a[-2:]
if lst[0]=='0':
    if lst[1]=='0':
        pass
    else:
        s+="-"+o[int(lst[1])-1]
else:
    if len(a)>2 and lst[0]!='1':
        s="-and"+form(lst,o,n)+s
    else:

        s=form(lst,o,n)+s


if len(a)>2:
       lst1=a[-3]
       if lst1!='0':
           s="-"+o[int(lst1)-1]+"-hundred"+s

for i in range(-4,-len(a)-1,-2):
     if i==-4:
         if  i==-len(a):
            lst=['0',a[-4]]
            s=form(lst,o,n)+"-thousand"+s
         else:
             lst=[a[-5],a[-4]]
             s = form(lst, o, n) + "-thousand" + s
     elif i==-6:
         if  i==-len(a):
            lst=['0',a[-6]]
            s=form(lst,o,n)+"-lakh"+s
         else:
             lst=[a[-7],a[-6]]
             s = form(lst, o, n) + "-lakh" + s
     elif i==-8:
         if  i==-len(a):
            lst=['0',a[-8]]
            s=form(lst,o,n)+"-crore"+s
         else:
             lst=[a[-9],a[-8]]
             s = form(lst, o, n) + "-crore" + s



print(s[1:])




