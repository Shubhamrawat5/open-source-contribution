#importing module which needs to be installed,it does not come pre installed with python
import pyqrcode

# get user input to create a QR Code.
data = input("Enter the text or link to generate QR code: ")

# creating QR Code
qr = pyqrcode.create(data)

# qr code is not diectly visible,exporting it into a file,keeping scale parameter 8
qr.svg('qr_code.svg', scale = 8)


