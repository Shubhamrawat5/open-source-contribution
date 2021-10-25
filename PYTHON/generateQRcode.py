
# Import QRCode from pyqrcode
import pyqrcode
import png
from pyqrcode import QRCode

print("WELCOME TO THE QR CODE GENERATION")

# Take input
name  = input("Enter Name : ")
stream = input("Enter Stream : ")
collegename = input("Enter Name of College : ")

# String which represents the QR code
s = "Name : "+ name + "\nStream : " + stream +"\nCollege Name : " + collegename 
  
# Generate QR code
url = pyqrcode.create(s)

# Create and save the png file naming "myqr.png"
url.png('myqr.png', scale = 6)
