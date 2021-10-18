import time
from plyer import notification

t = input("Enter title for your notification")
msg = input("Enter message for your notification")
delay = int(input("Enter time after which you want to be reminded!"))

while True:
    notification.notify(
        title = t,
        message = msg,
        timeout = delay

    )
    time.sleep(5)
